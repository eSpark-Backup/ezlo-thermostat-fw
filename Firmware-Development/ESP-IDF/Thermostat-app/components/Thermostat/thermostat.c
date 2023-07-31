#include "thermostat.h"

static void thermostat_relays_setup(void)
{
    gpio_reset_pin(RELAYSET);
    gpio_set_direction(RELAYSET, GPIO_MODE_OUTPUT);

    gpio_reset_pin(RELAYRESET);
    gpio_set_direction(RELAYRESET, GPIO_MODE_OUTPUT);

    gpio_reset_pin(RELAYSTATUS);
    gpio_set_direction(RELAYSTATUS, GPIO_MODE_INPUT);

    gpio_reset_pin(RELAYADDR0);
    gpio_set_direction(RELAYADDR0, GPIO_MODE_OUTPUT);

    gpio_reset_pin(RELAYADDR1);
    gpio_set_direction(RELAYADDR1, GPIO_MODE_OUTPUT);

    gpio_reset_pin(RELAYADDR2);
    gpio_set_direction(RELAYADDR2, GPIO_MODE_OUTPUT);
}

void thermostat_control_relay(uint8_t relay_addr, relay_state_t state)
{
    relay_addr_t relay;
    memcpy(&relay, &relay_addr, sizeof(relay));
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(RELAYSET, state);
    gpio_set_level(RELAYRESET, !state);
    gpio_set_level(RELAYADDR0, relay.addr0);
    gpio_set_level(RELAYADDR1, relay.addr1);
    gpio_set_level(RELAYADDR2, relay.addr2);
}

esp_err_t thermostat_setup(void)
{
    thermostat_relays_setup();
    return ESP_OK;
}