#include "SYSCTL/sysctl.h"



sint8_t SYSCTL_gpio_port_clk_config(uint8_t _port_index, uint8_t _config)
{
    sint8_t res = ALL_OK;

    // check for passed port index
    if ((_port_index < PORTA) || (_port_index > PORTF))
    {
        res = -EINVARG;
        goto out;
    }

    switch (_port_index)
    {
        case PORTA:
            if (_config == ENABLE)
                SET_BIT(RCGCGPIO_R, PORTA_CLK_BIT);
            else if (_config == DISABLE)
                CLR_BIT(RCGCGPIO_R, PORTA_CLK_BIT);
        break;

        case PORTB:
            if (_config == ENABLE)
                SET_BIT(RCGCGPIO_R, PORTB_CLK_BIT);
            else if (_config == DISABLE)
                CLR_BIT(RCGCGPIO_R, PORTB_CLK_BIT);
        break;

        case PORTC:
            if (_config == ENABLE)
                SET_BIT(RCGCGPIO_R, PORTC_CLK_BIT);
            else if (_config == DISABLE)
                CLR_BIT(RCGCGPIO_R, PORTC_CLK_BIT);
        break;

        case PORTD:
            if (_config == ENABLE)
                SET_BIT(RCGCGPIO_R, PORTD_CLK_BIT);
            else if (_config == DISABLE)
                CLR_BIT(RCGCGPIO_R, PORTD_CLK_BIT);
        break;

        case PORTE:
            if (_config == ENABLE)
                SET_BIT(RCGCGPIO_R, PORTE_CLK_BIT);
            else if (_config == DISABLE)
                CLR_BIT(RCGCGPIO_R, PORTE_CLK_BIT);
        break;

        case PORTF:
            if (_config == ENABLE)
                SET_BIT(RCGCGPIO_R, PORTF_CLK_BIT);
            else if (_config == DISABLE)
                CLR_BIT(RCGCGPIO_R, PORTF_CLK_BIT);
        break;
    }

out:
    return res;
}

sint8_t SYSCTL_gpio_port_bus_config(uint8_t _port_index, uint8_t _config)
{
    sint8_t res = ALL_OK;

    // check for passed port index
    if ((_port_index < PORTA) || (_port_index > PORTF))
    {
        res = -EINVARG;
        goto out;
    }

    switch (_port_index)
    {
        case PORTA:
            if (_config == ENABLE)
                SET_BIT(GPIOHBCTL_R, PORTA_BUS_BIT);
            else if (_config == DISABLE)
                CLR_BIT(GPIOHBCTL_R, PORTA_BUS_BIT);
        break;

        case PORTB:
            if (_config == ENABLE)
                SET_BIT(GPIOHBCTL_R, PORTB_BUS_BIT);
            else if (_config == DISABLE)
                CLR_BIT(GPIOHBCTL_R, PORTB_BUS_BIT);
        break;

        case PORTC:
            if (_config == ENABLE)
                SET_BIT(GPIOHBCTL_R, PORTC_BUS_BIT);
            else if (_config == DISABLE)
                CLR_BIT(GPIOHBCTL_R, PORTC_BUS_BIT);
        break;

        case PORTD:
            if (_config == ENABLE)
                SET_BIT(GPIOHBCTL_R, PORTD_BUS_BIT);
            else if (_config == DISABLE)
                CLR_BIT(GPIOHBCTL_R, PORTD_BUS_BIT);
        break;

        case PORTE:
            if (_config == ENABLE)
                SET_BIT(GPIOHBCTL_R, PORTE_BUS_BIT);
            else if (_config == DISABLE)
                CLR_BIT(GPIOHBCTL_R, PORTE_BUS_BIT);
        break;

        case PORTF:
            if (_config == ENABLE)
                SET_BIT(GPIOHBCTL_R, PORTF_BUS_BIT);
            else if (_config == DISABLE)
                CLR_BIT(GPIOHBCTL_R, PORTF_BUS_BIT);
        break;
    }

out:
    return res;
}


