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
	Initialization
		1. Enable UART module (sysctl function)
		2. Enable GPIO port clock for chosen UART module (sysctl function)
		3. Enable GPIO AFSEL in order to be able to access/configure UART (gpio function)
		*also maybe need to set GPIO DEN (gpio function) --- actually it turns out I do!*
		4. Configure GPIO current drive & slew rate (gpio functions)
		5. Configure PMCn fields in GPIOCTL to assign UART signals to appropriate pins (need to implement a GPIO function for that + Check the table at page 1351 in datasheet)
	Configuration
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

enum UART_UARTClockSource
{
	SYS_CLK = 0x00,
	PIOSC = 0x05
};

enum UART_BaudRate
{
	BAUD_RATE_9600,
	BAUD_RATE_19200,
	BAUD_RATE_38400,
	BAUD_RATE_57600,
	BAUD_RATE_115200,
};

// field bit location in UARTCTL register
enum UART_ControlOptions
{
	UARTEN = 0,
	SIREN = 1,
	SIRLP = 2,
	SMART = 3,
	EOT = 4,
	HSE = 5,
	LBE = 7,
	TXE = 8,
	RXE = 9,
	RTS = 11,
	RTSEN = 14,
	CTSEN = 15
};

// start bit position for every field in UARTLCTL register
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

enum UART_WordLength
{
	WLEN_5BIT = 0x00,
	WLEN_6BIT = 0x01,
	WLEN_7BIT = 0x02,
	WLEN_8BIT = 0x03
};

enum UART_DataParity
{
	EVEN_PARITY,
	ODD_PARITY
};

enum UART_NumberOfStopBits
{
	ONE_BIT,
	TWO_BITS
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

struct UART_module
{
	struct UART_pins* pins;
		
	struct UART_line_control* line_ctl;
	
	struct UART_interrupt_config* interrupt_config;
	
	// UART_INTERRUPT_CALLBACK_FUNC uart_transmit_handler;
	// UART_INTERRUPT_CALLBACK_FUNC uart_receive_handler;
	// maybe some pointers for error handlers
	
	uint8_t module_index 		: 4;
	uint8_t module_port_index  	: 4;
};



void UART_ctrl_UARTEN_config(struct UART_module* _uart_module, uint8_t _config);

// uart_init
void UART_init();
// disable_uart
void UART_disable();
// enable_uart
void UART_enable();
// uart_clk_source
void UART_clk_source_config();
// set_baud_rate
void UART_baud_rate_config();
// line_control_config 
void UART_line_control_config();
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
#endif