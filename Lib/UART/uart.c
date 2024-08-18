#include "UART/uart.c"

struct UART_line_control
{
	uint8_t SPS		: 1; // Stick Parity Select
	uint8_t WLEN	: 2; // Word Length for Sent/Received Data
	uint8_t FEN 	: 1; // Enable FIFO
	uint8_t STP2 	: 1; // Two Stop Bits Select
	uint8_t EPS 	: 1; // Even Parity Select
	uint8_t PEN 	: 1; // Parity Enable
	uint8_t BRK 	: 1; // UART Send Break
};

/*
sint8_t UART_line_control_config(struct UART_module* _uart_module)
{
	
}
*/

// uart_clk_source
void UART_clk_source_config();
// set_baud_rate
void UART_baud_rate_config();
// uart_control_config // there are a lot of options here
void UART_control_config();



// disable uart
void UART_disable(struct UART_module* _uart_module)
{
	SYSCTL_uart_config(_uart_module->module_index, DISABLE);
}

// enable uart
void UART_enable(struct UART_module* _uart_module)
{
	SYSCTL_uart_config(_uart_module->module_index, ENABLE);
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
			GPIO_pin_init(_uart_module->pins->Tx, PORTA, PIN1); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTA, PIN0);	// setting Rx	
		break;
		
		case UART1: // PRIMARY || ALTERNATE
			if (_pin_config == PRIMARY)
			{
				GPIO_pin_init(_uart_module->pins->Tx, PORTB, PIN1); // setting primary Tx
				GPIO_pin_init(_uart_module->pins->Rx, PORTB, PIN0); // setting primary Rx
			}
			else if (_pin_config == ALTERNATE)
			{
				GPIO_pin_init(_uart_module->pins->Tx, PORTC, PIN5); // setting primary Tx
				GPIO_pin_init(_uart_module->pins->Rx, PORTC, PIN4); // setting primary Rx
			}
		break;
		
		case UART2:
			GPIO_pin_init(_uart_module->pins->Tx, PORTD, PIN7); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTD, PIN6);	// setting Rx
		break;
		
		case UART3:
			GPIO_pin_init(_uart_module->pins->Tx, PORTC, PIN7); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTC, PIN6);	// setting Rx
		break;
		
		case UART4: 
			GPIO_pin_init(_uart_module->pins->Tx, PORTC, PIN5); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTC, PIN4);	// setting Rx
		break;
		
		case UART5:
			GPIO_pin_init(_uart_module->pins->Tx, PORTE, PIN5); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTE, PIN4);	// setting Rx
		break;
		
		case UART6: 
			GPIO_pin_init(_uart_module->pins->Tx, PORTD, PIN5); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTD, PIN4);	// setting Rx
		break;
		
		case UART7:
			GPIO_pin_init(_uart_module->pins->Tx, PORTE, PIN1); // setting Tx pin
			GPIO_pin_init(_uart_module->pins->Rx, PORTE, PIN0);	// setting Rx
		break;
	}
	
	// set gpio port control for uart module pins (will implement this function)
	
	
	// disable uart module that was just defined (enable ONLY after config is done)
	UART_disable(_uart_module);
		
out:
	return res;
}

// uart_clk_source
sint8_t UART_clk_source_config(struct UART_module* _uart_module)
{
	sint8_t res = ALL_OK;
	
	// check passed pointer
	if (_uart_module == NULL)
	{
		res = -EINVARG;
		goto out;
	}
	
	switch (_uart_module->module_index)
	{
		case UART0:
			// UARTCC_R_UART0
		break;
		
		case UART1:
			// UARTCC_R_UART0
		break;
		
		case UART2:
			// UARTCC_R_UART0
		break;
		
		case UART3:
			// UARTCC_R_UART0
		break;
		
		case UART4:
			// UARTCC_R_UART0
		break;
		
		case UART5:
			// UARTCC_R_UART0
		break;
		
		case UART6:
			// UARTCC_R_UART0
		break;
		
		case UART7:
			// UARTCC_R_UART0
		break;
	}
	
out:
	return res;
}
// uart_clk_divisor
void UART_clk_divisor();
// set_baud_rate
/*
@PIOSC aka 16MHz	
	9600 baud: IBRD = 104, FBRD = 11
	19200 baud: IBRD = 52, FBRD = 5
	38400 baud: IBRD = 26, FBRD = 3
	57600 baud: IBRD = 17, FBRD = 23
	115200 baud: IBRD = 8, FBRD = 44
*/
void UART_baud_rate_config();
// uart 9-bit mode
void UART_9bit_mode_config();
// uart_control_config // there are a lot of options here
void UART_control_config();
// uart_interrupt_config
void UART_interrupt_config();
// uart_interrupt_enable/disable + isr_set?!
void UART_interrupt_enable();
void UART_interrupt_disable();
// uart_dma_config
void UART_DMA_config();

// error flag checkers
bool UART_is_causing_overrun_error();
bool UART_is_causing_break_error();
bool UART_is_causing_parity_error();
bool UART_is_causing_framing_error();

// uart_send_char // polling or interrupt
void UART_send_char(); // module + char

// uart_send_str // polling or interrupt
void UART_send_str(); // uses UART_send_char() to send char

// uart_receive_char // polling or interrupt
char UART_receive_char();
// uart_receive_str // polling or interrupt
char* UART_receive_str();