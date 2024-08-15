#include "gpio.h"

// gpio_port_init
//uint8_t GPIO_portInit(struct GPIO_port* _port, )

/*
	1. create a struct for pin
	2. call pin_init(struct pin, port_index, pin_index)
		// will do the default configuration (make macros for it or sth)
*/

/**
	Arguments:
		1. address of struct GPIO_pin || struct GPIO_pin*
		2. port index
		3. pin index
		
	Description:
		1. 
*/

enum GPIO_PinIndex
{
	PIN0 = 0,
    PIN1 = 1,
    PIN2 = 2,
    PIN3 = 3,
    PIN4 = 4,
    PIN5 = 5,
    PIN6 = 6,
    PIN7 = 7
};

enum GPIO_PortIndex
{
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
	PORTF = 5
};



// GPIO Port ISRs -> note that each port ISR is shared between all its pins
GPIO_INTERRUPT_CALLBACK_FUNC GPIO_ISR_PORTA = NULL;
GPIO_INTERRUPT_CALLBACK_FUNC GPIO_ISR_PORTB = NULL;
GPIO_INTERRUPT_CALLBACK_FUNC GPIO_ISR_PORTC = NULL;
GPIO_INTERRUPT_CALLBACK_FUNC GPIO_ISR_PORTD = NULL;
GPIO_INTERRUPT_CALLBACK_FUNC GPIO_ISR_PORTE = NULL;
GPIO_INTERRUPT_CALLBACK_FUNC GPIO_ISR_PORTF = NULL;


sint8_t GPIO_set_pin_ISR(struct GPIO_pin* _pin, GPIO_INTERRUPT_CALLBACK_FUNC _isr)
{
	if (NULL == _pin)
	{
		return (-EINVARG);
	}
	
	switch (_pin->port_index)
	{
		case PORTA:
			GPIO_ISR_PORTA = _isr;
		break;
		
		case PORTB:
			GPIO_ISR_PORTB = _isr;
		break;
		
		case PORTC:
			GPIO_ISR_PORTC = _isr;
		break;
		
		case PORTD:
			GPIO_ISR_PORTD = _isr;
		break;
		
		case PORTE:
			GPIO_ISR_PORTE = _isr;
		break;
		
		case PORTF:
			GPIO_ISR_PORTF = _isr;
		break;
	}
	
	return ALL_OK;
}

sint8_t GPIO_pin_config_lock(struct GPIO_pin* _pin, uint32_t _lock)
{
	if (NULL == _pin)
	{
		return (-EINVARG);
	}
	
	switch (_pin->port_index)
	{
		case PORTA:
			GPIOLOCK_R_PORTA = _lock;
		break;
		
		case PORTB:
			GPIOLOCK_R_PORTB = _lock;
		break;
		
		case PORTC:
			GPIOLOCK_R_PORTC = _lock;
		break;
		
		case PORTD:
			GPIOLOCK_R_PORTD = _lock;
		break;
		
		case PORTE:
			GPIOLOCK_R_PORTE = _lock;
		break;
		
		case PORTF:
			GPIOLOCK_R_PORTF = _lock;
		break;
	}
	
	return ALL_OK;
}


static void GPIO_set_pin_port_indices(struct GPIO_pin* _pin, uint8_t _port_index, uint8_t _pin_index)
{
	_pin->port_index = _port_index;
	_pin->port_index = _pin_index;
}

sint8_t GPIO_pin_AFSEL_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}

	_pin->pad_config.AFSEL = _config;
	
	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == ENABLE)
				SET_BIT(GPIOAFSEL_R_PORTA, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIOAFSEL_R_PORTA, _pin->pin_index);
		break;
		
		case PORTB:
			if (_config == ENABLE)
				SET_BIT(GPIOAFSEL_R_PORTB, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIOAFSEL_R_PORTB, _pin->pin_index);
		break;
		
		case PORTC:
			if (_config == ENABLE)
				SET_BIT(GPIOAFSEL_R_PORTC, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIOAFSEL_R_PORTC, _pin->pin_index);
		break;
		
		case PORTD:
			if (_config == ENABLE)
				SET_BIT(GPIOAFSEL_R_PORTD, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIOAFSEL_R_PORTD, _pin->pin_index);
		break;
		
		case PORTE:
			if (_config == ENABLE)
				SET_BIT(GPIOAFSEL_R_PORTE, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIOAFSEL_R_PORTE, _pin->pin_index);
		break;
		
		case PORTF:
			if (_config == ENABLE)
				SET_BIT(GPIOAFSEL_R_PORTF, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIOAFSEL_R_PORTF, _pin->pin_index);
		break;
	}

out:
	return res;
}

sint8_t GPIO_pin_direction_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	_pin->pad_config.DIR = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == OUTPUT)
				SET_BIT(GPIODIR_R_PORTA, _pin->pin_index);
			else if (_config == INPUT)
				CLR_BIT(GPIODIR_R_PORTA, _pin->pin_index);
		break;
		
		case PORTB:
			if (_config == OUTPUT)
				SET_BIT(GPIODIR_R_PORTB, _pin->pin_index);
			else if (_config == INPUT)
				CLR_BIT(GPIODIR_R_PORTB, _pin->pin_index);
		break;
		
		case PORTC:
			if (_config == OUTPUT)
				SET_BIT(GPIODIR_R_PORTC, _pin->pin_index);
			else if (_config == INPUT)
				CLR_BIT(GPIODIR_R_PORTC, _pin->pin_index);
		break;
		
		case PORTD:
			if (_config == OUTPUT)
				SET_BIT(GPIODIR_R_PORTD, _pin->pin_index);
			else if (_config == INPUT)
				CLR_BIT(GPIODIR_R_PORTD, _pin->pin_index);
		break;
		
		case PORTE:
			if (_config == OUTPUT)
				SET_BIT(GPIODIR_R_PORTE, _pin->pin_index);
			else if (_config == INPUT)
				CLR_BIT(GPIODIR_R_PORTE, _pin->pin_index);
		break;
		
		case PORTF:
			if (_config == OUTPUT)
				SET_BIT(GPIODIR_R_PORTF, _pin->pin_index);
			else if (_config == INPUT)
				CLR_BIT(GPIODIR_R_PORTF, _pin->pin_index);
		break;
	}

out:
	return res;
}


sint8_t GPIO_pin_digital_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}

	_pin->pad_config.DEN = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == ENABLE)
				SET_BIT(GPIODEN_R_PORTA, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIODEN_R_PORTA, _pin->pin_index);
		break;
		
		case PORTB:
			if (_config == ENABLE)
				SET_BIT(GPIODEN_R_PORTB, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIODEN_R_PORTB, _pin->pin_index);
		break;
		
		case PORTC:
			if (_config == ENABLE)
				SET_BIT(GPIODEN_R_PORTC, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIODEN_R_PORTC, _pin->pin_index);
		break;
		
		case PORTD:
			if (_config == ENABLE)
				SET_BIT(GPIODEN_R_PORTD, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIODEN_R_PORTD, _pin->pin_index);
		break;
		
		case PORTE:
			if (_config == ENABLE)
				SET_BIT(GPIODEN_R_PORTE, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIODEN_R_PORTE, _pin->pin_index);
		break;
		
		case PORTF:
			if (_config == ENABLE)
				SET_BIT(GPIODEN_R_PORTF, _pin->pin_index);
			else if (_config == DISABLE)
				CLR_BIT(GPIODEN_R_PORTF, _pin->pin_index);
		break;
	}

out:
	return res;
}
 

sint8_t GPIO_pin_resistor_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	_pin->pad_config.RES = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == PULL_UP_RESISTOR)
			{
				SET_BIT(GPIOPUR_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTA, _pin->pin_index);
			}	
			else if (_config == PULL_DOWN_RESISTOR)
			{
				SET_BIT(GPIOPDR_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTA, _pin->pin_index);
			}
			else if (_config == OPEN_DRAIN_RESISTOR)
			{
				SET_BIT(GPIOODR_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTA, _pin->pin_index);
			}
		break;
		
		case PORTB:
			if (_config == PULL_UP_RESISTOR)
			{
				SET_BIT(GPIOPUR_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTB, _pin->pin_index);
			}	
			else if (_config == PULL_DOWN_RESISTOR)
			{
				SET_BIT(GPIOPDR_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTB, _pin->pin_index);
			}
			else if (_config == OPEN_DRAIN_RESISTOR)
			{
				SET_BIT(GPIOODR_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTB, _pin->pin_index);
			}
		break;
		
		case PORTC:
			if (_config == PULL_UP_RESISTOR)
			{
				SET_BIT(GPIOPUR_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTC, _pin->pin_index);
			}	
			else if (_config == PULL_DOWN_RESISTOR)
			{
				SET_BIT(GPIOPDR_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTC, _pin->pin_index);
			}
			else if (_config == OPEN_DRAIN_RESISTOR)
			{
				SET_BIT(GPIOODR_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTC, _pin->pin_index);
			}
		break;
		
		case PORTD:
			if (_config == PULL_UP_RESISTOR)
			{
				SET_BIT(GPIOPUR_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTD, _pin->pin_index);
			}	
			else if (_config == PULL_DOWN_RESISTOR)
			{
				SET_BIT(GPIOPDR_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTD, _pin->pin_index);
			}
			else if (_config == OPEN_DRAIN_RESISTOR)
			{
				SET_BIT(GPIOODR_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTD, _pin->pin_index);
			}
		break;
		
		case PORTE:
			if (_config == PULL_UP_RESISTOR)
			{
				SET_BIT(GPIOPUR_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTE, _pin->pin_index);
			}	
			else if (_config == PULL_DOWN_RESISTOR)
			{
				SET_BIT(GPIOPDR_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTE, _pin->pin_index);
			}
			else if (_config == OPEN_DRAIN_RESISTOR)
			{
				SET_BIT(GPIOODR_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTE, _pin->pin_index);
			}
		break;
		
		case PORTF:
			if (_config == PULL_UP_RESISTOR)
			{
				SET_BIT(GPIOPUR_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTF, _pin->pin_index);
			}	
			else if (_config == PULL_DOWN_RESISTOR)
			{
				SET_BIT(GPIOPDR_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIOODR_R_PORTF, _pin->pin_index);
			}
			else if (_config == OPEN_DRAIN_RESISTOR)
			{
				SET_BIT(GPIOODR_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIOPUR_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIOPDR_R_PORTF, _pin->pin_index);
			}
		break;
	}

out:
	return res;
}


sint8_t GPIO_pin_drive_current_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}

	_pin->pad_config.DRX = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == DRIVE_CURRENT_2MA)
			{
				SET_BIT(GPIODR2R_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTA, _pin->pin_index);
			}	
			else if (_config == DRIVE_CURRENT_4MA)
			{
				SET_BIT(GPIODR4R_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTA, _pin->pin_index);
			}
			else if (_config == DRIVE_CURRENT_8MA)
			{
				SET_BIT(GPIODR8R_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTA, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTA, _pin->pin_index);
			}
		break;
		
		case PORTB:
			if (_config == DRIVE_CURRENT_2MA)
			{
				SET_BIT(GPIODR2R_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTB, _pin->pin_index);
			}	
			else if (_config == DRIVE_CURRENT_4MA)
			{
				SET_BIT(GPIODR4R_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTB, _pin->pin_index);
			}
			else if (_config == DRIVE_CURRENT_8MA)
			{
				SET_BIT(GPIODR8R_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTB, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTB, _pin->pin_index);
			}
		break;
		
		case PORTC:
			if (_config == DRIVE_CURRENT_2MA)
			{
				SET_BIT(GPIODR2R_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTC, _pin->pin_index);
			}	
			else if (_config == DRIVE_CURRENT_4MA)
			{
				SET_BIT(GPIODR4R_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTC, _pin->pin_index);
			}
			else if (_config == DRIVE_CURRENT_8MA)
			{
				SET_BIT(GPIODR8R_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTC, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTC, _pin->pin_index);
			}
		break;
		
		case PORTD:
			if (_config == DRIVE_CURRENT_2MA)
			{
				SET_BIT(GPIODR2R_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTD, _pin->pin_index);
			}	
			else if (_config == DRIVE_CURRENT_4MA)
			{
				SET_BIT(GPIODR4R_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTD, _pin->pin_index);
			}
			else if (_config == DRIVE_CURRENT_8MA)
			{
				SET_BIT(GPIODR8R_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTD, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTD, _pin->pin_index);
			}
		break;
		
		case PORTE:
			if (_config == DRIVE_CURRENT_2MA)
			{
				SET_BIT(GPIODR2R_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTE, _pin->pin_index);
			}	
			else if (_config == DRIVE_CURRENT_4MA)
			{
				SET_BIT(GPIODR4R_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTE, _pin->pin_index);
			}
			else if (_config == DRIVE_CURRENT_8MA)
			{
				SET_BIT(GPIODR8R_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTE, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTE, _pin->pin_index);
			}
		break;
		
		case PORTF:
			if (_config == DRIVE_CURRENT_2MA)
			{
				SET_BIT(GPIODR2R_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTF, _pin->pin_index);
			}	
			else if (_config == DRIVE_CURRENT_4MA)
			{
				SET_BIT(GPIODR4R_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIODR8R_R_PORTF, _pin->pin_index);
			}
			else if (_config == DRIVE_CURRENT_8MA)
			{
				SET_BIT(GPIODR8R_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIODR2R_R_PORTF, _pin->pin_index);
				CLR_BIT(GPIODR4R_R_PORTF, _pin->pin_index);
			}
		break;
	}

out:
	return res;
}


sint8_t GPIO_pin_slew_rate_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	_pin->pad_config.SLR = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if ((_config == ENABLE) && (_pin->pad_config.DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTA, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTA, _pin->pin_index);
		break;
		
		case PORTB:
			if ((_config == ENABLE) && (_pin->pad_config.DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTB, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTB, _pin->pin_index);
		break;
		
		case PORTC:
			if ((_config == ENABLE) && (_pin->pad_config.DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTC, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTC, _pin->pin_index);
		break;
		
		case PORTD:
			if ((_config == ENABLE) && (_pin->pad_config.DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTD, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTD, _pin->pin_index);
		break;
		
		case PORTE:
			if ((_config == ENABLE) && (_pin->pad_config.DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTE, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTE, _pin->pin_index);
		break;
		
		case PORTF:
			if ((_config == ENABLE) && (_pin->pad_config.DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTF, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTF, _pin->pin_index);
		break;
	}

out:
	return res;
}

sint8_t GPIO_pin_pad_config(struct GPIO_pin* _pin)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	res = GPIO_pin_AFSEL_config(_pin, _pin->pad_config.AFSEL);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_direction_config(_pin, _pin->pad_config.DIR);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_digital_config(_pin, _pin->pad_config.DEN);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_resistor_config(_pin, _pin->pad_config.RES);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_drive_current_config(_pin, _pin->pad_config.DRX);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_slew_rate_config(_pin, _pin->pad_config.SLR);
	if (res < 0)
	{
		goto out;
	}
	
out:
	return res;
}

sint8_t GPIO_pin_init(struct GPIO_pin* _pin, uint8_t _port_index, uint8_t _pin_index)
{
	sint8_t res = ALL_OK;
	
	// check for passed pointer
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	// check for passed port index
	if (~((_port_index >= PORTA) && (_port_index <= PORTF)))
	{
		res = -EINVARG;
		goto out;
	}
	
	// check for passed pin index
	if (~(_pin_index < PORTA_MAX_PIN))
	{
		res = -EINVARG;
		goto out;
	}
	
	// check if pin index matches assigned port (PA->PD have 8 pins each but PE has 6 and PF has 5)
	if (((_pin_index >= PORTF_MAX_PIN) && (_port_index != PORTF)) || ((_pin_index >= PORTE_MAX_PIN) && (_port_index != PORTE)))
	{
		res = -EINVARG;
		goto out;
	}
	
	// set port and pin indices
	GPIO_set_pin_port_indices(_pin, _port_index, _pin_index)
	
	// set ISR to NULL until explicitly changed
	GPIO_set_pin_ISR(_pin, (GPIO_INTERRUPT_CALLBACK_FUNC)NULL);
	
	// by default, port is unlocked
	GPIO_pin_config_lock(_pin, UNLOCK);
	
	
	// pad configuration for pin
	_pin->pad_config.AFSEL = DISABLED;
	_pin->pad_config.DIR = OUTPUT;
	_pin->pad_config.DEN = ENABLED;
	_pin->pad_config.RES = PULL_UP_RESISTOR;
	_pin->pad_config.DRX = DRIVE_CURRENT_8MA;
	_pin->pad_config.SLR = ENABLED;	
	
	GPIO_pin_pad_config(_pin);
	
	// creating interrupt configuration for pin
	_pin->interrupt_config.sense_trig = RISING_EDGE;
	_pin->interrupt_config.state = MASKED;
	
out:
	return res;
}


// gpio_pin_init
// gpio_port_read
// gpio_pin_read
// gpio_port write
// gpio_pin_write
// gpio_port_data_direction
// gpio_pin_data_direction

// gpio_pin_current_drive_select
// gpio_pin_resistor_configuration
	// gpio_pin_configure_pullup_res
	// gpio_pin_configure_pulldown_res
	// gpio_pin_configure_opendrain_res
// gpio_pin_digital_enable
// gpio_pin_analog_mode_select
// gpio_pin_config_alternate_function


// gpio_pin_interrupt_init

// gpio_pin_set_interrupt_sense_event
// gpio_pin_set_interrupt_mask
// gpio_pin_is_interrupt_raised
// gpio_pin_clear_interrupt












