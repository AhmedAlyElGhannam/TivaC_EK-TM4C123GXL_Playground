#ifndef UART_H
#define UART_H

#include "config.h"
#include "std_types.h"
#include "status.h"
#include "bit_op.h"
#include "tm4c123gh6pm.h"
#include "SYSCTL/sysctl.h"
#include "GPIO/gpio.h"

/**
	Initialization & Configuration
		1. Enable UART module (sysctl function)
		2. Enable GPIO port clock for chosen UART module (sysctl function)
		3. Enable GPIO AFSEL in order to be able to access/configure UART (gpio function)
		*also maybe need to set GPIO DEN (gpio function)*
		4. Configure GPIO current drive & slew rate (gpio functions)
		5. Configure PMCn fields in GPIOCTL to assign UART signals to appropriate pins (need to implement a GPIO function for that + Check the table at page 1351 in datasheet)
	Using UART
		// DISABLE UART
		1. Configure clk source
		2. Configure Baud rate
		3. Configure line control
		4. Configure interrupts
		5. Configure DMA
		// ENABLE UART

*/

typedef void(*UART_INTERRUPT_CALLBACK_FUNC)(void); // pointer to ISR

#define UART_MODULE_COUNT	8

enum UART_UARTIndex
{
	UART0,
	UART1,
	UART2,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7
};

enum UART_UARTPrimaryOrAlternate // for choosing pins of UART
{
	PRIMARY,
	ALTERNATE
};

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

struct UART_interrupt_config
{
	uint16_t IFLSEL_T 	: 3; // Transmitter Interrupt FIFO Level Select
	uint16_t IFLSEL_R 	: 3; // Receiver Interrupt FIFO Level Select
	uint16_t NINE_BITIM : 1; // 9-Bit Mode Interrupt Mask
	uint16_t OEIM		: 1; // UART Overrun Error Interrupt Mask
	uint16_t PEIM 		: 1; // UART Break Error Interrupt Mask
	uint16_t BEIM 		: 1; // UART Parity Error Interrupt Mask
	uint16_t FEIM 		: 1; // UART Framing Error Interrupt Mask
	uint16_t RTIM 		: 1; // UART Receive Time-Out Interrupt Mask
	uint16_t TXIM 		: 1; // UART Transmit Interrupt Mask
	uint16_t RXIM 		: 1; // UART Receive Interrupt Mask
	uint16_t CTSIM 		: 1; // UART Clear To Sent Modem Interrupt Mask
}

struct UART_pins
{
	struct GPIO_pin* Tx;
	struct GPIO_pin* Rx;
};

// make an array out of deez
struct UART_module_index
{
	uint16_t module_port  	 : 3;
	uint16_t module_tx 		 : 3;
	uint16_t module_rx 		 : 3;
};

struct UART_module
{
	struct UART_pins* pins;
	
	union // anonymous union to save memory
	{
		struct UART_module_index* main_index;
		struct UART_module_index* alt_index;
	};
	
	struct UART_module_index* index;
	
	struct UART_line_control* line_ctl;
	
	struct UART_interrupt_config* interrupt_config;
	
	UART_INTERRUPT_CALLBACK_FUNC uart_transmit_handler;
	UART_INTERRUPT_CALLBACK_FUNC uart_receive_handler;
	// maybe some pointers for error handlers
	
	uint8_t module_index;
};


// uart_init
// disable_uart
// enable_uart
// uart_clk_source
// set_baud_rate
// line_control_config 
// uart_control_config // there are a lot of options here
// uart_interrupt_config
// uart_interrupt_enable/disable + isr_set?!
// uart_dma_config

// error flag checkers

// uart_send_char // polling or interrupt
// uart_send_str // polling or interrupt

// uart_receive_char // polling or interrupt
// uart_receive_str // polling or interrupt

#endif