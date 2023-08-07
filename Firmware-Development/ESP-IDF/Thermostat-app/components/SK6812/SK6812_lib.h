#pragma once

#include <led_strip.h> 
#include "driver/gpio.h"
#include "color_codes.h"

#define LED_TYPE        LED_STRIP_SK6812
#define LED_GPIO        GPIO_NUM_16
#define LED_STRIP_LEN   4

esp_err_t sk6812_setup(led_strip_t *strip);
esp_err_t sk6812_config(led_strip_t *strip);
esp_err_t sk6812_set_color(led_strip_t *strip, uint32_t start, uint32_t len, uint32_t color_code);
void sk6812_set_brightness(led_strip_t *strip, uint8_t brightness);
esp_err_t sk6812_show(led_strip_t *strip);
