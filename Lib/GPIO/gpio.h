#ifndef GPIO_H
#define GPIO_H

#include "config.h"
#include "std_types.h"
#include "status.h"
#include "bit_op.h"
#include "tm4c123gh6pm.h"

/**
	Initialization & Configuration Steps
		1. Enable Port Clock for Appropriate Pin(s)(not implemented yet)
		2. Set Pin(s) Direction
		3. Configure AFSEL for Pin
		4. Set Current Drive Strength
		5. Configure Pin Resistor (PU/PD/OD) + Slew Rate
		6. Either Enable Digital or Analog Functionality of Pin
		7. Configure Pin Interrupt
		8. Configure Lock on Port
*/

/*---------------------------------------------*/

enum GPIO_PortPadConfigLock
{
	UNLOCK = 0x4C4F434B, // value as stated under GPIOCR description
	LOCK = 0xFFFFFFFF // any value works
};

// PA0-7 && PB0-7 && PC0-7 && PC0-7 && PE0-5 && PF0-4
enum GPIO_PortMaxPinCount 
{
	PORTA_MAX_PIN = 8,
	PORTB_MAX_PIN = 8,
	PORTC_MAX_PIN = 8,
	PORTD_MAX_PIN = 8,
	PORTE_MAX_PIN = 6,
	PORTF_MAX_PIN = 5
};

enum GPIO_ResistorType
{
	PULL_UP_RESISTOR = 5,
	PULL_DOWN_RESISTOR,
	OPEN_DRAIN_RESISTOR 
};

enum GPIO_CurrentDrive
{
	DRIVE_CURRENT_2MA = 3,
	DRIVE_CURRENT_4MA,
	DRIVE_CURRENT_8MA
};

enum GPIO_InterruptSense
{
	RISING_EDGE = 2,
	FALLING_EDGE,
	BOTH_EDGES,
	HIGH_LEVEL,
	LOW_LEVEL
};

enum GPIO_InterruptState
{
	MASKED,
	NOT_MASKED
};

/*---------------------------------------------*/

typedef void(*GPIO_INTERRUPT_CALLBACK_FUNC)(void); // pointer to ISR

/*---------------------------------------------*/

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
	uint8_t mask_state; // masked || not masked
};

// struct for gpio pin
struct GPIO_pin
{
	struct GPIO_pad_config* pad_config; // pointer to pad config for this pin
	struct GPIO_interrupt_config* interrupt_config; // pointer to interrupt config for this pin
	uint8_t port_index; // index for port this pin belongs to
	uint8_t pin_index; // index for pin
};

/*---------------------------------------------*/



sint8_t GPIO_pin_init(struct GPIO_pin* _pin, uint8_t _port_index, uint8_t _pin_index);

sint8_t GPIO_pin_config_lock(struct GPIO_pin* _pin, uint32_t _lock);

sint8_t GPIO_pin_pad_config(struct GPIO_pin* _pin);
sint8_t GPIO_pin_AFSEL_config(struct GPIO_pin* _pin, uint8_t _config);
sint8_t GPIO_pin_direction_config(struct GPIO_pin* _pin, uint8_t _config);
sint8_t GPIO_pin_digital_config(struct GPIO_pin* _pin, uint8_t _config);
sint8_t GPIO_pin_resistor_config(struct GPIO_pin* _pin, uint8_t _config);
sint8_t GPIO_pin_drive_current_config(struct GPIO_pin* _pin, uint8_t _config);
sint8_t GPIO_pin_slew_rate_config(struct GPIO_pin* _pin, uint8_t _config);

sint16_t GPIO_pin_digital_read(struct GPIO_pin* _pin);
sint8_t GPIO_pin_digital_write(struct GPIO_pin* _pin, uint8_t _data);

sint8_t GPIO_set_pin_ISR(struct GPIO_pin* _pin, GPIO_INTERRUPT_CALLBACK_FUNC _isr);
sint8_t GPIO_pin_interrupt_sense_trig_config(struct GPIO_pin* _pin, uint8_t _config);
sint8_t GPIO_pin_interrupt_mask_config(struct GPIO_pin* _pin, uint8_t _config);
bool GPIO_pin_is_interrupt_raised(struct GPIO_pin* _pin);
void GPIO_pin_clear_pin_interrupt(struct GPIO_pin* _pin);

#endif
