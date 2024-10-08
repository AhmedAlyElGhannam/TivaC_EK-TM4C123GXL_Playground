#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t; 

typedef float float32_t;  // float/double can only be signed
typedef double float64_t; // float/double can only be signed

typedef enum 
{
	true = 1,
	false = 0
} bool;

enum LogicLevel
{
    LOW = 0,
    HIGH = 1
};

enum DataDirection
{
    INPUT = 0,
    OUTPUT = 1
};

enum FeatureState
{
	DISABLE = 0,
	ENABLE = 1
};

enum PinIndex
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

enum PortIndex
{
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
    PORTF = 5
};

enum CommProtocolModules
{
	UART0,
	UART1,
	UART2,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	SSI,
	I2C,
	CAN
};

enum PrimaryOrAlternatePinConfig // for choosing pin layout of CommProtocolModules
{
	PRIMARY,
	ALTERNATE
};

enum GPIOPortMuxControl
{
	PMC0,
	PMC1,
	PMC2,
	PMC3,
	PMC4,
	PMC5,
	PMC6,
	PMC7
};

enum NibbleIndex
{
	NIB0,
	NIB1,
	NIB2,
	NIB3,
	NIB4,
	NIB5,
	NIB6,
	NIB7
};

#define NULL ((void*)0)

#endif
