
#include "esp_check.h"
#include "SK6812_lib.h"

/* 
    @func   :   sk6812_setup
                (Initializes the strip with SK6812 RGB LED ) 

    @param  :   strip (Pointer of LED strip descriptor)
*/
esp_err_t sk6812_setup(led_strip_t *strip)
{    
    led_strip_install();
    ESP_RETURN_ON_ERROR(sk6812_config(strip), "sk6812_config", "Pointer is NULL");
    return led_strip_init(strip);
}
/*
    @func   :   sk6812_config
                ( sets strip to SK6812 configuration (Ambient Pro Tracker)  ) 
*/
esp_err_t sk6812_config(led_strip_t *strip)
{
    if(strip == NULL)
        return ESP_FAIL;

    strip->type = LED_TYPE;
    strip->is_rgbw = false;
    strip->length = LED_STRIP_LEN;
    strip->gpio = LED_GPIO;
    strip->buf = NULL;
    strip->brightness = 255;
    strip->channel = RMT_CHANNEL_0;

    return ESP_OK;
}
/*  @func  :    sk6812_set_color 
                (It sets the color for the RGB-LED in the strip struct.) 

    @param :    strip (Pointer of LED strip descriptor)
                start (First LED index, 0-based)
                len (Number of LEDs)
                colorCode (24bit color-codes for e.g: 0xFF0000 - Red color)               
*/
esp_err_t sk6812_set_color(led_strip_t *strip, uint32_t start, uint32_t len, uint32_t color_code)
{
    rgb_t color = (rgb_t)rgb_from_code(color_code);
    return led_strip_fill(strip, start, len, color);  
}

/*  @func  :    sk6812_set_color 
                (It sets the color for the RGB-LED in the strip struct.) 

    @param :    strip (Pointer of LED strip descriptor)
                brightness ( 0 - 255)
*/
void sk6812_set_brightness(led_strip_t *strip , uint8_t brightness)
{
    return led_strip_set_brightness(strip, brightness);
}

/*  sk6812_show : Update Strip Buffer To LED. 
    This function must called after set_color or set_brightness to update LED.    
*/
esp_err_t sk6812_show(led_strip_t *strip)
{
    return led_strip_flush(strip);
}