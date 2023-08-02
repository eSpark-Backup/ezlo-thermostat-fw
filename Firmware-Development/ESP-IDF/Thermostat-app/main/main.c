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
        thermostat_control_relay(relay_no, ENABLE);
        printf("Enable : Relay No : %d Status after : %d\n", relay_no, thermostat_get_relay_status(relay_no));
               
    }

    printf("All Relay Status 0 to 6 : ");
    for (size_t relay_no = 0; relay_no < 7; relay_no++)
    {
        printf("| %d ", thermostat_get_relay_status(relay_no));
    }
    printf("\n");
    vTaskDelay(3000 / portTICK_PERIOD_MS);

    for (size_t relay_no = 0; relay_no < 7; relay_no++)
    {
        printf("Disable : Relay No : %d Status before : %d\n", relay_no, thermostat_get_relay_status(relay_no));
        thermostat_control_relay(relay_no, DISABLE);
        printf("Disable : Relay No : %d Status after : %d\n", relay_no, thermostat_get_relay_status(relay_no));
        
    }

    while (1) 
    {
        printf("All Relay Status 0 to 6 : ");
        for (size_t relay_no = 0; relay_no < 7; relay_no++)
        {
            printf("| %d ", thermostat_get_relay_status(relay_no));
        }
        printf("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}