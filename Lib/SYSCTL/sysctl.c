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

    // check for passed config
    if ((_config != ENABLE) && (_config != DISABLE))
    {
        res = -EINVARG;
        goto out;
    }

	// set or clear bit in reg depending on passed config
	if (_config == ENABLE)
        SET_BIT(RCGCGPIO_R, _port_index);
    else if (_config == DISABLE)
        CLR_BIT(RCGCGPIO_R, _port_index);

out:
    return res;
}

// this function should only be accessible IF port bus is AHB
#ifdef (GPIO_PORT_BUS == AHB_BUS)
sint8_t SYSCTL_gpio_port_bus_config(uint8_t _port_index, uint8_t _config)
{
    sint8_t res = ALL_OK;

    // check for passed port index
    if ((_port_index < PORTA) || (_port_index > PORTF))
    {
        res = -EINVARG;
        goto out;
    }

    // check for passed config
    if ((_config != ENABLE) && (_config != DISABLE))
    {
        res = -EINVARG;
        goto out;
    }

	// set or clear bit in reg depending on passed config
	if (_config == ENABLE)
        SET_BIT(GPIOHBCTL_R, _port_index);
    else if (_config == DISABLE)
        CLR_BIT(GPIOHBCTL_R, _port_index);

out:
    return res;
}
#endif

sint8_t SYSCTL_uart_clk_config(uint8_t _uart_module, uint8_t _config)
{
	sint8_t res = ALL_OK;

    // check for passed uart module index
    if ((_uart_module < UART0) || (_uart_module > UART7))
    {
        res = -EINVARG;
        goto out;
    }

	// check for passed config
	if ((_config != ENABLE) && (_config != DISABLE))
    {
        res = -EINVARG;
        goto out;
    }

	// set or clear bit in reg depending on passed config
	if (_config == ENABLE)
        SET_BIT(RCGCUART_R, _uart_module);
    else if (_config == DISABLE)
        CLR_BIT(RCGCUART_R, _uart_module);

out:
    return res;
}

