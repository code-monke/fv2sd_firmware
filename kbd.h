

#include "buttons.h"


uint8_t init_promicro(void);

void pulse(struct button* button, uint8_t scancode, uint8_t extra_mods);
void press_redundant(struct button* button, uint8_t scancode, uint8_t extra_mods);
void beep(void);