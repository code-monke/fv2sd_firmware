/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "bsp/board.h"
#include "tusb.h"

#include "usb_descriptors.h"
#include "buttons.h"

#define PIN_COMMON 29
#define PIN_S0 14
#define PIN_S1 13
#define PIN_S2 10
#define PIN_S3 11
#define PIN_ENABLE_0 12
#define PIN_ENABLE_1 21
#define PIN_ENABLE_2 19
#define PIN_ENABLE_3 20
#define PIN_ENABLE_4 18
#define PIN_ENABLE_5 17

#define NUM_SHIFTREG 6
#define NUM_PINS_PER_SHIFTREG 16

#define THRESHOLD_SENSOR 1986 // 1.6v

#define KEY_ROLLOVER 6
#define L2_REPEATABLES_QUEUE_SIZE 4


void hid_task(void);
uint8_t usb_keyboard_send(void);
uint8_t usb_extra_send(void);
void pulse(struct button* button, uint8_t scancode, uint8_t extra_mods);
void press_redundant(struct button* button, uint8_t scancode, uint8_t extra_mods);


// const uint8_t BUTTONS[6][16] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
const uint8_t PINS_ENABLE[6] = {PIN_ENABLE_0, PIN_ENABLE_1, PIN_ENABLE_2, PIN_ENABLE_3, PIN_ENABLE_4, PIN_ENABLE_5};
const uint8_t PINS_S[4] = {PIN_S0, PIN_S1, PIN_S2, PIN_S3};

uint8_t state;
uint8_t found_active_L2_repeatable = 0;
struct button* button;
uint8_t need_send = 0; 
uint8_t L2_active = 0;
uint8_t L3_active = 0;
uint8_t shiftPlus_active = 0;
struct button* active_L2_repeatables[L2_REPEATABLES_QUEUE_SIZE];
struct button* previous_repeatables[2]; 
struct button* buttons[NUM_SHIFTREG][NUM_PINS_PER_SHIFTREG];

//which modifier keys are currently pressed
//1=left ctrl,    2=left shift,   4=left alt,    8=left gui
//16=right ctrl, 32=right shift, 64=right alt, 128=right gui
uint8_t g_active_mods;
uint8_t keyboard_keys[KEY_ROLLOVER];

const uint16_t extra_keys[] = {
	0x00CD, // play/pause
	0x00E9, // volunme up
	0x00EA, // volume down
};


int main() {

    stdio_init_all();
    board_init();
    tusb_init();

    for(int i=0;i<L2_REPEATABLES_QUEUE_SIZE;i++){active_L2_repeatables[i] = 0;}
    for(int i=0;i<2;i++){previous_repeatables[i] = &BUTTON_SPACE;}

    // gpio_init(PIN_COMMON);
    gpio_init(PIN_ENABLE_0);
    gpio_init(PIN_ENABLE_1);
    gpio_init(PIN_ENABLE_2);
    gpio_init(PIN_ENABLE_3);
    gpio_init(PIN_ENABLE_4);
    gpio_init(PIN_ENABLE_5);
    gpio_init(PIN_S0);
    gpio_init(PIN_S1);
    gpio_init(PIN_S2);
    gpio_init(PIN_S3);
    // gpio_set_dir(PIN_COMMON, GPIO_IN);
    gpio_set_dir(PIN_S0, GPIO_OUT);
    gpio_set_dir(PIN_S1, GPIO_OUT);
    gpio_set_dir(PIN_S2, GPIO_OUT);
    gpio_set_dir(PIN_S3, GPIO_OUT);
    gpio_set_dir(PIN_ENABLE_0, GPIO_OUT);
    gpio_set_dir(PIN_ENABLE_1, GPIO_OUT);
    gpio_set_dir(PIN_ENABLE_2, GPIO_OUT);
    gpio_set_dir(PIN_ENABLE_3, GPIO_OUT);
    gpio_set_dir(PIN_ENABLE_4, GPIO_OUT);
    gpio_set_dir(PIN_ENABLE_5, GPIO_OUT);
    gpio_put(PIN_ENABLE_0, 1);
    gpio_put(PIN_ENABLE_1, 1);
    gpio_put(PIN_ENABLE_2, 1);
    gpio_put(PIN_ENABLE_3, 1);
    gpio_put(PIN_ENABLE_4, 1);
    gpio_put(PIN_ENABLE_5, 1);
    gpio_put(PIN_S0, 0);
    gpio_put(PIN_S1, 0);
    gpio_put(PIN_S2, 0);
    gpio_put(PIN_S3, 0);

    adc_init();
    adc_gpio_init(PIN_COMMON);
    adc_select_input(3);

    int i, j;
	for(i = 0; i < NUM_SHIFTREG; i++){
		for (j = 0; j < NUM_PINS_PER_SHIFTREG; j++){
			buttons[i][j] = 0;
		}
	}

	buttons[0][0] = &BUTTON_ESC;
	buttons[0][1] = &BUTTON_1;
	buttons[0][15] = &BUTTON_2;
	buttons[1][0] = &BUTTON_3;
	buttons[1][15] = &BUTTON_4;
	buttons[2][0] = &BUTTON_5;
	buttons[2][15] = &BUTTON_6;
	buttons[3][0] = &BUTTON_7;
	buttons[3][15] = &BUTTON_8;
	buttons[4][0] = &BUTTON_9;
	buttons[4][15] = &BUTTON_0;
	buttons[5][0] = &BUTTON_MINUS;
	buttons[5][8] = &BUTTON_EQUALS;
	buttons[5][9] = &BUTTON_TILDE;
	
	buttons[0][7] = &BUTTON_TAB;
	buttons[0][9] = &BUTTON_Q;
	buttons[1][7] = &BUTTON_SHIFTPLUS1;
	buttons[1][8] = &BUTTON_W;
	buttons[2][7] = &BUTTON_F;
	buttons[2][8] = &BUTTON_P;
	buttons[3][7] = &BUTTON_G;
	buttons[3][8] = &BUTTON_J;
	buttons[4][7] = &BUTTON_L;
	buttons[4][8] = &BUTTON_U;
	buttons[4][9] = &BUTTON_Y;
	buttons[5][6] = &BUTTON_SEMICOLON;
	buttons[5][7] = &BUTTON_SHIFTPLUS2;
	buttons[5][5] = &BUTTON_BACKSLASH;
	buttons[5][10] = &BUTTON_DUMMY1;
	
	buttons[0][6] = &BUTTON_ENTER;
	buttons[0][10] = &BUTTON_CLOSINGSQUAREBRACKET;
	buttons[0][8] = &BUTTON_A;
	buttons[1][6] = &BUTTON_R;
	buttons[1][5] = &BUTTON_S;
	buttons[1][9] = &BUTTON_T;
	buttons[2][6] = &BUTTON_D;
	buttons[2][9] = &BUTTON_H;
	buttons[3][6] = &BUTTON_N;
	buttons[3][9] = &BUTTON_E;
	buttons[4][6] = &BUTTON_I;
	buttons[4][5] = &BUTTON_O;
	buttons[4][11] = &BUTTON_ENTER_1;
	buttons[5][11] = &BUTTON_DUMMY2;

	buttons[0][5] = &BUTTON_DUMMY3;
	buttons[0][11] = &BUTTON_OPENINGSQUAREBRACKET;
	buttons[1][4] = &BUTTON_APOSTROPHE;
	buttons[2][4] = &BUTTON_Z;
	buttons[1][10] = &BUTTON_X;
	buttons[1][11] = &BUTTON_C;
	buttons[2][5] = &BUTTON_V;
	buttons[2][10] = &BUTTON_B;
	buttons[3][5] = &BUTTON_K;
	buttons[3][10] = &BUTTON_M;
	buttons[3][11] = &BUTTON_COMMA;
	buttons[4][4] = &BUTTON_PERIOD;
	buttons[4][10] = &BUTTON_FORWARDSLASH;
	buttons[5][4] = &BUTTON_DUMMY3;
	buttons[5][12] = &BUTTON_DUMMY4;

	buttons[0][4] = &BUTTON_ALTTAB;
	buttons[0][12] = &BUTTON_DUMMY5;
	buttons[1][3] = &BUTTON_DUMMY6;
	buttons[1][12] = &BUTTON_DUMMY6;
	buttons[2][3] = &BUTTON_L2;
	buttons[2][12] = &BUTTON_REP1;
	buttons[2][11] = &BUTTON_SPACE;
	buttons[3][4] = &BUTTON_SPACE_1;
	buttons[3][3] = &BUTTON_REP2;
	buttons[3][13] = &BUTTON_DUMMY6;
	buttons[4][3] = &BUTTON_DUMMY6;
	buttons[4][12] = &BUTTON_DUMMY6;
	buttons[5][3] = &BUTTON_DUMMY6;
	buttons[5][13] = &BUTTON_DUMMY6;

	buttons[0][2] = &BUTTON_DUMMY6;
	buttons[0][14] = &BUTTON_DUMMY6;
	buttons[0][13] = &BUTTON_DUMMY6;
	buttons[1][1] = &BUTTON_DUMMY6;
	buttons[1][14] = &BUTTON_LGUI;
	buttons[2][1] = &BUTTON_L3;
	buttons[2][13] = &BUTTON_LCTRL;
	buttons[3][1] = &BUTTON_LSHIFT;
	buttons[3][14] = &BUTTON_LALT;
	buttons[4][1] = &BUTTON_DUMMY6;
	buttons[4][14] = &BUTTON_DUMMY6;
	buttons[5][1] = &BUTTON_DUMMY6;
	buttons[5][14] = &BUTTON_DUMMY6;
	buttons[5][15] = &BUTTON_DUMMY6;

    //resets the keys being sent to the computer
	uint8_t x = 0;
	for(x; x < KEY_ROLLOVER; x++)
	{keyboard_keys[x] = 0;}
	g_active_mods = 0;

    while (1)
    {
        tud_task(); // tinyusb device task
        // led_blinking_task(); 

        hid_task();
    }
    

    // while (true) {
    //     // printf("Hello, world!\n");

    //     const float conversion_factor = 3.3f / (1 << 12);

    //     for(int i = 0; i < 6; i++){
    //         gpio_put(PINS_ENABLE[i], 0);
    //         for(int j = 0; j < 16; j++){

    //             if (SWITCHES[i][j]){

    //                 gpio_put(PIN_S0, 0);
    //                 gpio_put(PIN_S1, 0);
    //                 gpio_put(PIN_S2, 0);
    //                 gpio_put(PIN_S3, 0);
    //                 if (j & 8){
    //                     gpio_put(PIN_S3, 1);
    //                 }
    //                 if (j & 4){
    //                     gpio_put(PIN_S2, 1);
    //                 }
    //                 if (j & 2){
    //                     gpio_put(PIN_S1, 1);
    //                 }
    //                 if (j & 1){
    //                     gpio_put(PIN_S0, 1);
    //                 }
    //                 // sleep_us(15); // this is what riskable uses; adds 1.44 ms to full scan
    //                 sleep_us(7); // seems to be enough
    //                 uint16_t result = adc_read();
                    
    //                 // printf("%f ", result * conversion_factor);

    //                 // if (result*conversion_factor > THRESHOLD_SENSOR){
    //                 if (result > THRESHOLD_SENSOR){

    //                     printf("%d %d %d %f \n", i, j, result, result * conversion_factor);
    //                     sleep_ms(1000);
    //                 }

    //             }
    //         }
    //         gpio_put(PINS_ENABLE[i], 1);
    //     }
    //     // printf("\n");
        
    //     // uint16_t result = adc_read();
    //     // printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);

    //     // sleep_ms(1000);
    // }
}

void hid_task(void)
{
// Poll every 10ms
const uint32_t interval_ms = 1;
static uint32_t start_ms = 0;

if ( board_millis() - start_ms < interval_ms) return; // not enough time
// if (board_millis() > 10000 && board_millis() < 11000) usb_keyboard_send(); //test to make sure usb is working; make usb_keyboard_send just send a scancode
start_ms += interval_ms;

// printf("test");  

const float conversion_factor = 3.3f / (1 << 12);

for(int i = 0; i < NUM_SHIFTREG; i++){
    gpio_put(PINS_ENABLE[i], 0);
    for(int j = 0; j < NUM_PINS_PER_SHIFTREG; j++){

        state = 0;

        button = buttons[i][j];

        if(button){

            gpio_put(PIN_S0, 0);
            gpio_put(PIN_S1, 0);
            gpio_put(PIN_S2, 0);
            gpio_put(PIN_S3, 0);
            if (j & 8){
                gpio_put(PIN_S3, 1);
            }
            if (j & 4){
                gpio_put(PIN_S2, 1);
            }
            if (j & 2){
                gpio_put(PIN_S1, 1);
            }
            if (j & 1){
                gpio_put(PIN_S0, 1);
            }
            // sleep_us(15); // this is what riskable uses; adds 1.44 ms to full scan
            sleep_us(7); // seems to be enough
            uint16_t result = adc_read();
            
            // printf("%f ", result * conversion_factor);
            // if (result*conversion_factor > THRESHOLD_SENSOR){
            // if (result > THRESHOLD_SENSOR){
            state = (result > THRESHOLD_SENSOR) ? 1 : 0;
            
            if(button->stuff.pressed && !state){
                
                button->stuff.pressed = 0;
                
                if(button == &BUTTON_L3){
                    L3_active = 0;
                }else if(button == &BUTTON_L2){
                    L2_active = 0;
                }// else if(button == &BUTTON_BEEPER){
                // 	beeper_on = 0;
                // }
                
                g_active_mods &= ~button->stuff.mods;
                
                if(button->stuff.pressed_L2){
                    if(button->stuff.is_L2_repeatable){
                        for(int k=0;k<L2_REPEATABLES_QUEUE_SIZE;k++){
                            if(active_L2_repeatables[k] == button){
                                active_L2_repeatables[k] = 0;
                            }
                        }
                    }
                    g_active_mods &= ~button->stuff.L2_mods;
                    button->stuff.pressed_L2 = 0;
                }
                
                button->current_scancode = 0;
                button->current_extra_key = 0;
                need_send = 1;
                
                //_delay_ms(10);
                
                
            }else if(!button->stuff.pressed && state){
                
                button->stuff.pressed = 1;
                
                // if(beeper_on){
                // 	beep();
                // }
                
                if(L3_active && button->stuff.has_L3){
                    if(button->stuff.is_L3_extra){
                        button->current_extra_key = button->extra_key;
                    }else{
                        button->current_scancode = button->scancodes[2];
                    }
                    need_send = 1;
                }else if(L2_active && button->stuff.has_L2){

                    button->stuff.pressed_L2 = 1; //???

                    if(button->stuff.is_L2Rep){
                        found_active_L2_repeatable = 0;
                        for(int k=0;k<L2_REPEATABLES_QUEUE_SIZE;k++){
                            if(active_L2_repeatables[k]){
                                found_active_L2_repeatable = 1;
                                if(active_L2_repeatables[k]->current_scancode){
                                    active_L2_repeatables[k]->current_scancode = 0;
                                    g_active_mods &= ~button->stuff.L2_mods; 
                                    usb_keyboard_send();
                                }
                                pulse(active_L2_repeatables[k], active_L2_repeatables[k]->scancodes[1], active_L2_repeatables[k]->stuff.L2_mods);
                            }
                        }
                    }
                    if(!button->stuff.is_L2Rep || !found_active_L2_repeatable){
                        if(button->stuff.is_L2_redundant){
                            pulse(button, button->scancodes[1], button->stuff.L2_mods);
                        }else{
                            if(button->stuff.is_L2_extra){
                                button->current_extra_key = button->extra_key;
                            }else{
                                button->current_scancode = button->scancodes[1];
                            }
                            g_active_mods |= (button->stuff.L2_mods && 15);
                            need_send = 1;
                        }
                        if(button->stuff.is_L2_repeatable){
                            for(int k=0;k<L2_REPEATABLES_QUEUE_SIZE;k++){
                                if(!active_L2_repeatables[k]){
                                    active_L2_repeatables[k] = button;
                                    break;
                                }
                            }
                        }
                    }
                }else{
                    if(button->stuff.is_shiftPlus){
                        shiftPlus_active = 1 & ~shiftPlus_active;
                        // set_PINX_output(PIN_LED_SHIFTPLUS, shiftPlus_active);
                    }else if(button == &BUTTON_REP1){
                        if(previous_repeatables[0]->current_scancode){
                            previous_repeatables[0]->current_scancode = 0;
                            usb_keyboard_send();
                        }
                        if(previous_repeatables[0]->stuff.is_affected_by_shiftPlus && shiftPlus_active){
                            pulse(previous_repeatables[0], previous_repeatables[0]->scancodes[0], 2);
                        }else{
                            pulse(previous_repeatables[0], previous_repeatables[0]->scancodes[0], 0);
                        }
                    }else if(button == &BUTTON_REP2){
                        if(previous_repeatables[1]->current_scancode){
                            previous_repeatables[1]->current_scancode = 0;
                            usb_keyboard_send();
                        }
                        if(previous_repeatables[1]->stuff.is_affected_by_shiftPlus && shiftPlus_active){
                            pulse(previous_repeatables[1], previous_repeatables[1]->scancodes[0], 2);
                        }else{
                            pulse(previous_repeatables[1], previous_repeatables[1]->scancodes[0], 0);
                        }
                    // }else if(button == &BUTTON_REP1){
                    // 	pulse(previous_repeatables[0], previous_repeatables[0]->scancodes[0], 0);
                    // }else if(button == &BUTTON_REP2){
                    // 	pulse(previous_repeatables[0], previous_repeatables[0]->scancodes[0], 0);
                    // }else if(button == &BUTTON_BEEPER){
                    // 	beeper_on = 1;
                    }else if(button == &BUTTON_L2){
                        L2_active = 1;
                    }else if(button == &BUTTON_L3){
                        L3_active = 1;
                    // }else if(button == &BUTTON_SPACE_PULSE){
                    // 	if(BUTTON_SPACE.current_scancode){
                    // 		BUTTON_SPACE.current_scancode = 0;
                    // 		usb_keyboard_send();
                    // 	}
                    // 	pulse(&BUTTON_SPACE_PULSE, 44, 0);
                    // }
                    }else if(button->stuff.is_redundant){
                        press_redundant(button, button->scancodes[0], 0);
                    }
                    else{
                        if(button->stuff.is_repeatable){
                            previous_repeatables[1] = previous_repeatables[0];
                            previous_repeatables[0] = button;
                        }
                        if(button->stuff.is_affected_by_shiftPlus && shiftPlus_active){
                            pulse(button, button->scancodes[0], shiftPlus_active?2:0);
                        }else{
                            g_active_mods |= button->stuff.mods;
                            button->current_scancode = button->scancodes[0];
                            need_send = 1;
                        }
                    }
                }
                if(button->stuff.does_kill_shiftPlus){
                    shiftPlus_active = 0;
                    // set_PINX_output(PIN_LED_SHIFTPLUS, 0);
                }
                
                //_delay_ms(10);
            }
        }
    }
    gpio_put(PINS_ENABLE[i], 1);
}

if(need_send == 1){
    usb_keyboard_send();
    usb_extra_send();
    need_send = 0;
}




//   // Remote wakeup
//   if ( tud_suspended() && btn )
//   {
//     // Wake up host if we are in suspend mode
//     // and REMOTE_WAKEUP feature is enabled by host
//     tud_remote_wakeup();
//   }else
//   {
//     // Send the 1st of report chain, the rest will be sent by tud_hid_report_complete_cb()
//     send_hid_report(REPORT_ID_KEYBOARD, btn);
//   }
}

uint8_t usb_keyboard_send(void){
    // printf("usbkbsend %d", g_active_mods);

    // if ( !tud_hid_ready() ) return 0;
    while(!tud_hid_ready()){
        tud_task();
    }

    // test to make sure usb is working
    // uint8_t keycode[6] = { 0 };
    // keycode[0] = HID_KEY_A;
    // tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycode);

    uint8_t c = 0;
    uint8_t keycode[KEY_ROLLOVER] = { 0 };
    struct button* current_button;
    for(int i=0; i<NUM_SHIFTREG; i++){
        for (int j=0; j< NUM_PINS_PER_SHIFTREG; j++){
            current_button = buttons[i][j];
            if(current_button){
                if(current_button->current_scancode){
                    // keycode[0] = HID_KEY_A;
                    // break;
                    keycode[c] = current_button->current_scancode;
                    c++;
                }
            }
            if(c>KEY_ROLLOVER){ break; }
        }
        if(c>KEY_ROLLOVER){ break; }
    }
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, g_active_mods, keycode);
    // sleep_ms(500);
}

uint8_t usb_extra_send(void){
}

void pulse(struct button* button, uint8_t scancode, uint8_t extra_mods){
    uint8_t store_mods = g_active_mods;
	g_active_mods |= (extra_mods & 15);
	button->current_scancode = scancode;
	usb_keyboard_send();
	button->current_scancode = 0;
	usb_keyboard_send();
	g_active_mods = store_mods;
}


void press_redundant(struct button* button, uint8_t scancode, uint8_t extra_mods){
    
	for(int i = 0; i < NUM_SHIFTREG; i++){
        for(int j = 0; j < NUM_PINS_PER_SHIFTREG; j++){
            if(buttons[i][j]->stuff.pressed && buttons[i][j]->current_scancode == scancode){
                // buttons[i]->stuff.pressed = 0;
                buttons[i][j]->current_scancode = 0;
                buttons[i][j]->current_extra_key = 0;
            }
        }
	}

	usb_keyboard_send();
	button->current_scancode = scancode;
	usb_keyboard_send();
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
  // TODO not Implemented
  (void) instance;
  (void) report_id;
  (void) report_type;
  (void) buffer;
  (void) reqlen;

  return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
//   (void) instance;

//   if (report_type == HID_REPORT_TYPE_OUTPUT)
//   {
//     // Set keyboard LED e.g Capslock, Numlock etc...
//     if (report_id == REPORT_ID_KEYBOARD)
//     {
//       // bufsize should be (at least) 1
//       if ( bufsize < 1 ) return;

//       uint8_t const kbd_leds = buffer[0];

//       if (kbd_leds & KEYBOARD_LED_CAPSLOCK)
//       {
//         // Capslock On: disable blink, turn led on
//         blink_interval_ms = 0;
//         board_led_write(true);
//       }else
//       {
//         // Caplocks Off: back to normal blink
//         board_led_write(false);
//         blink_interval_ms = BLINK_MOUNTED;
//       }
//     }
//   }
}

// static void send_hid_report(uint8_t report_id, uint32_t btn)
// {
//   // skip if hid is not ready yet
//   if ( !tud_hid_ready() ) return;

//   switch(report_id)
//   {
//     case REPORT_ID_KEYBOARD:
//     {
//       // use to avoid send multiple consecutive zero report for keyboard
//       static bool has_keyboard_key = false;

//       if ( btn )
//       {
//         uint8_t keycode[6] = { 0 };
//         keycode[0] = HID_KEY_A;

//         tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycode);
//         has_keyboard_key = true;
//       }else
//       {
//         // send empty key report if previously has key pressed
//         if (has_keyboard_key) tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, NULL);
//         has_keyboard_key = false;
//       }
//     }
//     break;

//     case REPORT_ID_MOUSE:
//     {
//       int8_t const delta = 5;

//       // no button, right + down, no scroll, no pan
//       tud_hid_mouse_report(REPORT_ID_MOUSE, 0x00, delta, delta, 0, 0);
//     }
//     break;

//     case REPORT_ID_CONSUMER_CONTROL:
//     {
//       // use to avoid send multiple consecutive zero report
//       static bool has_consumer_key = false;

//       if ( btn )
//       {
//         // volume down
//         uint16_t volume_down = HID_USAGE_CONSUMER_VOLUME_DECREMENT;
//         tud_hid_report(REPORT_ID_CONSUMER_CONTROL, &volume_down, 2);
//         has_consumer_key = true;
//       }else
//       {
//         // send empty key report (release key) if previously has key pressed
//         uint16_t empty_key = 0;
//         if (has_consumer_key) tud_hid_report(REPORT_ID_CONSUMER_CONTROL, &empty_key, 2);
//         has_consumer_key = false;
//       }
//     }
//     break;

//     case REPORT_ID_GAMEPAD:
//     {
//       // use to avoid send multiple consecutive zero report for keyboard
//       static bool has_gamepad_key = false;

//       hid_gamepad_report_t report =
//       {
//         .x   = 0, .y = 0, .z = 0, .rz = 0, .rx = 0, .ry = 0,
//         .hat = 0, .buttons = 0
//       };

//       if ( btn )
//       {
//         report.hat = GAMEPAD_HAT_UP;
//         report.buttons = GAMEPAD_BUTTON_A;
//         tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));

//         has_gamepad_key = true;
//       }else
//       {
//         report.hat = GAMEPAD_HAT_CENTERED;
//         report.buttons = 0;
//         if (has_gamepad_key) tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));
//         has_gamepad_key = false;
//       }
//     }
//     break;

//     default: break;
//   }
// }

// // Invoked when sent REPORT successfully to host
// // Application can use this to send the next report
// // Note: For composite reports, report[0] is report ID
// void tud_hid_report_complete_cb(uint8_t instance, uint8_t const* report, uint16_t len)
// {
//   (void) instance;
//   (void) len;

//   uint8_t next_report_id = report[0] + 1;

//   if (next_report_id < REPORT_ID_COUNT)
//   {
//     send_hid_report(next_report_id, board_button_read());
//   }
// }

// // Invoked when received GET_REPORT control request
// // Application must fill buffer report's content and return its length.
// // Return zero will cause the stack to STALL request
// uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
// {
//   // TODO not Implemented
//   (void) instance;
//   (void) report_id;
//   (void) report_type;
//   (void) buffer;
//   (void) reqlen;

//   return 0;
// }

// // Invoked when received SET_REPORT control request or
// // received data on OUT endpoint ( Report ID = 0, Type = 0 )
// void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
// {
//   (void) instance;

//   if (report_type == HID_REPORT_TYPE_OUTPUT)
//   {
//     // Set keyboard LED e.g Capslock, Numlock etc...
//     if (report_id == REPORT_ID_KEYBOARD)
//     {
//       // bufsize should be (at least) 1
//       if ( bufsize < 1 ) return;

//       uint8_t const kbd_leds = buffer[0];

//       if (kbd_leds & KEYBOARD_LED_CAPSLOCK)
//       {
//         // Capslock On: disable blink, turn led on
//         blink_interval_ms = 0;
//         board_led_write(true);
//       }else
//       {
//         // Caplocks Off: back to normal blink
//         board_led_write(false);
//         blink_interval_ms = BLINK_MOUNTED;
//       }
//     }
//   }
// }