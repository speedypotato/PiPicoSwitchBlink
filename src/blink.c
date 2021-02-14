/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Modified by SpeedyPotato
 */

#include "pico/stdlib.h"

const uint LED_PIN = 25;
const uint SW_PIN = 14;

void blink_led() {
    gpio_put(LED_PIN, 1);
    sleep_ms(250);
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
}

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // setup button inputs
    gpio_init(SW_PIN);
    gpio_set_function(SW_PIN, GPIO_FUNC_SIO); gpio_set_dir(SW_PIN, GPIO_IN); gpio_pull_up(SW_PIN);

    while (true) {
        if (!gpio_get(SW_PIN)) {
            blink_led();
        }
    }
}
