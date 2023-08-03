#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "thermostat.h"
#include "bme680_bsec.h"

bme680_data_t gas_sesnor_data;


void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    thermostat_setup();
    bme680_setup(true); // true : initialize i2c, false : skips i2c initialization
    thermostat_test();

    while (1) 
    {
        printf("All Relay Status 0 to 6 : ");
        for (size_t relay_no = 0; relay_no < 7; relay_no++)
        {
            printf("| %d ", thermostat_get_relay_status(relay_no));
        }
        printf("\n");

        if (bme680_get_data(&gas_sesnor_data))
        {
            bme680_print_data(&gas_sesnor_data);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}