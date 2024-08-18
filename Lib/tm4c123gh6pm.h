#ifndef TM4C123GH6PM_H
#define TM4C123GH6PM_H

#include "config.h"

/**
	Putting this here cuz I will need to look it up EVERY. SINGLE. TIME.

	RC: Reading via software clears it
	RO: Read-only via software
	RW: Readable and Writable via software
	RWC: Readable and Writable via software BUT a Write clears it
	RW1C: Readable and Writable via software BUT Writing 0 has no effect and Writing 1 clears the bit
	RW1S: Readable and Writable via software BUT Writing 0 is ignored (writing 1 is normal)
	W1C: Writing 0 is ignored BUT writing 1 clears that bit

*/



/*----------GPIO START----------*/

// defining port base address based on configured bus in config.h
#if (GPIO_PORT_BUS == APB_BUS)

	#define GPIO_PORTA_BASE		(0x40004000)
	#define GPIO_PORTB_BASE		(0x40005000)
	#define GPIO_PORTC_BASE		(0x40006000)
	#define GPIO_PORTD_BASE		(0x40007000)
	#define GPIO_PORTE_BASE		(0x40024000)
	#define GPIO_PORTF_BASE		(0x40025000)

#elif (GPIO_PORT_BUS == AHB_BUS)

	#define GPIO_PORTA_BASE		(0x40058000)
	#define GPIO_PORTB_BASE		(0x40059000)
	#define GPIO_PORTC_BASE     (0x4005A000)
	#define GPIO_PORTD_BASE     (0x4005B000)
	#define GPIO_PORTE_BASE     (0x4005C000)
	#define GPIO_PORTF_BASE     (0x4005D000)

#endif

/**
	@Name: GPIO Data Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DATA 		(RW) (0x00 Upon Reset)

*/
#define GPIO_DATA_OFFSET		(0x3FC)
#define GPIODATA_R_PORTA		(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DATA_OFFSET))
#define GPIODATA_R_PORTB		(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DATA_OFFSET))
#define GPIODATA_R_PORTC		(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DATA_OFFSET))
#define GPIODATA_R_PORTD		(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DATA_OFFSET))
#define GPIODATA_R_PORTE		(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DATA_OFFSET))
#define GPIODATA_R_PORTF		(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DATA_OFFSET))


/**
	@Name: GPIO Data Direction Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DIR 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin is an Output
		Writing 0 -> Corresponding Pin is an Input

*/
#define GPIO_DIR_OFFSET			(0x400)
#define GPIODIR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DIR_OFFSET))
#define GPIODIR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DIR_OFFSET))
#define GPIODIR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DIR_OFFSET))
#define GPIODIR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DIR_OFFSET))
#define GPIODIR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DIR_OFFSET))
#define GPIODIR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DIR_OFFSET))


/**
	@Name: GPIO Interrupt Sense Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> IS 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin is Level-Sensitive (High & Low)
		Writing 0 -> Corresponding Pin is Edge-Sensitive (Rising & Falling)

*/
#define GPIO_IS_OFFSET			(0x404)
#define GPIOIS_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_IS_OFFSET))
#define GPIOIS_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_IS_OFFSET))
#define GPIOIS_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_IS_OFFSET))
#define GPIOIS_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_IS_OFFSET))
#define GPIOIS_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_IS_OFFSET))
#define GPIOIS_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_IS_OFFSET))


/**
	@Name: GPIO Interrupt Both Edges Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> IBE 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin is Sensitive to Both Edges (Rising & Falling)
		Writing 0 -> Interrupt Generation is Controlled by GPIOIEV Register

*/
#define GPIO_IBE_OFFSET			(0x408)
#define GPIOIBE_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_IBE_OFFSET))
#define GPIOIBE_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_IBE_OFFSET))
#define GPIOIBE_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_IBE_OFFSET))
#define GPIOIBE_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_IBE_OFFSET))
#define GPIOIBE_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_IBE_OFFSET))
#define GPIOIBE_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_IBE_OFFSET))


/**
	@Name: GPIO Interrupt Event Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> IEV 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin Triggers an Interrupt on Rising-Edge OR High-Level
		Writing 0 -> Corresponding Pin Triggers an Interrupt on Falling-Edge OR Low-Level

*/
#define GPIO_IEV_OFFSET			(0x40C)
#define GPIOIEV_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_IEV_OFFSET))
#define GPIOIEV_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_IEV_OFFSET))
#define GPIOIEV_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_IEV_OFFSET))
#define GPIOIEV_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_IEV_OFFSET))
#define GPIOIEV_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_IEV_OFFSET))
#define GPIOIEV_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_IEV_OFFSET))


/**
	@Name: GPIO Interrupt Mask Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> IME 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin's Interrupt is not Masked (Enabled) and Sent to Interrupt Controller
		Writing 0 -> Corresponding Pin's Interrupt is Masked (Disabled)

*/
#define GPIO_IM_OFFSET			(0x410)
#define GPIOIM_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_IM_OFFSET))
#define GPIOIM_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_IM_OFFSET))
#define GPIOIM_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_IM_OFFSET))
#define GPIOIM_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_IM_OFFSET))
#define GPIOIM_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_IM_OFFSET))
#define GPIOIM_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_IM_OFFSET))


/**
	@Name: GPIO Raw Interrupt Status Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> RIS 		(RO) (0x00 Upon Reset)
	@Value:
		Reading 1 -> Corresponding Pin Raised an Interrupt
		Reading 0 -> Corresponding Pin Did not Raise an Interrupt

*/
#define GPIO_RIS_OFFSET			(0x414)
#define GPIORIS_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_RIS_OFFSET))
#define GPIORIS_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_RIS_OFFSET))
#define GPIORIS_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_RIS_OFFSET))
#define GPIORIS_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_RIS_OFFSET))
#define GPIORIS_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_RIS_OFFSET))
#define GPIORIS_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_RIS_OFFSET))


/**
	@Name: GPIO Masked Interrupt Status Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> MIS 		(R0) (0x00 Upon Reset)
	@Value:
		Reading 1 -> Corresponding Pin Triggered an Interrupt to the Interrupt Controller
		Reading 0 -> Corresponding Pin Has its Interrupt Masked OR Did not Raise an Interrupt

*/
#define GPIO_MIS_OFFSET			(0x418)
#define GPIOMIS_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_MIS_OFFSET))
#define GPIOMIS_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_MIS_OFFSET))
#define GPIOMIS_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_MIS_OFFSET))
#define GPIOMIS_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_MIS_OFFSET))
#define GPIOMIS_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_MIS_OFFSET))
#define GPIOMIS_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_MIS_OFFSET))


/**
	@Name: GPIO Interrupt Clear Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> IC 		(W1C) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin Interrupt is Cleared
		Writing 0 -> Corresponding Pin Interrupt is Unaffected

*/
#define GPIO_ICR_OFFSET			(0x41C)
#define GPIOICR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_ICR_OFFSET))
#define GPIOICR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_ICR_OFFSET))
#define GPIOICR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_ICR_OFFSET))
#define GPIOICR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_ICR_OFFSET))
#define GPIOICR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_ICR_OFFSET))
#define GPIOICR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_ICR_OFFSET))

/**
	@Name: GPIO Alternate Function Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> AFSEL 	(RW)
	@Value:
		Writing 1 -> Corresponding Pin Functions as the Designated Alternate Function
		Writing 0 -> Corresponding Pin Functions as GPIO and is Controlled by GPIO Registers
*/
#define GPIO_AFSEL_OFFSET			(0x420)
#define GPIOAFSEL_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_AFSEL_OFFSET))
#define GPIOAFSEL_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_AFSEL_OFFSET))
#define GPIOAFSEL_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_AFSEL_OFFSET))
#define GPIOAFSEL_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_AFSEL_OFFSET))
#define GPIOAFSEL_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_AFSEL_OFFSET))
#define GPIOAFSEL_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_AFSEL_OFFSET))


/**
	@Name: GPIO 2-mA Drive Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DRV2 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin Drives 2-mA
		Writing 0 -> Corresponding Pin has its Drive controlled by GPIODR4R OR GPIODR8R
*/
#define GPIO_DR2R_OFFSET			(0x500)
#define GPIODR2R_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DR2R_OFFSET))
#define GPIODR2R_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DR2R_OFFSET))
#define GPIODR2R_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DR2R_OFFSET))
#define GPIODR2R_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DR2R_OFFSET))
#define GPIODR2R_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DR2R_OFFSET))
#define GPIODR2R_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DR2R_OFFSET))


/**
	@Name: GPIO 4-mA Drive Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DRV4 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin Drives 4-mA
		Writing 0 -> Corresponding Pin has its Drive controlled by GPIODR2R OR GPIODR8R
*/
#define GPIO_DR4R_OFFSET			(0x504)
#define GPIODR4R_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DR4R_OFFSET))
#define GPIODR4R_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DR4R_OFFSET))
#define GPIODR4R_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DR4R_OFFSET))
#define GPIODR4R_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DR4R_OFFSET))
#define GPIODR4R_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DR4R_OFFSET))
#define GPIODR4R_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DR4R_OFFSET))


/**
	@Name: GPIO 8-mA Drive Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DRV8 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin Drives 8-mA
		Writing 0 -> Corresponding Pin has its Drive controlled by GPIODR2R OR GPIODR4R
*/
#define GPIO_DR8R_OFFSET			(0x508)
#define GPIODR8R_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DR8R_OFFSET))
#define GPIODR8R_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DR8R_OFFSET))
#define GPIODR8R_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DR8R_OFFSET))
#define GPIODR8R_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DR8R_OFFSET))
#define GPIODR8R_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DR8R_OFFSET))
#define GPIODR8R_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DR8R_OFFSET))


/**
	@Name: GPIO Open Drain Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> ODE 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin is Configured as Open Drain
		Writing 0 -> Corresponding Pin is not Configured as Open Drain
*/
#define GPIO_ODR_OFFSET			(0x50C)
#define GPIOODR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_ODR_OFFSET))
#define GPIOODR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_ODR_OFFSET))
#define GPIOODR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_ODR_OFFSET))
#define GPIOODR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_ODR_OFFSET))
#define GPIOODR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_ODR_OFFSET))
#define GPIOODR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_ODR_OFFSET))


/**
	@Name: GPIO Pull-Up Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PUE 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin's weak Pull-Up Resistor is Enabled
		Writing 0 -> Corresponding Pin's weak Pull-Up Resistor is Disabled
*/
#define GPIO_PUR_OFFSET			(0x510)
#define GPIOPUR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PUR_OFFSET))
#define GPIOPUR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PUR_OFFSET))
#define GPIOPUR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PUR_OFFSET))
#define GPIOPUR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PUR_OFFSET))
#define GPIOPUR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PUR_OFFSET))
#define GPIOPUR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PUR_OFFSET))


/**
	@Name: GPIO Pull-Down Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PDE 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin's weak Pull-Down Resistor is Enabled
		Writing 0 -> Corresponding Pin's weak Pull-Down Resistor is Disabled
*/
#define GPIO_PDR_OFFSET			(0x514)
#define GPIOPDR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PDR_OFFSET))
#define GPIOPDR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PDR_OFFSET))
#define GPIOPDR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PDR_OFFSET))
#define GPIOPDR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PDR_OFFSET))
#define GPIOPDR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PDR_OFFSET))
#define GPIOPDR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PDR_OFFSET))


/**
	@Name: GPIO Slew Rate Control Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> SRL 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin's Slew Rate Control is Enabled (8mA Drive ONLY)
		Writing 0 -> Corresponding Pin's Slew Rate Control is Disabled (8mA Drive ONLY)
*/
#define GPIO_SLR_OFFSET			(0x518)
#define GPIOSLR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_SLR_OFFSET))
#define GPIOSLR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_SLR_OFFSET))
#define GPIOSLR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_SLR_OFFSET))
#define GPIOSLR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_SLR_OFFSET))
#define GPIOSLR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_SLR_OFFSET))
#define GPIOSLR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_SLR_OFFSET))


/**
	@Name: GPIO Digital Enable Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DEN 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin's Digital Functions are Enabled (8mA Drive ONLY)
		Writing 0 -> Corresponding Pin's Digital Functions are Disabled (8mA Drive ONLY)
*/
#define GPIO_DEN_OFFSET			(0x51C)
#define GPIODEN_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DEN_OFFSET))
#define GPIODEN_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DEN_OFFSET))
#define GPIODEN_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DEN_OFFSET))
#define GPIODEN_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DEN_OFFSET))
#define GPIODEN_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DEN_OFFSET))
#define GPIODEN_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DEN_OFFSET))


/**
	@Name: GPIO Lock Register
	@Layout:
		bit31:bit0 -> LOCK 	    (RW)
	@Value:
		Writing 0x4C4F434B -> Unlocks GPIOCR Register for Write Access
		Writing ANY other value -> Reapplies the Lock
		Reading either returns:
			1 -> indicates GPIOCR register is locked and cannot be modified
			0 -> indicates GPIOCR register is unlocked and can be modified
*/
#define GPIO_LOCK_OFFSET			(0x520)
#define GPIOLOCK_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_LOCK_OFFSET))
#define GPIOLOCK_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_LOCK_OFFSET))
#define GPIOLOCK_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_LOCK_OFFSET))
#define GPIOLOCK_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_LOCK_OFFSET))
#define GPIOLOCK_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_LOCK_OFFSET))
#define GPIOLOCK_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_LOCK_OFFSET))


/**
	@Name: GPIO Commit Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> CR 	    (RW)
	@Value:
		Writing 1 -> Corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, and GPIODEN bits cannot be Written
		Writing 0 -> Corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, and GPIODEN bits can be Written
*/
#define GPIO_CR_OFFSET			(0x524)
#define GPIOCR_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_CR_OFFSET))
#define GPIOCR_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_CR_OFFSET))
#define GPIOCR_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_CR_OFFSET))
#define GPIOCR_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_CR_OFFSET))
#define GPIOCR_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_CR_OFFSET))
#define GPIOCR_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_CR_OFFSET))


/**
	@Name: GPIO Analog Mode Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> GPIOAMSEL (RW)
	@Value:
		Writing 1 -> Corresponding Pin's Analog Functions are Enabled and the Isolation ?! is Disabled
		Writing 0 -> Corresponding Pin's Analog Functions are Disabled and the Isolation ?! is Enabled
*/
#define GPIO_AMSEL_OFFSET			(0x528)
#define GPIOAMSEL_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_AMSEL_OFFSET))
#define GPIOAMSEL_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_AMSEL_OFFSET))
#define GPIOAMSEL_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_AMSEL_OFFSET))
#define GPIOAMSEL_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_AMSEL_OFFSET))
#define GPIOAMSEL_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_AMSEL_OFFSET))
#define GPIOAMSEL_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_AMSEL_OFFSET))


/**
	@Name: GPIO Port Control Register
	@Layout:
		bit31:bit28 -> Port MUX Control 7 --- Controls GPIO Pin 7 Configuration (RW)
		bit27:bit24 -> Port MUX Control 6 --- Controls GPIO Pin 6 Configuration (RW)
		bit23:bit20 -> Port MUX Control 5 --- Controls GPIO Pin 5 Configuration (RW)
		bit19:bit16 -> Port MUX Control 4 --- Controls GPIO Pin 4 Configuration (RW)
		bit15:bit12 -> Port MUX Control 3 --- Controls GPIO Pin 3 Configuration (RW)
		bit11:bit8  -> Port MUX Control 2 --- Controls GPIO Pin 2 Configuration (RW)
		bit7:bit4   -> Port MUX Control 1 --- Controls GPIO Pin 1 Configuration (RW)
		bit3:bit0   -> Port MUX Control 0 --- Controls GPIO Pin 0 Configuration (RW)
	@Value:
		According to Table 10-11 in Datasheet (used to specify alternate pin function)
*/
#define GPIO_PCTL_OFFSET			(0x52C)
#define GPIOPCTL_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PCTL_OFFSET))
#define GPIOPCTL_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PCTL_OFFSET))
#define GPIOPCTL_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PCTL_OFFSET))
#define GPIOPCTL_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PCTL_OFFSET))
#define GPIOPCTL_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PCTL_OFFSET))
#define GPIOPCTL_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PCTL_OFFSET))


/**
	@Name: GPIO ADC Control Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> ADCEN 	    (RW)
	@Value:
		Writing 1 -> Corresponding Pin is Used to Trigger ADC
		Writing 0 -> Corresponding Pin is not Used to Trigger ADC
*/
#define GPIO_ADCCTL_OFFSET			(0x530)
#define GPIOADCCTL_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOADCCTL_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOADCCTL_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOADCCTL_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOADCCTL_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOADCCTL_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_ADCCTL_OFFSET))


/**
	@Name: GPIO DMA Control Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> DMAEN 	(RW)
	@Value:
		Writing 1 -> Corresponding Pin is Used to Trigger uDMA
		Writing 0 -> Corresponding Pin is not Used to Trigger uDMA
*/
#define GPIO_DMACTL_OFFSET			(0x534)
#define GPIODMACTL_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_DMACTL_OFFSET))
#define GPIODMACTL_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_DMACTL_OFFSET))
#define GPIODMACTL_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_DMACTL_OFFSET))
#define GPIODMACTL_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_DMACTL_OFFSET))
#define GPIODMACTL_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_DMACTL_OFFSET))
#define GPIODMACTL_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_DMACTL_OFFSET))


/**
	@Name: GPIO Peripheral Identification 4 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID4 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID4_OFFSET			(0xFD0)
#define GPIOPID4_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID4_OFFSET))
#define GPIOPID4_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID4_OFFSET))
#define GPIOPID4_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID4_OFFSET))
#define GPIOPID4_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID4_OFFSET))
#define GPIOPID4_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID4_OFFSET))
#define GPIOPID4_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID4_OFFSET))


/**
	@Name: GPIO Peripheral Identification 5 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID5 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID5_OFFSET			(0xFD4)
#define GPIOPID5_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID5_OFFSET))
#define GPIOPID5_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID5_OFFSET))
#define GPIOPID5_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID5_OFFSET))
#define GPIOPID5_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID5_OFFSET))
#define GPIOPID5_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID5_OFFSET))
#define GPIOPID5_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID5_OFFSET))


/**
	@Name: GPIO Peripheral Identification 6 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID6 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID6_OFFSET			(0xFD8)
#define GPIOPID6_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID6_OFFSET))
#define GPIOPID6_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID6_OFFSET))
#define GPIOPID6_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID6_OFFSET))
#define GPIOPID6_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID6_OFFSET))
#define GPIOPID6_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID6_OFFSET))
#define GPIOPID6_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID6_OFFSET))


/**
	@Name: GPIO Peripheral Identification 7 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID7 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID7_OFFSET			(0xFDC)
#define GPIOPID7_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID7_OFFSET))
#define GPIOPID7_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID7_OFFSET))
#define GPIOPID7_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID7_OFFSET))
#define GPIOPID7_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID7_OFFSET))
#define GPIOPID7_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID7_OFFSET))
#define GPIOPID7_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID7_OFFSET))


/**
	@Name: GPIO Peripheral Identification 0 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID0 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID0_OFFSET			(0xFE0)
#define GPIOPID0_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID0_OFFSET))
#define GPIOPID0_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID0_OFFSET))
#define GPIOPID0_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID0_OFFSET))
#define GPIOPID0_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID0_OFFSET))
#define GPIOPID0_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID0_OFFSET))
#define GPIOPID0_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID0_OFFSET))


/**
	@Name: GPIO Peripheral Identification 1 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID1 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID1_OFFSET			(0xFE4)
#define GPIOPID1_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID1_OFFSET))
#define GPIOPID1_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID1_OFFSET))
#define GPIOPID1_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID1_OFFSET))
#define GPIOPID1_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID1_OFFSET))
#define GPIOPID1_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID1_OFFSET))
#define GPIOPID1_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID1_OFFSET))


/**
	@Name: GPIO Peripheral Identification 2 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID2 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID2_OFFSET			(0xFE8)
#define GPIOPID2_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID2_OFFSET))
#define GPIOPID2_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID2_OFFSET))
#define GPIOPID2_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID2_OFFSET))
#define GPIOPID2_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID2_OFFSET))
#define GPIOPID2_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID2_OFFSET))
#define GPIOPID2_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID2_OFFSET))


/**
	@Name: GPIO Peripheral Identification 3 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> PID3 		(R0)
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID3_OFFSET			(0xFEC)
#define GPIOPID3_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_PID3_OFFSET))
#define GPIOPID3_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_PID3_OFFSET))
#define GPIOPID3_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_PID3_OFFSET))
#define GPIOPID3_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_PID3_OFFSET))
#define GPIOPID3_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_PID3_OFFSET))
#define GPIOPID3_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_PID3_OFFSET))


/**
	@Name: GPIO PrimeCell Identification 0 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> CID0 		(R0)
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID0_OFFSET			(0xFF0)
#define GPIOCID0_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_CID0_OFFSET))
#define GPIOCID0_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_CID0_OFFSET))
#define GPIOCID0_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_CID0_OFFSET))
#define GPIOCID0_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_CID0_OFFSET))
#define GPIOCID0_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_CID0_OFFSET))
#define GPIOCID0_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_CID0_OFFSET))


/**
	@Name: GPIO PrimeCell Identification 1 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> CID1 		(R0)
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID1_OFFSET			(0xFF4)
#define GPIOCID1_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_CID1_OFFSET))
#define GPIOCID1_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_CID1_OFFSET))
#define GPIOCID1_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_CID1_OFFSET))
#define GPIOCID1_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_CID1_OFFSET))
#define GPIOCID1_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_CID1_OFFSET))
#define GPIOCID1_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_CID1_OFFSET))


/**
	@Name: GPIO PrimeCell Identification 2 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> CID2 		(R0)
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID2_OFFSET			(0xFF8)
#define GPIOCID2_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_CID2_OFFSET))
#define GPIOCID2_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_CID2_OFFSET))
#define GPIOCID2_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_CID2_OFFSET))
#define GPIOCID2_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_CID2_OFFSET))
#define GPIOCID2_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_CID2_OFFSET))
#define GPIOCID2_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_CID2_OFFSET))


/**
	@Name: GPIO PrimeCell Identification 3 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO)
		bit7:bit0  -> CID3 		(R0)
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID3_OFFSET			(0xFFC)
#define GPIOCID3_R_PORTA			(*(volatile uint32_t*)(GPIO_PORTA_BASE + GPIO_CID3_OFFSET))
#define GPIOCID3_R_PORTB			(*(volatile uint32_t*)(GPIO_PORTB_BASE + GPIO_CID3_OFFSET))
#define GPIOCID3_R_PORTC			(*(volatile uint32_t*)(GPIO_PORTC_BASE + GPIO_CID3_OFFSET))
#define GPIOCID3_R_PORTD			(*(volatile uint32_t*)(GPIO_PORTD_BASE + GPIO_CID3_OFFSET))
#define GPIOCID3_R_PORTE			(*(volatile uint32_t*)(GPIO_PORTE_BASE + GPIO_CID3_OFFSET))
#define GPIOCID3_R_PORTF			(*(volatile uint32_t*)(GPIO_PORTF_BASE + GPIO_CID3_OFFSET))

/*----------GPIO END----------*/



/*----------SYSCTL START----------*/

// base address for system control module
#define SYSCTL_BASE    (0x400FE000)

/**
     @Name: General-Purpose Input/Output Run Mode Clock Gating Control Register
     @Layout:
         bit31:bit6 -> reserved  (RO)
         bit5       -> Port F    (RW)
         bit4       -> Port E    (RW)
         bit3       -> Port D    (RW)
         bit2       -> Port C    (RW)
         bit1       -> Port B    (RW)
         bit0       -> Port A    (RW)
     @Function:
         Writing 1 -> Port Corresponding to Bit has its Clock Enabled in Run Mode
         Writing 0 -> Port Corresponding to Bit is Disabled ###
 */
#define SYSCTL_RCGCGPIO_OFFSET  (0x608)
#define RCGCGPIO_R  (*(volatile uint32_t*)(SYSCTL_BASE + SYSCTL_RCGCGPIO_OFFSET))


/**
     @Name: GPIO High-Performance Bus Control Register
     @Layout:
         bit31:bit6 -> reserved  (RO)
         bit5       -> Port F    (RW)
         bit4       -> Port E    (RW)
         bit3       -> Port D    (RW)
         bit2       -> Port C    (RW)
         bit1       -> Port B    (RW)
         bit0       -> Port A    (RW)
     @Function:
         Writing 1 -> Port Corresponding to Bit has AHB Enabled
         Writing 0 -> Port Corresponding to Bit has APB Enabled
 */
#define SYSCTL_GPIOHBCTL_OFFSET  (0x06C)
#define GPIOHBCTL_R  (*(volatile uint32_t*)(SYSCTL_BASE + SYSCTL_GPIOHBCTL_OFFSET))


/**
     @Name: Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control Register
     @Layout:
         bit31:bit8 -> reserved  	   (RO)
		 bit7       -> UART Module 7   (RW)
         bit6       -> UART Module 6   (RW)
         bit5       -> UART Module 5   (RW)
         bit4       -> UART Module 4   (RW)
         bit3       -> UART Module 3   (RW)
         bit2       -> UART Module 2   (RW)
         bit1       -> UART Module 1   (RW)
         bit0       -> UART Module 0   (RW)
     @Function:
         Writing 1 -> UART Module Corresponding to Bit is Provided with a Clock and is Enabled
         Writing 0 -> UART Module Corresponding to Bit is Disabled
 */
#define SYSCTL_RCGCUART_OFFSET  (0x618)
#define RCGCUART_R  (*(volatile uint32_t*)(SYSCTL_BASE + SYSCTL_RCGCUART_OFFSET))


/**
     @Name: Run-Mode Clock Configuration Register
     @Layout:
         bit31:bit28 -> reserved  	   (RO)
		 bit27       -> ACG   (RW)
		 bit26:bit23 -> SYSDIV  	   (RO)
         bit22       -> USESYSDIV   (RW)
         bit21       -> reserved   (RW)
         bit20       -> USEPWMDIV   (RW)
		 bit19:bit17 -> PWMDIV  	   (RO)
         bit16:bit14       -> reserved   (RW)
         bit13       -> PWRDN   (RW)
		 bit12       -> reserved   (RO)
		 bit11       -> BYPASS   (RW)
		 bit10:bit6 -> XTAL  	   (RO)
		 bit5:bit4 -> OSCSRC  	   (RO)
		 bit3:bit1 -> reserved  	   (RO)
         bit0       -> MOSCDIS   (RW)
     @Function:
         *will write it down later*
 */
#define SYSCTL_RCC_OFFSET  (0x060)
#define RCC_R  (*(volatile uint32_t*)(SYSCTL_BASE + SYSCTL_RCC_OFFSET))



/*----------SYSCTL END----------*/



/*----------UART START----------*/
// defining base addresses for UART modules
#define UART_UART0_BASE		(0x4000C000)
#define UART_UART1_BASE		(0x4000D000)
#define UART_UART2_BASE		(0x4000E000)
#define UART_UART3_BASE		(0x4000F000)
#define UART_UART4_BASE		(0x40010000)
#define UART_UART5_BASE		(0x40011000)
#define UART_UART6_BASE		(0x40012000)
#define UART_UART7_BASE		(0x40013000)


/**
    @Name: UART Data Register
    @Layout:
         bit31:bit12 -> reserved  	    (RO)
		 bit11       -> Overrun Error   (RO)  
         bit10       -> Break Error     (RO)  
         bit9        -> Parity Error    (RO)  
         bit8        -> Framing Error   (RO)  
		 bit7:bit0   -> Tx/Rx Data      (RW)
    @Function:
		OE == 0 ? No data has been lost due to a FIFO overrun : New data was received when the FIFO was full, resulting in data loss
	    BE == 0 ? No break condition has occurred :  A break condition has been detected, indicating that the receive data input was held Lowfor longer than a full-word transmission time (defined as start, data, parity, and stop bits)
	    PE == 0 ? No parity error has occurred : The parity of the received data character does not match the parity defined by bits 2 and 7 of the UARTLCRH register
		FE == 0 ? No framing error has occurred : The received character does not have a valid stop bit (a valid stop bit is 1)
	@Note:
		The Error flag bits here are tied to the data being written/read, more interactions can be done with error bits with the next registers
 */
#define UART_UARTDR_OFFSET  (0x000)
#define UARTDR_R_UART0	(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART1  (*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART2  (*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART3  (*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART4  (*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART5  (*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART6  (*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTDR_OFFSET))
#define UARTDR_R_UART7  (*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTDR_OFFSET))


/**
    @Name: UART Receive Status/Error Clear Register
    @Layout (Receive Status (RO)):
         bit31:bit4 -> reserved  	   (RO)
		 bit3       -> Overrun Error   (RO)  
         bit2       -> Break Error     (RO)  
         bit1       -> Parity Error    (RO)  
         bit0       -> Framing Error   (RO)  
	@Layout (Error Clear (WO)):
         bit31:bit8 -> reserved  	   (RO)
		 bit7:bit0  -> DATA 		   (WO)
    @Function:
		Writing 1 or 0 -> Clears All 4 Error Flags 
*/
#define UART_UARTRSR_UARTECR_OFFSET  	(0x004)
#define UARTRSR_UARTECR_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTRSR_UARTECR_OFFSET))
#define UARTRSR_UARTECR_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTRSR_UARTECR_OFFSET))


/**
    @Name: UART Flag Register
    @Layout:
        bit31:bit8 -> reserved 	(RO)
		bit7       -> TXFE   	(RO)  
        bit6       -> RXFF     	(RO)  
        bit5       -> TXFF    	(RO)  
        bit4       -> RXFE   	(RO) 
		bit3       -> BUSY		(RO)
		bit2:1     -> reserved	(RO)
		bit0       -> CTS		(RO)
    @Function:
		TXFE (UART Transmit FIFO Empty) -> = 0 Has data to transmit (full): = 1 if FEN is 0 the transmit holding register is empty and if FEN is 1 the transmit FIFO is empty 
		RXFF (UART Receive FIFO Full) -> = 0 Rx can receive data (empty) : = 1 if FEN is 0 the receive holding register is full and if FEN is 1 the transmit FIFO is full
		TXFF (UART Transmit FIFO Full) -> = 0 Has data to transmit (empty): = 1 if FEN is 0 the transmit holding register is empty and if FEN is 1 the transmit FIFO is empty 
		RXFE (UART Receive FIFO Empty) -> = 0 Receiver is full : = 1 if FEN is 0 the receive holding register is empty and if FEN is 1 the receive FIFO is empty
		BUSY (UART BUSY) -> = 0 uart is not busy : = 1 UART is busy transmitting data. This bit remains set until the complete byte, including all stop bits, has been sent from the shift register
		CTS (Clear To Send) -> = 0 connected device is NOT ready to receive data : = 1 connected device is ready to receive data 
*/
#define UART_UARTFR_OFFSET  	(0x018)
#define UARTFR_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTFR_OFFSET))
#define UARTFR_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTFR_OFFSET))


/**
    @Name: UART IrDA Low-Power Register Register
    @Layout:
        bit31:bit8 -> reserved 		(RO)
		bit7:bit0  -> ILPDVSR   	(RW)
    @Function:
		This field contains the 8-bit low-power divisor value
*/
#define UART_UARTILPR_OFFSET  	(0x020)
#define UARTILPR_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTILPR_OFFSET))
#define UARTILPR_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTILPR_OFFSET))


/**
    @Name: UART Integer Baud-Rate Divisor Register
    @Layout:
        bit31:bit16 -> reserved 	(RO)
		bit15:bit0  -> DIVINT   	(RW)
    @Function:
		 Integer Baud-Rate Divisor
*/
#define UART_UARTIBRD_OFFSET  	(0x024)
#define UARTIBRD_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTIBRD_OFFSET))
#define UARTIBRD_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTIBRD_OFFSET))


/**
    @Name: UART Fractional Baud-Rate Divisor Register
    @Layout:
        bit31:bit6 -> reserved 		(RO)
		bit5:bit0  -> DIVFRAC   	(RW)
    @Function:
		 Fractional Baud-Rate Divisor
*/
#define UART_UARTFBRD_OFFSET  	(0x028)
#define UARTFBRD_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTFBRD_OFFSET))
#define UARTFBRD_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTFBRD_OFFSET))


/**
    @Name: UART Line Control Register
    @Layout:
        bit31:bit8 -> reserved 	(RO)
		bit7	   -> SPS   	(RW)
		bit6:bit5  -> WLEN   	(RW)
		bit4	   -> FEN   	(RW)
		bit3	   -> STP2   	(RW)
		bit2	   -> EPS   	(RW)
		bit1	   -> PEN   	(RW)
		bit0	   -> BRK   	(RW)
    @Function:
		SPS (Stick Parity Select) -> = 0 to disable && other values dependent on other bits specified in datasheet
		WLEN (Word Length for Sent/Received Data) -> (5-8 bits)
		FEN (Enable FIFO) -> = 0 FIFOs are disabled (Character mode). The FIFOs become 1-byte-deep holding registers : = 1 transmit and receive FIFO buffers are enabled (FIFO mode)
		STP2 (Two Stop Bits Select) -> = 0 for one stop bit : = 1 for two stop bits
		EPS (Even Parity Select) -> = 0 for odd parity : = 1 for even parity
		PEN (Parity Enable) -> = 0 to disable parity : = 1 to enable parity
		BRK (UART Send Break) -> = 0 for normal use : *something!*
	@Note:
		This control register is used to configure *data format*
*/
#define UART_UARTLCRH_OFFSET  	(0x02C)
#define UARTLCRH_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTLCRH_OFFSET))
#define UARTLCRH_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTLCRH_OFFSET))


/**
    @Name: UART Control Register
    @Layout:
        bit31:bit16	-> reserved (RO)
		bit15	   	-> CTSEN   	(RW)
		bit14	   	-> RTSEN   	(RW)
		bit13:bit12	-> reserved (RO)
		bit11	   	-> RTS   	(RW)
		bit10	   	-> reserved (RO)
		bit9	   	-> RXE   	(RW)
		bit8	   	-> TXE   	(RW)
		bit7	   	-> LBE   	(RW)
		bit6	   	-> reserved (RO)
		bit5	   	-> HSE   	(RW)
		bit4	   	-> EOT   	(RW)
		bit3	   	-> SMART   	(RW)
		bit2	   	-> SIRLP   	(RW)
		bit1	   	-> SIREN   	(RW)
		bit0	   	-> UARTEN   (RW)
    @Function:
		CTSEN (Enable Clear To Send) -> = 0 to disable CTS : = 1 to enable CTS
		RTSEN (Enable Request To Send) -> = 0 to disable RTS : = 1 to enable RTS
		RTS (Request To Send)
		RXE (UART Receive Enable) -> = 0 to disable receive : = 1 to enable receive
		TXE (UART Transmit Enable) -> = 0 to disable transmit : = 1 to enable transmit
		LBE (UART Loopback Enable) -> = 0 for normal operation : = 1 for feeding  UnTx path through UnRx path
		HSE (High-Speed Enable) -> = 0 for div by 16 clock : = 1 for div by 8 clock
		EOT (End of Transmission) -> = 0 The TXRIS bit is set when the transmit FIFO condition specified in UARTIFLS is met : The TXRIS bit is set only after all transmitted data, including stop bits, have cleared the serializer
		SMART (ISO 7816 Smart Card Support) -> = 0 for normal operation : = 1 for Smart Card mode of operation
		SIRLP (UART SIR Low-Power Mode) -> = 0 Low-level bits are transmitted as an active High pulse with a width of 3/16th of the bit period : UART operates in SIR Low-Power mode. Low-level bits are transmitted with a pulse width which is 3 times the period of the IrLPBaud16 input signal, regardless of the selected bit rate
		SIREN (UART SIR Enable) -> = 0 for normal operation : = 1 IrDA SIR block is enabled, and the UART will transmit and receive data using SIR protocol.
		UARTEN (UART Enable) -> = 0 to disable UART : = 1 to enable UART
	@Note:
		This control register is used to configure *the way the UART module should operate*
*/
#define UART_UARTCTL_OFFSET  	(0x030)
#define UARTCTL_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTCTL_OFFSET))
#define UARTCTL_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTCTL_OFFSET))



/**
    @Name: UART Interrupt FIFO Level Select Register
    @Layout:
        bit31:bit6	-> reserved (RO)
		bit5:bit3	-> RXIFLSEL (RW)
		bit2:bit0	-> TXIFLSEL (RW)
    @Function:
		RXIFLSEL: 0x00=>Rx FIFO 1/8 full, 0x01=>Rx FIFO 1/4 full, 0x02=>Rx FIFO 1/2 full (default), 0x03=>Rx FIFO 3/4 full, 0x04=>Rx FIFO 7/8 full
		TXIFLSEL: 0x00=>Tx FIFO 1/8 full, 0x01=>Tx FIFO 1/4 full, 0x02=>Tx FIFO 1/2 full (default), 0x03=>Tx FIFO 3/4 full, 0x04=>Tx FIFO 7/8 full
*/
#define UART_UARTIFLS_OFFSET  	(0x034)
#define UARTIFLS_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTIFLS_OFFSET))
#define UARTIFLS_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTIFLS_OFFSET))


/**
    @Name: UART Interrupt Mask Register
    @Layout:
        bit31:bit13	-> reserved (RO)
		bit12	   	-> 9BITIM   (RW)
		bit11	   	-> reserved (RW)
		bit10    	-> OEIM 	(RW)
		bit9	   	-> BEIM   	(RW)
		bit8	   	-> PEIM   	(RW)
		bit7	   	-> FEIM   	(RW)
		bit6	   	-> RTIM 	(RW)
		bit5	   	-> TXIM   	(RW)
		bit4	   	-> RXIM   	(RW)
		bit3:bit2	-> reserved (RO)
		bit1	   	-> CTSIM   	(RW)
		bit0	   	-> reserved (RO)
    @Function:
		9BITIM (9-Bit Mode Interrupt Mask) -> = 0 9BITRIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the 9BITRIS bit in the UARTRIS register is set
		OEIM (UART Overrun Error Interrupt Mask) -> = 0 OERIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the OERIS bit in the UARTRIS register is set
		BEIM (UART Break Error Interrupt Mask) -> = 0 BERIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the BERIS bit in the UARTRIS register is set
		PEIM (UART Parity Error Interrupt Mask) -> = 0 PERIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the PERIS bit in the UARTRIS register is set
		FEIM (UART Framing Error Interrupt Mask) -> = 0 FERIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the FERIS bit in the UARTRIS register is set
		RTIM (UART Receive Time-Out Interrupt Mask) -> = 0 RTRIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the RTRIS bit in the UARTRIS register is set
		TXIM (UART Transmit Interrupt Mask) -> = 0 TXRIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the TXRIS bit in the UARTRIS register is set
		RXIM (UART Receive Interrupt Mask) -> = 0 RXRIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the RXRIS bit in the UARTRIS register is set
		CTSIM (UART Clear To Sent Modem Interrupt Mask) -> = 0 CTSRIS interrupt is suppressed and not sent to the interrupt controller : = 1 an interrupt is sent to the interrupt controller when the CTSRIS bit in the UARTRIS register is set
*/
#define UART_UARTIM_OFFSET  	(0x038)
#define UARTIM_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTIM_OFFSET))
#define UARTIM_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTIM_OFFSET))


/**
    @Name: UART Raw Interrupt Status Register
    @Layout:
        bit31:bit13	-> reserved (RO)
		bit12	   	-> 9BITIM   (RO)
		bit11	   	-> reserved (RO)
		bit10    	-> OEIM 	(RO)
		bit9	   	-> BEIM   	(RO)
		bit8	   	-> PEIM   	(RO)
		bit7	   	-> FEIM   	(RO)
		bit6	   	-> RTIM 	(RO)
		bit5	   	-> TXIM   	(RO)
		bit4	   	-> RXIM   	(RO)
		bit3:bit2	-> reserved (RO)
		bit1	   	-> CTSIM   	(RO)
		bit0	   	-> reserved (RO)
    @Function:
		Reading 0 -> No Interrupt
		Reading 1 -> 
			9BITRIS => receive address match occurred
			OERIS => overrun error has occurred
			BERIS => break error has occurred
			PERIS => parity error has occurred
			FERIS => framing error has occurred
			RTRIS => receive time out has occurred
			TXRIS => if EOT bit in UARTCTL is clear the transmit FIFO level has passed through the condition defined in the UARTIFLS register. If the EOT bit is set,the last bit of all transmitted data and flags has left the serializer.
			RXRIS => receive FIFO has passed through the condition defined in UARTIFLS register
			CTSRIS => clear to send used for software flow control
	@Note:
		indicates whether an interrupt condition has occurred regardless of whether the interrupt is enabled or masked
*/
#define UART_UARTRIS_OFFSET  	(0x038)
#define UARTRIS_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTRIS_OFFSET))
#define UARTRIS_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTRIS_OFFSET))


/**
    @Name: UART Masked Interrupt Status Register
    @Layout:
        bit31:bit13	-> reserved (RO)
		bit12	   	-> 9BITIM   (RO)
		bit11	   	-> reserved (RO)
		bit10    	-> OEIM 	(RO)
		bit9	   	-> BEIM   	(RO)
		bit8	   	-> PEIM   	(RO)
		bit7	   	-> FEIM   	(RO)
		bit6	   	-> RTIM 	(RO)
		bit5	   	-> TXIM   	(RO)
		bit4	   	-> RXIM   	(RO)
		bit3:bit2	-> reserved (RO)
		bit1	   	-> CTSIM   	(RO)
		bit0	   	-> reserved (RO)
    @Function:
		Reading 0 -> No Interrupt Occurred or is Masked
		Reading 1 -> Unmasked Interrupt was raised
	@Note:
		indicates whether an interrupt is both active and enabled (i.e., whether it can generate an interrupt request to the CPU)
*/
#define UART_UARTMIS_OFFSET  	(0x040)
#define UARTMIS_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTMIS_OFFSET))
#define UARTMIS_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTMIS_OFFSET))


/**
    @Name: UART Interrupt Clear Register
    @Layout:
        bit31:bit13	-> reserved (RO)
		bit12	   	-> 9BITIM   (W1C)
		bit11	   	-> reserved (RO)
		bit10    	-> OEIM 	(W1C)
		bit9	   	-> BEIM   	(W1C)
		bit8	   	-> PEIM   	(W1C)
		bit7	   	-> FEIM   	(W1C)
		bit6	   	-> RTIM 	(W1C)
		bit5	   	-> TXIM   	(W1C)
		bit4	   	-> RXIM   	(W1C)
		bit3:bit2	-> reserved (RO)
		bit1	   	-> CTSIM   	(W1C)
		bit0	   	-> reserved (RO)
    @Function:
		Writing 1 clears the corresponding bits in UARTMIS & UARTRIS registers
*/
#define UART_UARTICR_OFFSET  	(0x044)
#define UARTICR_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTICR_OFFSET))
#define UARTICR_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTICR_OFFSET))


/**
    @Name: UART DMA Control Register
    @Layout:
        bit31:bit3	-> reserved (RO)
		bit2		-> DMAERR 	(RW)
		bit1	   	-> TXDMAE	(RW)
		bit0	   	-> RXDMAE 	(RW)
    @Function:
		DMAERR (DMA on Error) -> = 0 uDMA receive requests are unaffected when an error occurs : = 1 uDMA receive requests are automatically disabled when a receive error occurs
		TXDMAE (Transmit DMA Enable) -> = 0 uDMA for transmit FIFO is disabled : = 1 uDMA is enabled for transmit FIFO
		RXDMAE (Transmit DMA Enable) -> = 0 uDMA for receive FIFO is disabled : = 1 uDMA is enabled for receive FIFO		
*/
#define UART_UARTDMACTL_OFFSET  	(0x048)
#define UARTDMACTL_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTDMACTL_OFFSET))
#define UARTDMACTL_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTDMACTL_OFFSET))


/**
    @Name: UART 9-Bit Self Address Register
    @Layout:
        bit31:bit16	-> reserved (RO)
		bit15		-> 9BITEN 	(RW)
		bit14:bit8	-> reserved (RO)
		bit7:bit0	-> ADDR 	(RW)
    @Function:
		9BITEN (9-Bit Enable) -> = 0 for disabled : =1 for enabled
		ADDR (Self-Address for 9-Bit Mode) -> address that should be matched when UART9BITAMASK is 0xFF
*/
#define UART_UART9BITADDR_OFFSET  	(0x0A4)
#define UART9BITADDR_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UART9BITADDR_OFFSET))
#define UART9BITADDR_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UART9BITADDR_OFFSET))


/**
    @Name: UART 9-Bit Self Address Mask Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> MASK 	(RW)
    @Function:
		MASK (Self Address Mask For 9-Bit Mode) -> contains the address mask that creates a set of addresses that should be matched
*/
#define UART_UART9BITAMASK_OFFSET  	(0x0A8)
#define UART9BITAMASK_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UART9BITAMASK_OFFSET))
#define UART9BITAMASK_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UART9BITAMASK_OFFSET))


/**
    @Name: UART Peripheral Properties Register
    @Layout:
        bit31:bit2	-> reserved (RO)
		bit1		-> NB	 	(RW)
		bit0		-> SC		(RW)
    @Function:
		NB (9-Bit Support) -> = 0 UART module does not provide support for the transmission of 9-bit data for RS-485 support : = 1 UART module provides support
		SC (Smart Card Support) -> = 0 UART module does not provide smart card support : = 1 UART module provides smart card support
*/
#define UART_UARTPP_OFFSET  	(0xFC0)
#define UARTPP_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPP_OFFSET))
#define UARTPP_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPP_OFFSET))


/**
    @Name: UART Clock Configuration Register
    @Layout:
        bit31:bit4	-> reserved (RO)
		bit3:bit0	-> CS	 	(RW)
    @Function:
		CS (UART Baud Clock Source):
			0x00 => System Clock
			0x05 => PIOSC (Precision Internal Oscillator -- provides a fixed frequency of 16 MHz)
*/
#define UART_UARTCC_OFFSET  	(0xFC8)
#define UARTCC_R_UART0			(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTCC_OFFSET))
#define UARTCC_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTCC_OFFSET))


/**
    @Name: UART Peripheral Identification 4 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID4	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID4_OFFSET  	(0xFD0)
#define UARTPID4_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID4_OFFSET))
#define UARTPID4_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID4_OFFSET))


/**
    @Name: UART Peripheral Identification 5 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID5	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID5_OFFSET  	(0xFD4)
#define UARTPID5_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID5_OFFSET))
#define UARTPID5_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID5_OFFSET))


/**
    @Name: UART Peripheral Identification 6 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID6	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID6_OFFSET  	(0xFD8)
#define UARTPID6_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID6_OFFSET))
#define UARTPID6_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID6_OFFSET))


/**
    @Name: UART Peripheral Identification 7 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID7	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID7_OFFSET  	(0xFDC)
#define UARTPID7_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID7_OFFSET))
#define UARTPID7_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID7_OFFSET))


/**
    @Name: UART Peripheral Identification 0 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID40 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID0_OFFSET  	(0xFE0)
#define UARTPID0_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID0_OFFSET))
#define UARTPID0_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID0_OFFSET))


/**
    @Name: UART Peripheral Identification 1 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID1	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID1_OFFSET  	(0xFE4)
#define UARTPID1_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID1_OFFSET))
#define UARTPID1_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID1_OFFSET))


/**
    @Name: UART Peripheral Identification 2 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID2	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID2_OFFSET  	(0xFE8)
#define UARTPID2_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID2_OFFSET))
#define UARTPID2_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID2_OFFSET))


/**
    @Name: UART Peripheral Identification 3 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> PID3	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTPID3_OFFSET  	(0xFEC)
#define UARTPID3_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTPID3_OFFSET))
#define UARTPID3_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTPID3_OFFSET))


/**
    @Name: UART PrimeCell Identification 0 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> CID0	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTCID0_OFFSET  	(0xFF0)
#define UARTCID0_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTCID0_OFFSET))
#define UARTCID0_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTCID0_OFFSET))


/**
    @Name: UART PrimeCell Identification 1 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> CID1	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTCID1_OFFSET  	(0xFF4)
#define UARTCID1_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTCID1_OFFSET))
#define UARTCID1_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTCID1_OFFSET))


/**
    @Name: UART PrimeCell Identification 2 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> CID2	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTCID2_OFFSET  	(0xFF8)
#define UARTCID2_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTCID2_OFFSET))
#define UARTCID2_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTCID2_OFFSET))


/**
    @Name: UART PrimeCell Identification 3 Register
    @Layout:
        bit31:bit8	-> reserved (RO)
		bit7:bit0	-> CID3	 	(RW)
    @Function:
		Can be used by software to identify the presence of this peripheral
*/
#define UART_UARTCID3_OFFSET  	(0xFFC)
#define UARTCID3_R_UART0		(*(volatile uint32_t*)(UART_UART0_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART1  		(*(volatile uint32_t*)(UART_UART1_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART2  		(*(volatile uint32_t*)(UART_UART2_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART3  		(*(volatile uint32_t*)(UART_UART3_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART4  		(*(volatile uint32_t*)(UART_UART4_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART5  		(*(volatile uint32_t*)(UART_UART5_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART6  		(*(volatile uint32_t*)(UART_UART6_BASE + UART_UARTCID3_OFFSET))
#define UARTCID3_R_UART7  		(*(volatile uint32_t*)(UART_UART7_BASE + UART_UARTCID3_OFFSET))


/*----------UART END----------*/

#endif
