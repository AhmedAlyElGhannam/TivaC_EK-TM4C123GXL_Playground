#ifndef SYS_CTL_H
#define SYS_CTL_H

#include "config.h"
#include "std_types.h"
#include "status.h"
#include "bit_op.h"
#include "tm4c123gh6pm.h"

enum SYSCTL_GPIOPortClkBit
{
    PORTA_CLK_BIT = 0,
    PORTB_CLK_BIT = 1,
    PORTC_CLK_BIT = 2,
    PORTD_CLK_BIT = 3,
    PORTE_CLK_BIT = 4,
    PORTF_CLK_BIT = 5
};

sint8_t SYSCTL_gpio_port_clk_config(uint8_t _port_index, uint8_t _config);

#endif
