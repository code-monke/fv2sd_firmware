
#include <stdio.h>

// #define DEBOUNCE //comment this out if no debounce needed
#define DEBOUNCE_MS 5
#define DEBOUNCE_PRECISION_MS 1
// number of bits =  ceiling(DEBOUNCE_MS / DEBOUNCE_PRECISION_MS) or something like that

#define L2_REPEATABLES_QUEUE_SIZE 4

#define NUM_LAYERS 3

struct button_stuff {
	uint32_t pressed : 1;
	uint32_t pressed_L2 : 1; // if the press took place on L2; used to identify if need to let go of L2_mods when unpress
	uint32_t mods : 4; // lgui, lalt, lshift, lctrl
	uint32_t L2_mods : 4; // can only be used for pulse keys
	uint32_t has_L2 : 1;
	uint32_t has_L3 : 1;
	uint32_t is_L2_extra : 1;
	uint32_t is_L3_extra : 1;
	uint32_t does_need_alt : 1;
	uint32_t does_L2_need_ctrl : 1;
	uint32_t does_L2_need_alt : 1;
	uint32_t is_shiftPlus: 1;
	uint32_t does_kill_shiftPlus : 1;
	uint32_t is_affected_by_shiftPlus : 1;
	uint32_t is_redundant : 1;
	uint32_t is_L2_redundant : 1;
	uint32_t is_repeatable : 1;
	uint32_t is_L2Rep : 1;
	uint32_t is_L2_repeatable : 1;
	
	#ifdef DEBOUNCE
	uint32_t is_locked : 1;
	uint32_t when_locked : 6;
	#endif
};

struct button {
	uint8_t current_scancode;
	uint8_t current_extra_key;
	struct button_stuff stuff;
	uint8_t extra_key;
	uint8_t scancodes[NUM_LAYERS];
};


extern struct button BUTTON_ESC;
extern struct button BUTTON_1;
extern struct button BUTTON_2;
extern struct button BUTTON_3;
extern struct button BUTTON_4;
extern struct button BUTTON_5;
extern struct button BUTTON_6;
extern struct button BUTTON_7;
extern struct button BUTTON_8;
extern struct button BUTTON_9;
extern struct button BUTTON_0;
extern struct button BUTTON_MINUS;
extern struct button BUTTON_EQUALS;
extern struct button BUTTON_TILDE;
extern struct button BUTTON_TAB;
extern struct button BUTTON_Q;
extern struct button BUTTON_SHIFTPLUS1;
extern struct button BUTTON_W;
extern struct button BUTTON_F;
extern struct button BUTTON_P;
extern struct button BUTTON_G;
extern struct button BUTTON_L;
extern struct button BUTTON_U;
extern struct button BUTTON_Y;
extern struct button BUTTON_SEMICOLON;
extern struct button BUTTON_SHIFTPLUS2;
extern struct button BUTTON_BACKSLASH;
extern struct button BUTTON_ENTER;
extern struct button BUTTON_CLOSINGSQUAREBRACKET;
extern struct button BUTTON_A;
extern struct button BUTTON_R;
extern struct button BUTTON_S;
extern struct button BUTTON_T;
extern struct button BUTTON_D;
extern struct button BUTTON_H;
extern struct button BUTTON_H;
extern struct button BUTTON_E;
extern struct button BUTTON_I;
extern struct button BUTTON_O;
extern struct button BUTTON_ENTER_1;
extern struct button BUTTON_OPENINGSQUAREBRACKET;
extern struct button BUTTON_APOSTROPHE;
extern struct button BUTTON_Z;
extern struct button BUTTON_X;
extern struct button BUTTON_C;
extern struct button BUTTON_V;
extern struct button BUTTON_B;
extern struct button BUTTON_K;
extern struct button BUTTON_M;
extern struct button BUTTON_COMMA;
extern struct button BUTTON_PERIOD;
extern struct button BUTTON_FORWARDSLASH;
extern struct button BUTTON_L2;
extern struct button BUTTON_REP1;
extern struct button BUTTON_SPACE;
extern struct button BUTTON_SPACE_1;
extern struct button BUTTON_REP2;
extern struct button BUTTON_LGUI;
extern struct button BUTTON_L3;
extern struct button BUTTON_LCTRL;
extern struct button BUTTON_LSHIFT;
extern struct button BUTTON_LALT;
extern struct button BUTTON_ALTTAB;

extern struct button BUTTON_DUMMY1;
extern struct button BUTTON_DUMMY2;
extern struct button BUTTON_DUMMY3;
extern struct button BUTTON_DUMMY4;
extern struct button BUTTON_DUMMY5;
extern struct button BUTTON_DUMMY6;
extern struct button BUTTON_BACKSPACE;
extern struct button BUTTON_J;
extern struct button BUTTON_N;
extern struct button BUTTON_RSHIFT;
