

#include "kbd.h"




/**************************************************************************
*
**************************************************************************/


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

#define THRESHOLD_SENSOR 1986 // 1.6v

#define NUM_SHIFTREG 6
#define NUM_PINS_PER_SHIFTREG 16
const uint8_t SWITCHES[NUM_SHIFTREG][NUM_PINS_PER_SHIFTREG];
//{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
// {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1}, 
// {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, 
// {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, 
// {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1}, 
// {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
const uint8_t PINS_ENABLE[6] = {PIN_ENABLE_0, PIN_ENABLE_1, PIN_ENABLE_2, PIN_ENABLE_3, PIN_ENABLE_4, PIN_ENABLE_5};
const uint8_t PINS_S[4] = {PIN_S0, PIN_S1, PIN_S2, PIN_S3};
struct button* buttons[NUM_SHIFTREG][NUM_PINS_PER_SHIFTREG];

uint8_t init_pins(void){
	
	stdio_init_all();

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
	
	return 1;
}

uint8_t init_promicro(void)
{
	init_pins();

	return 1;
}







/**************************************************************************
*
*     main
*
**************************************************************************/

int main(void){
	
	
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
	buttons[1][8]] = &BUTTON_W;
	buttons[2][7] = &BUTTON_F;
	buttons[2][8] = &BUTTON_P;
	buttons[3][7] = &BUTTON_G;
	buttons[3][8] = &BUTTON_J;
	buttons[4][7] = &BUTTON_L;
	buttons[4][8] = &BUTTON_U;
	buttons[4][9] = &BUTTON_Y;
	buttons[5][6]] = &BUTTON_SEMICOLON;
	buttons[5][7] = &BUTTON_SHIFTPLUS2;
	buttons[5][5] = &BUTTON_BACKSLASH;
	buttons[5][10] = &BUTTON_DUMMY1;
	
	buttons[0][6] = &BUTTON_ENTER;
	buttons[0][10] = &BUTTON_CLOSINGSQUAREBRACKET;
	buttons[0][8] = &BUTTON_A;
	buttons[1][5] = &BUTTON_R;
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
	buttons[0][13]] = &BUTTON_DUMMY6;
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
	
	
	
	
	
	
	init();
	
	uint8_t i, state;
	uint8_t k, found_active_L2_repeatable;
	found_active_L2_repeatable = 0;
	struct button* button;
	
	uint8_t need_send = 0; 
	uint8_t L2_active = 0;
	uint8_t L3_active = 0;
	uint8_t shiftPlus_active = 0;
	struct button* active_L2_repeatables[L2_REPEATABLES_QUEUE_SIZE];
		for(i=0;i<L2_REPEATABLES_QUEUE_SIZE;i++){active_L2_repeatables[i] = 0;}
	struct button* previous_repeatables[2]; 
		for(i=0;i<2;i++){previous_repeatables[i] = &BUTTON_SPACE;}
	
	
	// // TIMER1
	// TCNT1H = 0;
	// TCNT1L = 0;
	
	// OCR1BH = 0x10;
	// OCR1BL = 0;
	
	// TCCR1A = (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11);
	
	// ICR1H = 0x20;
	// ICR1L = 0;
	
	// TCCR1B = (1<<WGM13) | (1<<WGM12);
	
	
	// // TIMER3
	
	// OCR3AH = 0x9C;
	// OCR3AL = 0x40;
	
	// TIMSK3 |= (1<<OCIE3A);
	
	// TCCR3B |= (1<<WGM32);
	
	
	while(1){
		
		
		for(i=0; i <NUM_SHIFTREG; i++){

			gpio_put(PINS_ENABLE[i], 0);

			for j=0; j < NUM_PINS_PER_SHIFTREG; j++){
				
				button = buttons[i];
				
				if(button){

                    if (j & 8){
                        gpio_put(PIN_S3, 1);
                    }else{
						gpio_put(PIN_S3, 0);
					}
                    if (j & 4){
                        gpio_put(PIN_S2, 1);
                    }else{
						gpio_put(PIN_S2, 0);
					}
                    if (j & 2){
                        gpio_put(PIN_S1, 1);
                    }else{
						gpio_put(PIN_S1, 0);
					}
                    if (j & 1){
                        gpio_put(PIN_S0, 1);
                    }else{
						gpio_put(PIN_S0, 0);
					}

                    // sleep_us(15); // this is what riskable uses; adds 1.44 ms to full scan
                    sleep_us(7); // seems to be enough
                    uint16_t result = adc_read();
                    
                    // printf("%f ", result * conversion_factor);

                    // if (result*conversion_factor > THRESHOLD_SENSOR){
                    if (result > THRESHOLD_SENSOR){

                        // printf("%d %d %d %f \n", i, j, result, result * conversion_factor);
						printf("%d", buttons[i][j].scancodes[0]);
                        // sleep_ms(1000);
						state = 0;
                    }else{
						state = 1;
					}

					if(button->stuff.pressed && state){
						
						button->stuff.pressed = 0;
						
						if(button == &BUTTON_L3){
							L3_active = 0;
						}else if(button == &BUTTON_L2){
							L2_active = 0;
						}
						
						g_active_mods &= ~button->stuff.mods;
						
						if(button->stuff.pressed_L2){
							if(button->stuff.is_L2_repeatable){
								for(k=0;k<L2_REPEATABLES_QUEUE_SIZE;k++){
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
						
						
					}else if(!button->stuff.pressed && !state){
						
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
								for(k=0;k<L2_REPEATABLES_QUEUE_SIZE;k++){
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
									for(k=0;k<L2_REPEATABLES_QUEUE_SIZE;k++){
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
		
		set_PINX_output(PIN_CE, 1);
		
	}

	return 1;
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

// kinda shit, only works for L1; should probably step back and rethink before expanding to L2
void press_redundant(struct button* button, uint8_t scancode, uint8_t extra_mods){
	
	for(int i = 0; i < BUTTONS_LENGTH; i++){
		if(buttons[i]->stuff.pressed && buttons[i]->current_scancode == scancode){
			// buttons[i]->stuff.pressed = 0;
			buttons[i]->current_scancode = 0;
			buttons[i]->current_extra_key = 0;
		}
	}

	usb_keyboard_send();
	button->current_scancode = scancode;
	usb_keyboard_send();
}

// void beep(void){
	
// 	TCNT3H = 0;
// 	TCNT3L = 0;
	
// 	TCCR1B |= (1<<CS10);
// 	TCCR3B |= (1<<CS31);
// }

// ISR(TIMER3_COMPA_vect){
	
// 	TCCR1B &= ~(1<<CS10);
// 	TCCR3B &= ~(1<<CS32);
	
// 	// set_PINX_output(PIN_BUZZER, 1);
// }