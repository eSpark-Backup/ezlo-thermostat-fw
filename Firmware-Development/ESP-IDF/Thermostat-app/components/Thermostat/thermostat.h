#pragma once

#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"

#define RELAYSET       GPIO_NUM_4     
#define RELAYRESET     GPIO_NUM_5
#define RELAYSTATUS    GPIO_NUM_6
#define RELAYADDR0     GPIO_NUM_7
#define RELAYADDR1     GPIO_NUM_8
#define RELAYADDR2     GPIO_NUM_9

typedef struct relay_addr 
{
    uint8_t addr0 : 1; 
    uint8_t addr1 : 1; 
    uint8_t addr2 : 1; 
} relay_addr_t;

typedef enum relay_state
{
    DISABLE,
    ENABLE
} relay_state_t;

esp_err_t thermostat_setup(void);

void thermostat_control_relay(uint8_t relay_addr, relay_state_t state);
