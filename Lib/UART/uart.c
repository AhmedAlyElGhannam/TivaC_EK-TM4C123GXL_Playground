#include "UART/uart.c"

// disable_uart
void UART_disable(struct UART_module* _uart_module)
{
	UART_ctrl_UARTEN_config(struct UART_module* _uart_module, uint8_t _config);
	UART_ctrl_TXE_config(struct UART_module* _uart_module, uint8_t _config);
	UART_ctrl_RXE_config(struct UART_module* _uart_module, uint8_t _config);
}
// enable_uart
void UART_enable(struct UART_module* _uart_module)
{
	UART_ctrl_UARTEN_config(struct UART_module* _uart_module, uint8_t _config);
	UART_ctrl_TXE_config(struct UART_module* _uart_module, uint8_t _config);
	UART_ctrl_RXE_config(struct UART_module* _uart_module, uint8_t _config);	
}

sint8_t UART_init(struct UART_module* _uart_module, uint8_t _uart_index, uint8_t _pin_config)
{
	sint8_t res = ALL_OK;
	
	// check passed pointer
	if (_uart_module == NULL)
	{
		res = -EINVARG;
		goto out;
	}
	
	// check for passed index
	if ((_uart_index < UART0) || (_uart_index > UART7))
	{
		res = -EINVARG;
		goto out;
	}
	
	// check for passed pin config
	if ((_pin_config != PRIMARY) && (_pin_config != ALTERNATE))
	{
		res = -EINVARG;
		goto out;
	}
	
	// set uart module index
	_uart_module->module_index = _uart_index;
	
	// set uart pins
	switch (_uart_index)
	{
		case UART0:
			_uart_module->module_port_index = PORTA;
			GPIO_pin_init(_uart_module->pins->Tx, PORTA, PIN1); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTA, PIN0);	// setting Rx	
		break;
		
		case UART1: // PRIMARY || ALTERNATE
			if (_pin_config == PRIMARY)
			{
				_uart_module->module_port_index = PORTB;
				GPIO_pin_init(_uart_module->pins->Tx, PORTB, PIN1); // setting primary Tx
				GPIO_pin_init(_uart_module->pins->Rx, PORTB, PIN0); // setting primary Rx
			}
			else if (_pin_config == ALTERNATE)
			{
				_uart_module->module_port_index = PORTC;
				GPIO_pin_init(_uart_module->pins->Tx, PORTC, PIN5); // setting primary Tx
				GPIO_pin_init(_uart_module->pins->Rx, PORTC, PIN4); // setting primary Rx
			}
		break;
		
		case UART2:
			_uart_module->module_port_index = PORTD;
			GPIO_pin_init(_uart_module->pins->Tx, PORTD, PIN7); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTD, PIN6);	// setting Rx
		break;
		
		case UART3:
			_uart_module->module_port_index = PORTC;
			GPIO_pin_init(_uart_module->pins->Tx, PORTC, PIN7); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTC, PIN6);	// setting Rx
		break;
		
		case UART4: 
			_uart_module->module_port_index = PORTC;
			GPIO_pin_init(_uart_module->pins->Tx, PORTC, PIN5); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTC, PIN4);	// setting Rx
		break;
		
		case UART5:
			_uart_module->module_port_index = PORTE;
			GPIO_pin_init(_uart_module->pins->Tx, PORTE, PIN5); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTE, PIN4);	// setting Rx
		break;
		
		case UART6: 
			_uart_module->module_port_index = PORTD;
			GPIO_pin_init(_uart_module->pins->Tx, PORTD, PIN5); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTD, PIN4);	// setting Rx
		break;
		
		case UART7:
			_uart_module->module_port_index = PORTE;
			GPIO_pin_init(_uart_module->pins->Tx, PORTE, PIN1); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTE, PIN0);	// setting Rx
		break;
	}
	
	// enable gpio clk (in order to be able to configure port registers)
	SYSCTL_gpio_port_clk_config(_uart_module->module_port_index, ENABLE);
	
	// enable uart clk
	SYSCTL_uart_clk_config(_uart_module->module_index, ENABLE);
	
	// enable alt func
	GPIO_pin_AFSEL_config(_uart_module->pins->Tx, ENABLE);
	GPIO_pin_AFSEL_config(_uart_module->pins->Rx, ENABLE);
	
	// current drive
	GPIO_pin_drive_current_config(_uart_module->pins->Tx, DRIVE_CURRENT_8MA);
	GPIO_pin_drive_current_config(_uart_module->pins->Rx, DRIVE_CURRENT_8MA);
	
	// slew rate
	GPIO_pin_slew_rate_config(_uart_module->pins->Tx, ENABLE);
	GPIO_pin_slew_rate_config(_uart_module->pins->Rx, ENABLE);
	
	// set gpio port control for uart module pins
	GPIO_port_mux_control(_uart_module->module_index, _pin_config);
	
	// digital enable
	GPIO_pin_digital_config(_uart_module->pins->Tx, ENABLE);
	GPIO_pin_digital_config(_uart_module->pins->Rx, ENABLE);
	
	// disable uart module that was just defined (enable ONLY after config is done)
	UART_disable(_uart_module);
		
out:
	return res;
}


// uart_clk_divisor
void UART_clk_divisor();
// set_baud_rate


// this function should be able to tell the sys clk src
// for now, this enough just to make it abstract for future additions
uint8_t UART_get_clk_src(void)
{
	return SYS_CLK;
}

static void UART_baud_rate_PIOSC_calc(uint16_t _baud_rate, uint8_t* _baud_int, uint8_t* _baud_frac)
{
	switch (_baud_rate)
	{
		case BAUD_RATE_9600:
			baud_int = 104;
			baud_frac = 11;
		break;
		
		case BAUD_RATE_19200:
			baud_int = 52;
			baud_frac = 5;
		break;
		
		case BAUD_RATE_38400:
			baud_int = 26;
			baud_frac = 3;
		break;
		
		case BAUD_RATE_57600:
			baud_int = 17;
			baud_frac = 23;
		break;
		
		case BAUD_RATE_115200:
			baud_int = 8;
			baud_frac = 44;
		break;
	}
}

void UART_baud_rate_config(struct UART_module* _uart_module, uint16_t _baud_rate)
{
	// ignore null pointers
	if (_uart_module == NULL)
	{
		return;
	}
	
	// I will only account for the PIOSC 16MHz clk source
	uint8_t clk_src = UART_get_clk_src();
	
	// defining variables to hold int and frac part of baud rate
	uint8_t baud_int = 0;
	uint8_t baud_frac = 0;
	
	if (clk_src == SYS_CLK)
	{
		UART_baud_rate_PIOSC_calc(_baud_rate, &baud_int, &baud_frac); // calculate int and frac part for baud rate
		switch (_uart_module->module_index)
		{
			case UART0:
				UARTIBRD_R_UART0 = baud_int;
				UARTFBRD_R_UART0 = baud_frac;
			break;
			
			case UART1:
				UARTIBRD_R_UART1 = baud_int;
				UARTFBRD_R_UART1 = baud_frac;
			break;
			
			case UART2:
				UARTIBRD_R_UART2 = baud_int;
				UARTFBRD_R_UART2 = baud_frac;
			break;
			
			case UART3:
				UARTIBRD_R_UART3 = baud_int;
				UARTFBRD_R_UART3 = baud_frac;
			break;
			
			case UART4:
				UARTIBRD_R_UART4 = baud_int;
				UARTFBRD_R_UART4 = baud_frac;
			break;
			
			case UART5:
				UARTIBRD_R_UART5 = baud_int;
				UARTFBRD_R_UART5 = baud_frac;
			break;
			
			case UART6:
				UARTIBRD_R_UART6 = baud_int;
				UARTFBRD_R_UART6 = baud_frac;
			break;
			
			case UART7:
				UARTIBRD_R_UART7 = baud_int;
				UARTFBRD_R_UART7 = baud_frac;
			break;
		}
	}
	else if (clk_src == PIOSC)
	{
		// do nothing for now
	}
}


// uart_control_config // there are a lot of options here
void UART_ctrl_UARTEN_config(struct UART_module* _uart_module, uint8_t _config)
{
	if (_uart_module == NULL)
	{
		return;
	}
	
	switch (_uart_module->module_index)
	{
		case UART0:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART0, UARTEN) : CLR_BIT(UARTCTL_R_UART0, UARTEN);
		break;
		
		case UART1:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART1, UARTEN) : CLR_BIT(UARTCTL_R_UART1, UARTEN);
		break;
		
		case UART2:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART2, UARTEN) : CLR_BIT(UARTCTL_R_UART2, UARTEN);
		break;
		
		case UART3:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART3, UARTEN) : CLR_BIT(UARTCTL_R_UART3, UARTEN);
		break;
		
		case UART4:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART4, UARTEN) : CLR_BIT(UARTCTL_R_UART4, UARTEN);
		break;
		
		case UART5:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART5, UARTEN) : CLR_BIT(UARTCTL_R_UART5, UARTEN);
		break;
		
		case UART6:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART6, UARTEN) : CLR_BIT(UARTCTL_R_UART6, UARTEN);
		break;
		
		case UART7:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART7, UARTEN) : CLR_BIT(UARTCTL_R_UART7, UARTEN);
		break;
	}
}

void UART_ctrl_TXE_config(struct UART_module* _uart_module, uint8_t _config)
{
	if (_uart_module == NULL)
	{
		return;
	}
	
	switch (_uart_module->module_index)
	{
		case UART0:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART0, TXE) : CLR_BIT(UARTCTL_R_UART0, TXE);
		break;
		
		case UART1:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART1, TXE) : CLR_BIT(UARTCTL_R_UART1, TXE);
		break;
		
		case UART2:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART2, TXE) : CLR_BIT(UARTCTL_R_UART2, TXE);
		break;
		
		case UART3:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART3, TXE) : CLR_BIT(UARTCTL_R_UART3, TXE);
		break;
		
		case UART4:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART4, TXE) : CLR_BIT(UARTCTL_R_UART4, TXE);
		break;
		
		case UART5:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART5, TXE) : CLR_BIT(UARTCTL_R_UART5, TXE);
		break;
		
		case UART6:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART6, TXE) : CLR_BIT(UARTCTL_R_UART6, TXE);
		break;
		
		case UART7:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART7, TXE) : CLR_BIT(UARTCTL_R_UART7, TXE);
		break;
	}
}

void UART_ctrl_RXE_config(struct UART_module* _uart_module, uint8_t _config)
{
	if (_uart_module == NULL)
	{
		return;
	}
	
	switch (_uart_module->module_index)
	{
		case UART0:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART0, RXE) : CLR_BIT(UARTCTL_R_UART0, RXE);
		break;
		
		case UART1:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART1, RXE) : CLR_BIT(UARTCTL_R_UART1, RXE);
		break;
		
		case UART2:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART2, RXE) : CLR_BIT(UARTCTL_R_UART2, RXE);
		break;
		
		case UART3:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART3, RXE) : CLR_BIT(UARTCTL_R_UART3, RXE);
		break;
		
		case UART4:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART4, RXE) : CLR_BIT(UARTCTL_R_UART4, RXE);
		break;
		
		case UART5:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART5, RXE) : CLR_BIT(UARTCTL_R_UART5, RXE);
		break;
		
		case UART6:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART6, RXE) : CLR_BIT(UARTCTL_R_UART6, RXE);
		break;
		
		case UART7:
			_config == ENABLE ? SET_BIT(UARTCTL_R_UART7, RXE) : CLR_BIT(UARTCTL_R_UART7, RXE);
		break;
	}
}

void UART_clk_source_config(struct UART_module* _uart_module, uint8_t _config)
{
	if (_uart_module == NULL)
		return;
	
	if ((_config != SYS_CLK) && (_config != PIOSC))
		return;
	
	switch (_uart_module->module_index)
	{
		case UART0:
			SET_NIB_TO_VAL(UARTCC_R_UART0, NIB0, _config);
		break;
		
		case UART1:
			SET_NIB_TO_VAL(UARTCC_R_UART1, NIB0, _config);
		break;
		
		case UART2:
			SET_NIB_TO_VAL(UARTCC_R_UART2, NIB0, _config);
		break;
		
		case UART3:
			SET_NIB_TO_VAL(UARTCC_R_UART3, NIB0, _config);
		break;
		
		case UART4:
			SET_NIB_TO_VAL(UARTCC_R_UART4, NIB0, _config);
		break;
		
		case UART5:
			SET_NIB_TO_VAL(UARTCC_R_UART5, NIB0, _config);
		break;
		
		case UART6:
			SET_NIB_TO_VAL(UARTCC_R_UART6, NIB0, _config);
		break;
		
		case UART7:
			SET_NIB_TO_VAL(UARTCC_R_UART7, NIB0, _config);
		break;
	}
}

enum UART_LineControl
{
	SPS = 7,
	WLEN = 5,
	FEN = 4,
	STP2 = 3,
	EPS = 2,
	PEN = 1,
	BRK = 0
	
};

/*
		SPS (Stick Parity Select) -> = 0 to disable && other values dependent on other bits specified in datasheet
		WLEN (Word Length for Sent/Received Data) -> (5-8 bits)
		FEN (Enable FIFO) -> = 0 FIFOs are disabled (Character mode). The FIFOs become 1-byte-deep holding registers : = 1 transmit and receive FIFO buffers are enabled (FIFO mode)
		STP2 (Two Stop Bits Select) -> = 0 for one stop bit : = 1 for two stop bits
		EPS (Even Parity Select) -> = 0 for odd parity : = 1 for even parity
		PEN (Parity Enable) -> = 0 to disable parity : = 1 to enable parity
		BRK (UART Send Break) -> = 0 for normal use : *something!*
*/

sint8_t UART_set_word_len(struct UART_module* _uart_module, uint8_t _len)
{
	sint8_t res = ALL_OK;
	
	if (_uart_module == NULL)
	{
		res = -EINVARG;
		goto out;
	}
	
	WLEN_5BIT,
	WLEN_6BIT,
	WLEN_7BIT,
	WLEN_8BIT,
	WLEN_9BIT
	
	switch (_uart_module->module_index)
	{
		case UART0:
			// SET_BIT(UARTLCRH_R_UART0, WLEN0);
			// SET_BIT(UARTLCRH_R_UART0, WLEN);
		break;
		
		case UART1:
		break;
		
		case UART2:
		break;
		
		case UART3:
		break;
		
		case UART4:
		break;
		
		case UART5:
		break;
		
		case UART6:
		break;
		
		case UART7:
		break;;
	}
	
out:
	return res;
}

sint8_t UART_set_parity(struct UART_module* _uart_module, uint8_t _config)
{
	
}

sint8_t UART_set_no_of_stop_bits(struct UART_module* _uart_module, uint8_t _bit)
{
	
}


// uart_send_char // polling or interrupt
void UART_send_char(); // module + char

// uart_send_str // polling or interrupt
void UART_send_str(); // uses UART_send_char() to send char

// uart_receive_char // polling or interrupt
char UART_receive_char();
// uart_receive_str // polling or interrupt
char* UART_receive_str();