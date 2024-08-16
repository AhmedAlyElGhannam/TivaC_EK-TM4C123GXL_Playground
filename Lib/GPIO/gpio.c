#include "gpio.h"

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
	_pin->pin_index = _pin_index;
}

sint8_t GPIO_pin_AFSEL_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}

	_pin->pad_config->AFSEL = _config;
	
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
	
	_pin->pad_config->DIR = _config;

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

	_pin->pad_config->DEN = _config;

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
	
	_pin->pad_config->RES = _config;

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
			else // disable
			{
			    CLR_BIT(GPIOODR_R_PORTA, _pin->pin_index);
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
			else // disable
			            {
			                CLR_BIT(GPIOODR_R_PORTB, _pin->pin_index);
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
			else // disable
			            {
			                CLR_BIT(GPIOODR_R_PORTC, _pin->pin_index);
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
			else // disable
			            {
			                CLR_BIT(GPIOODR_R_PORTD, _pin->pin_index);
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
			else // disable
			            {
			                CLR_BIT(GPIOODR_R_PORTE, _pin->pin_index);
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
			else // disable
			            {
			                CLR_BIT(GPIOODR_R_PORTF, _pin->pin_index);
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

	_pin->pad_config->DRX = _config;

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
				CLR_BIT(GPIODR2R_R_PORTF, _pin->pin_index); // sets ALL bits other than the cleared one (unintended behaviour)
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
	
	_pin->pad_config->SLR = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if ((_config == ENABLE) && (_pin->pad_config->DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTA, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTA, _pin->pin_index);
		break;
		
		case PORTB:
			if ((_config == ENABLE) && (_pin->pad_config->DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTB, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTB, _pin->pin_index);
		break;
		
		case PORTC:
			if ((_config == ENABLE) && (_pin->pad_config->DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTC, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTC, _pin->pin_index);
		break;
		
		case PORTD:
			if ((_config == ENABLE) && (_pin->pad_config->DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTD, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTD, _pin->pin_index);
		break;
		
		case PORTE:
			if ((_config == ENABLE) && (_pin->pad_config->DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTE, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTE, _pin->pin_index);
		break;
		
		case PORTF:
			if ((_config == ENABLE) && (_pin->pad_config->DRX == DRIVE_CURRENT_8MA))
				SET_BIT(GPIOSLR_R_PORTF, _pin->pin_index);
			else 
				CLR_BIT(GPIOSLR_R_PORTF, _pin->pin_index);
		break;
	}

out:
	return res;
}

static void GPIO_pin_assign_default_configs(struct GPIO_pin* _pin)
{
	_pin->pad_config->AFSEL = DISABLE;
	_pin->pad_config->DIR = OUTPUT;
	_pin->pad_config->DEN = ENABLE;
	_pin->pad_config->RES = DISABLE;
	_pin->pad_config->DRX = DRIVE_CURRENT_8MA;
	_pin->pad_config->SLR = ENABLE;
	
	_pin->interrupt_config->sense_trig = RISING_EDGE;
	_pin->interrupt_config->mask_state = MASKED;
}

sint8_t GPIO_pin_pad_config(struct GPIO_pin* _pin)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	res = GPIO_pin_AFSEL_config(_pin, _pin->pad_config->AFSEL);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_direction_config(_pin, _pin->pad_config->DIR);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_digital_config(_pin, _pin->pad_config->DEN);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_resistor_config(_pin, _pin->pad_config->RES);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_drive_current_config(_pin, _pin->pad_config->DRX);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_slew_rate_config(_pin, _pin->pad_config->SLR);
	if (res < 0)
	{
		goto out;
	}
	
out:
	return res;
}

sint8_t GPIO_pin_interrupt_sense_trig_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}

	_pin->interrupt_config->sense_trig = _config;
	
	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == RISING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTA, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTA, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTA, _pin->pin_index); // rising edge
			}
			else if (_config == FALLING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTA, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTA, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTA, _pin->pin_index); // falling edge
			}
			else if (_config == BOTH_EDGES) // aka any abrupt change
			{
				CLR_BIT(GPIOIS_R_PORTA, _pin->pin_index); // edge sensitive
				SET_BIT(GPIOIBE_R_PORTA, _pin->pin_index); // sensitive to both edges 
				// GPIOIEV_R_PORTA is ignored in this case
			}
			else if (_config == HIGH_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTA, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTA, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTA, _pin->pin_index); // high level
			}
			else if (_config == LOW_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTA, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTA, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTA, _pin->pin_index); // low level
			}
		break;
		
		case PORTB:
			if (_config == RISING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTB, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTB, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTB, _pin->pin_index); // rising edge
			}
			else if (_config == FALLING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTB, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTB, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTB, _pin->pin_index); // falling edge
			}
			else if (_config == BOTH_EDGES) // aka any abrupt change
			{
				CLR_BIT(GPIOIS_R_PORTB, _pin->pin_index); // edge sensitive
				SET_BIT(GPIOIBE_R_PORTB, _pin->pin_index); // sensitive to both edges 
				// GPIOIEV_R_PORTB is ignored in this case
			}
			else if (_config == HIGH_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTB, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTB, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTB, _pin->pin_index); // high level
			}
			else if (_config == LOW_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTB, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTB, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTB, _pin->pin_index); // low level
			}
		break;
		
		case PORTC:
			if (_config == RISING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTC, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTC, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTC, _pin->pin_index); // rising edge
			}
			else if (_config == FALLING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTC, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTC, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTC, _pin->pin_index); // falling edge
			}
			else if (_config == BOTH_EDGES) // aka any abrupt change
			{
				CLR_BIT(GPIOIS_R_PORTC, _pin->pin_index); // edge sensitive
				SET_BIT(GPIOIBE_R_PORTC, _pin->pin_index); // sensitive to both edges 
				// GPIOIEV_R_PORTC is ignored in this case
			}
			else if (_config == HIGH_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTC, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTC, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTC, _pin->pin_index); // high level
			}
			else if (_config == LOW_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTC, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTC, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTC, _pin->pin_index); // low level
			}
		break;
		
		case PORTD:
			if (_config == RISING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTD, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTD, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTD, _pin->pin_index); // rising edge
			}
			else if (_config == FALLING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTD, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTD, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTD, _pin->pin_index); // falling edge
			}
			else if (_config == BOTH_EDGES) // aka any abrupt change
			{
				CLR_BIT(GPIOIS_R_PORTD, _pin->pin_index); // edge sensitive
				SET_BIT(GPIOIBE_R_PORTD, _pin->pin_index); // sensitive to both edges 
				// GPIOIEV_R_PORTD is ignored in this case
			}
			else if (_config == HIGH_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTD, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTD, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTD, _pin->pin_index); // high level
			}
			else if (_config == LOW_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTD, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTD, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTD, _pin->pin_index); // low level
			}
		break;
		
		case PORTE:
			if (_config == RISING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTE, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTE, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTE, _pin->pin_index); // rising edge
			}
			else if (_config == FALLING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTE, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTE, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTE, _pin->pin_index); // falling edge
			}
			else if (_config == BOTH_EDGES) // aka any abrupt change
			{
				CLR_BIT(GPIOIS_R_PORTE, _pin->pin_index); // edge sensitive
				SET_BIT(GPIOIBE_R_PORTE, _pin->pin_index); // sensitive to both edges 
				// GPIOIEV_R_PORTE is ignored in this case
			}
			else if (_config == HIGH_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTE, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTE, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTE, _pin->pin_index); // high level
			}
			else if (_config == LOW_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTE, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTE, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTE, _pin->pin_index); // low level
			}
		break;
		
		case PORTF:
			if (_config == RISING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTF, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTF, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTF, _pin->pin_index); // rising edge
			}
			else if (_config == FALLING_EDGE)
			{
				CLR_BIT(GPIOIS_R_PORTF, _pin->pin_index); // edge sensitive
				CLR_BIT(GPIOIBE_R_PORTF, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTF, _pin->pin_index); // falling edge
			}
			else if (_config == BOTH_EDGES) // aka any abrupt change
			{
				CLR_BIT(GPIOIS_R_PORTF, _pin->pin_index); // edge sensitive
				SET_BIT(GPIOIBE_R_PORTF, _pin->pin_index); // sensitive to both edges 
				// GPIOIEV_R_PORTF is ignored in this case
			}
			else if (_config == HIGH_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTF, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTF, _pin->pin_index); // controlled by GPIOIEV 
				SET_BIT(GPIOIEV_R_PORTF, _pin->pin_index); // high level
			}
			else if (_config == LOW_LEVEL)
			{
				SET_BIT(GPIOIS_R_PORTF, _pin->pin_index); // level sensitive
				CLR_BIT(GPIOIBE_R_PORTF, _pin->pin_index); // controlled by GPIOIEV 
				CLR_BIT(GPIOIEV_R_PORTF, _pin->pin_index); // low level
			}
		break;
	}

out:
	return res;
}

sint8_t GPIO_pin_interrupt_mask_config(struct GPIO_pin* _pin, uint8_t _config)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	_pin->interrupt_config->mask_state = _config;

	switch (_pin->port_index)
	{
		case PORTA:
			if (_config == ENABLE)
				CLR_BIT(GPIOIM_R_PORTA, _pin->pin_index); // masked == no interrupt
			else if (_config == DISABLE)
				SET_BIT(GPIOIM_R_PORTA, _pin->pin_index); // not masked == interrupt
		break;
		
		case PORTB:
			if (_config == ENABLE)
				CLR_BIT(GPIOIM_R_PORTB, _pin->pin_index); // masked == no interrupt
			else if (_config == DISABLE)
				SET_BIT(GPIOIM_R_PORTB, _pin->pin_index); // not masked == interrupt
		break;
		
		case PORTC:
			if (_config == ENABLE)
				CLR_BIT(GPIOIM_R_PORTC, _pin->pin_index); // masked == no interrupt
			else if (_config == DISABLE)
				SET_BIT(GPIOIM_R_PORTC, _pin->pin_index); // not masked == interrupt
		break;
		
		case PORTD:
			if (_config == ENABLE)
				CLR_BIT(GPIOIM_R_PORTD, _pin->pin_index); // masked == no interrupt
			else if (_config == DISABLE)
				SET_BIT(GPIOIM_R_PORTD, _pin->pin_index); // not masked == interrupt
		break;
		
		case PORTE:
			if (_config == ENABLE)
				CLR_BIT(GPIOIM_R_PORTE, _pin->pin_index); // masked == no interrupt
			else if (_config == DISABLE)
				SET_BIT(GPIOIM_R_PORTE, _pin->pin_index); // not masked == interrupt
		break;
		
		case PORTF:
			if (_config == ENABLE)
				CLR_BIT(GPIOIM_R_PORTF, _pin->pin_index); // masked == no interrupt
			else if (_config == DISABLE)
				SET_BIT(GPIOIM_R_PORTF, _pin->pin_index); // not masked == interrupt
		break;
	}

out:
	return res;
}

static sint8_t GPIO_pin_interrupt_config(struct GPIO_pin* _pin)
{
	sint8_t res = ALL_OK;
	
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	res = GPIO_pin_interrupt_sense_trig_config(_pin, _pin->interrupt_config->sense_trig);
	if (res < 0)
	{
		goto out;
	}
	
	res = GPIO_pin_interrupt_mask_config(_pin, _pin->interrupt_config->mask_state);
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
	if ((_port_index < PORTA) || (_port_index > PORTF))
	{
		res = -EINVARG;
		goto out;
	}
	
	// check for passed pin index
	if (_pin_index >= PORTA_MAX_PIN)
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
	GPIO_set_pin_port_indices(_pin, _port_index, _pin_index);
	
	// set ISR to NULL until explicitly changed
	GPIO_set_pin_ISR(_pin, (GPIO_INTERRUPT_CALLBACK_FUNC)NULL);
	
	// by default, port is unlocked
	//GPIO_pin_config_lock(_pin, UNLOCK);
	
	// default pad and interrupt configuration for pin
	GPIO_pin_assign_default_configs(_pin);	
	
	// pin pad config
	//GPIO_pin_pad_config(_pin);
	
	// pin interrupt config
	//GPIO_pin_interrupt_config(_pin);
	
out:
	return res;
}

sint16_t GPIO_pin_digital_read(struct GPIO_pin* _pin)
{
	// check for passed pointer
	if (NULL == _pin)
	{
		return -EINVARG;
	}
	
	switch (_pin->port_index)
	{
		case PORTA:
			return (GET_BIT(GPIODATA_R_PORTA, _pin->pin_index));
		break;
		
		case PORTB:
			return (GET_BIT(GPIODATA_R_PORTB, _pin->pin_index));
		break;
		
		case PORTC:
			return (GET_BIT(GPIODATA_R_PORTC, _pin->pin_index));
		break;
		
		case PORTD:
			return (GET_BIT(GPIODATA_R_PORTD, _pin->pin_index));
		break;
		
		case PORTE:
			return (GET_BIT(GPIODATA_R_PORTE, _pin->pin_index));
		break;
		
		case PORTF:
			return (GET_BIT(GPIODATA_R_PORTF, _pin->pin_index));
		break;
	}

	return -EIO;
}

sint8_t GPIO_pin_digital_write(struct GPIO_pin* _pin, uint8_t _data)
{
	sint8_t res = ALL_OK;
	
	// check for passed pointer
	if (NULL == _pin)
	{
		res = -EINVARG;
		goto out;
	}
	
	switch (_pin->port_index)
	{
		case PORTA:
			if (_data == HIGH)
			{
				SET_BIT(GPIODATA_R_PORTA, _pin->pin_index);
			}
			else if (_data == LOW)
			{
				CLR_BIT(GPIODATA_R_PORTA, _pin->pin_index);
			}
		break;
		
		case PORTB:
			if (_data == HIGH)
			{
				SET_BIT(GPIODATA_R_PORTB, _pin->pin_index);
			}
			else if (_data == LOW)
			{
				CLR_BIT(GPIODATA_R_PORTB, _pin->pin_index);
			}
		break;
		
		case PORTC:
			if (_data == HIGH)
			{
				SET_BIT(GPIODATA_R_PORTC, _pin->pin_index);
			}
			else if (_data == LOW)
			{
				CLR_BIT(GPIODATA_R_PORTC, _pin->pin_index);
			}
		break;
		
		case PORTD:
			if (_data == HIGH)
			{
				SET_BIT(GPIODATA_R_PORTD, _pin->pin_index);
			}
			else if (_data == LOW)
			{
				CLR_BIT(GPIODATA_R_PORTD, _pin->pin_index);
			}
		break;
		
		case PORTE:
			if (_data == HIGH)
			{
				SET_BIT(GPIODATA_R_PORTE, _pin->pin_index);
			}
			else if (_data == LOW)
			{
				CLR_BIT(GPIODATA_R_PORTE, _pin->pin_index);
			}
		break;
		
		case PORTF:
			if (_data == HIGH)
			{
				SET_BIT(GPIODATA_R_PORTF, _pin->pin_index);
			}
			else if (_data == LOW)
			{
				CLR_BIT(GPIODATA_R_PORTF, _pin->pin_index);
			}
		break;
	}

out:
	return res;
}


bool GPIO_pin_is_interrupt_raised(struct GPIO_pin* _pin)
{
	bool state = false;
	
	switch(_pin->port_index)
	{
		case PORTA:
			if (GET_BIT(GPIORIS_R_PORTA, _pin->pin_index) || GET_BIT(GPIOMIS_R_PORTA, _pin->pin_index))
				state = true;
		break;
		
		case PORTB:
			if (GET_BIT(GPIORIS_R_PORTB, _pin->pin_index) || GET_BIT(GPIOMIS_R_PORTB, _pin->pin_index))
				state = true;
		break;
		
		case PORTC:
			if (GET_BIT(GPIORIS_R_PORTC, _pin->pin_index) || GET_BIT(GPIOMIS_R_PORTC, _pin->pin_index))
				state = true;
		break;
		
		case PORTD:
			if (GET_BIT(GPIORIS_R_PORTD, _pin->pin_index) || GET_BIT(GPIOMIS_R_PORTD, _pin->pin_index))
				state = true;
		break;
		
		case PORTE:
			if (GET_BIT(GPIORIS_R_PORTE, _pin->pin_index) || GET_BIT(GPIOMIS_R_PORTE, _pin->pin_index))
				state = true;
		break;
		
		case PORTF:
			if (GET_BIT(GPIORIS_R_PORTF, _pin->pin_index) || GET_BIT(GPIOMIS_R_PORTF, _pin->pin_index))
				state = true;
		break;
	}
	
	return state;
}


void GPIO_pin_clear_pin_interrupt(struct GPIO_pin* _pin)
{	
	// check for passed pointer
	if (NULL == _pin)
	{
		return;
	}
	
	switch (_pin->port_index)
	{
		case PORTA:
			SET_BIT(GPIOICR_R_PORTA, _pin->pin_index);
		break;
		
		case PORTB:
			SET_BIT(GPIOICR_R_PORTB, _pin->pin_index);
		break;
		
		case PORTC:
			SET_BIT(GPIOICR_R_PORTC, _pin->pin_index);
		break;
		
		case PORTD:
			SET_BIT(GPIOICR_R_PORTD, _pin->pin_index);
		break;
		
		case PORTE:
			SET_BIT(GPIOICR_R_PORTE, _pin->pin_index);
		break;
		
		case PORTF:
			SET_BIT(GPIOICR_R_PORTF, _pin->pin_index);
		break;
	}

	return;
}


// gpio_pin_analog_mode_select

// gpio_pin_pad_init (with flags)
// gpio_pin_interrupt_init (with flags)













