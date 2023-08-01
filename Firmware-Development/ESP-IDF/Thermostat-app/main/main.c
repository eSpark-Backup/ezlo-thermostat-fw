#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "thermostat.h"

void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    thermostat_setup();

    for (size_t relay_no = 0; relay_no < 7; relay_no++)
    {
        printf("Enable : Relay No : %d Status before : %d\n", relay_no, thermostat_get_relay_status(relay_no));
        // vTaskDelay(1000 / portTICK_PERIOD_MS);   
        thermostat_control_relay(relay_no, ENABLE);
        printf("Enable : Relay No : %d Status after : %d\n", relay_no, thermostat_get_relay_status(relay_no));
        vTaskDelay(1000 / portTICK_PERIOD_MS);       
    }

    vTaskDelay(3000 / portTICK_PERIOD_MS);

    for (size_t relay_no = 0; relay_no < 7; relay_no++)
    {
        printf("Disable : Relay No : %d Status before : %d\n", relay_no, thermostat_get_relay_status(relay_no));
        // vTaskDelay(1000 / portTICK_PERIOD_MS); 
        thermostat_control_relay(relay_no, DISABLE);
        printf("Disable : Relay No : %d Status after : %d\n", relay_no, thermostat_get_relay_status(relay_no));
        vTaskDelay(1000 / portTICK_PERIOD_MS);  
    }

    while (1) 
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}