#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "thermostat.h"
#include "bme680_bsec.h"
#include "SK6812_lib.h"

bme680_data_t gas_sesnor_data;


void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    // thermostat_setup();
    // bme680_setup(true); // true : initialize i2c, false : skips i2c initialization
    // thermostat_test();
    led_strip_t sk6812;
    sk6812_setup(&sk6812);
    sk6812_set_color(&sk6812, CYAN);
    sk6812_set_brightness(&sk6812, 255);
    sk6812_show(&sk6812);
    uint32_t color_hex = CYAN;

    while (1) 
    {
        // printf("All Relay Status 0 to 6 : ");
        // for (size_t relay_no = 0; relay_no < 7; relay_no++)
        // {
        //     printf("| %d ", thermostat_get_relay_status(relay_no));
        // }
        // printf("\n");

        // if (bme680_get_data(&gas_sesnor_data))
        // {
        //     bme680_print_data(&gas_sesnor_data);
        // }
    //     for(uint8_t brightness = 0; brightness < 255; brightness++)
    //    {
    //         sk6812_set_brightness(&sk6812, brightness);
    //         sk6812_show(&sk6812);
    //         vTaskDelay(50 / portTICK_RATE_MS);
    //    } 
    sk6812_set_color(&sk6812, RED);
    sk6812_set_brightness(&sk6812, 255);
    sk6812_show(&sk6812);
    vTaskDelay(10 / portTICK_RATE_MS);
    // sk6812_set_color(&sk6812, GREEN);
    // sk6812_set_brightness(&sk6812, 255);
    // sk6812_show(&sk6812);
    // vTaskDelay(1000 / portTICK_RATE_MS);
    // sk6812_set_color(&sk6812, BLUE);
    // sk6812_set_brightness(&sk6812, 255);
    // sk6812_show(&sk6812);
    // vTaskDelay(1000 / portTICK_RATE_MS);
    // color_hex += 1000;
    //    printf("loop\n");
    }
}