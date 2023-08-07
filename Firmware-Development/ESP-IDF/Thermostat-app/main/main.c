#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "thermostat.h"
#include "bme680_bsec.h"
#include "SK6812_lib.h"

static const char* TAG = "Appication";

bme680_data_t gas_sesnor_data;

void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    thermostat_setup();
    bme680_setup(true); // true : initialize i2c, false : skips i2c initialization

    led_strip_t sk6812;
    if(ESP_OK != sk6812_setup(&sk6812))
    {
        ESP_LOGE(TAG, "Failed to initialize sk6812");
    }

    sk6812_set_brightness(&sk6812, 255);
    sk6812_set_color(&sk6812, 0, 1, INDIANRED);
    sk6812_set_color(&sk6812, 1, 1, TEAL);
    sk6812_set_color(&sk6812, 2, 1, FORESTGREEN);
    sk6812_set_color(&sk6812, 3, 1, GOLDENROD);
    sk6812_show(&sk6812);

    thermostat_test();

    while (1) 
    {
        if (bme680_get_data(&gas_sesnor_data))
        {
            bme680_print_data(&gas_sesnor_data);
        }
    }
}
