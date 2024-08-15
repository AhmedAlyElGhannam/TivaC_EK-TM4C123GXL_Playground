#ifndef GPIO_H
#define GPIO_H

#include "../config.h"
#include "../std_types.h"
#include "../tm4c123gh6pm.h"

/**
	Initialization & Configuration Steps
*/

/*---------------------------------------------*/

// enum for choices to make it look neat
enum GPIO_ReturnStatus // will leave it at that for now
{
	ALL_OK, 
	INCORRECT_PORT, 
	INCORRECT_PIN_NUM, 
	DIRECTION_ERROR,
	INCORRECT_MASK, 
	INCORRECT_VALUE, 
	INCORRECT_INTERRUPT_SENSE
};


enum GPIO_PortPadConfigLock
{
	UNLOCK = 0x4C4F434B, // value as stated under GPIOCR description
	LOCK = 0xFFFFFFFF // any value works
};

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
    PORTA_INDEX = 0,
    PORTB_INDEX = 1,
    PORTC_INDEX = 2,
    PORTD_INDEX = 3,
    PORTE_INDEX = 4,
	PORTF_INDEX = 5
};

enum GPIO_ResistorType
{
	PULL_UP_RESISTOR,
	PULL_DOWN_RESISTOR,
	OPEN_DRAIN_RESISTOR 
};

enum GPIO_CurrentDrive
{
	DRIVE_CURRENT_2MA,
	DRIVE_CURRENT_4MA,
	DRIVE_CURRENT_8MA
};

enum GPIO_InterruptSense
{
	RISING_EDGE,
	FALLING_EDGE,
	HIGH_LEVEL,
	LOW_LEVEL,
	LOW_LEVEL_FALLING_EDGE,
	HIGH_LEVEL_RISING_EDGE
};

enum GPIO_InterruptState
{
	MASKED,
	NOT_MASKED
};

typedef void(*GPIO_INTERRUPT_CALLBACK_FUNC)(void);

// struct for gpio pad config
struct GPIO_pad_config
{
	uint8_t AFSEL; 	// alternate function select
	uint8_t DIR; 	// data direction
	uint8_t DEN; 	// digital enable
	uint8_t RES; 	// pull-up || pull-down || open-drain
	uint8_t DRX; 	// 2mA || 4mA || 8mA current drive 
	uint8_t SLR;	// slew rate (only for 8mA current drive)
};

// struct for gpio interrupt config
struct GPIO_interrupt_config
{
	uint8_t sense_trig; // edge-triggered (rising/falling) || level-triggered (high/low)
	uint8_t state; // masked || not masked
	GPIO_INTERRUPT_CALLBACK_FUNC callback_func; // callback function
};

// struct for gpio pin
struct GPIO_pin
{
	struct GPIO_pad_config* pad_config; // pointer to pad config for this pin
	struct GPIO_interrupt_config* interrupt_config; // pointer to interrupt config for this pin
	uint8_t port; // index for port this pin belongs to
	uint8_t pin; // index for pin
};

// struct for gpio port 
struct GPIO_port
{
	struct GPIO_pin* pins[8]; // array of pointers to pins
	uint32_t lock; // lock state for this port
};

#endif