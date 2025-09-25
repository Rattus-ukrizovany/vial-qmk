// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void keyboard_pre_init_kb(void) {
    // Initialize indicator LEDs to output
    setPinOutput(B2); // Caps Lock LED
    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // Write LED state out to hardware
        writePin(B2, !led_state.caps_lock);
    }
    return res;
}