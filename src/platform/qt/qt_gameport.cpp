#include <cstdint>
#include "../../game/gameport.h"


plat_joystick_t plat_joystick_state[MAX_PLAT_JOYSTICKS];
joystick_t joystick_state[MAX_JOYSTICKS];
int joysticks_present = 0;
int joystick_type = 0;


void joystick_init() {
}

void joystick_close(){
}

void joystick_process() {
}
