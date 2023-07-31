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
        printf("Enable : Status before : %d\n", gpio_get_level(RELAYSTATUS));
        thermostat_control_relay(relay_no, ENABLE);
        printf("Enable : Status after : %d\n", gpio_get_level(RELAYSTATUS));
        vTaskDelay(1000 / portTICK_PERIOD_MS);       
    }

    vTaskDelay(5000 / portTICK_PERIOD_MS);

    for (size_t relay_no = 0; relay_no < 7; relay_no++)
    {
        printf("Disable : Status before : %d\n", gpio_get_level(RELAYSTATUS));
        thermostat_control_relay(relay_no, DISABLE);
        printf("Disable : Status after : %d\n", gpio_get_level(RELAYSTATUS));
        vTaskDelay(1000 / portTICK_PERIOD_MS);  
    }

    while (1) 
    {
        ESP_LOGI("LOOP", "RLYSTS PIN STATE : %d\n", gpio_get_level(RELAYSTATUS));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}