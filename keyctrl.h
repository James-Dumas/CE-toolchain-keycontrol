#ifndef KEYCTRL_HEADER
#define KEYCTRL_HEADER

#include <stdbool.h>

void kc_update();

bool kc_state(char* key);
bool kc_pressed(char* key);
bool kc_released(char* key);

#endif
