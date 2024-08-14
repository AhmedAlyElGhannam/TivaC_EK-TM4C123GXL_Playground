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

	#define GPIO_PORTA_BASE		((volatile uint32_t*)0x40004000)
	#define GPIO_PORTB_BASE		((volatile uint32_t*)0x40005000)
	#define GPIO_PORTC_BASE		((volatile uint32_t*)0x40006000)
	#define GPIO_PORTD_BASE		((volatile uint32_t*)0x40007000)
	#define GPIO_PORTE_BASE		((volatile uint32_t*)0x40024000)
	#define GPIO_PORTF_BASE		((volatile uint32_t*)0x40025000)
	
#elif (GPIO_PORT_BUS == AHB_BUS)
	
	#define GPIO_PORTA_BASE		((volatile uint32_t*)0x40058000)
	#define GPIO_PORTB_BASE		((volatile uint32_t*)0x40059000)
	#define GPIO_PORTC_BASE     ((volatile uint32_t*)0x4005A000)
	#define GPIO_PORTD_BASE     ((volatile uint32_t*)0x4005B000)
	#define GPIO_PORTE_BASE     ((volatile uint32_t*)0x4005C000)
	#define GPIO_PORTF_BASE     ((volatile uint32_t*)0x4005D000)
	
#endif

/**
	@Name: GPIO Data Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DATA 		(RW) (0x00 Upon Reset)
		
*/
#define GPIO_DATA_OFFSET	0x00


/**
	@Name: GPIO Data Direction Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DIR 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin is an Output
		Writing 0 -> Corresponding Pin is an Input
		
*/
#define GPIO_DIR_OFFSET		0x400


/**
	@Name: GPIO Interrupt Sense Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> IS 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin is Level-Sensitive (High & Low)
		Writing 0 -> Corresponding Pin is Edge-Sensitive (Rising & Falling)
		
*/
#define GPIO_IS_OFFSET		0x404


/**
	@Name: GPIO Interrupt Both Edges Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> IBE 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin is Sensitive to Both Edges (Rising & Falling)
		Writing 0 -> Interrupt Generation is Controlled by GPIOIEV Register
		
*/
#define GPIO_IBE_OFFSET		0x408


/**
	@Name: GPIO Interrupt Event Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> IEV 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin Triggers an Interrupt on Falling-Edge OR Low-Level
		Writing 0 -> Corresponding Pin Triggers an Interrupt on Rising-Edge OR High-Level
		
*/
#define GPIO_IEV_OFFSET		0x40C


/**
	@Name: GPIO Interrupt Mask Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> IME 		(RW) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin's Interrupt is not Masked (Enabled) and Sent to Interrupt Controller
		Writing 0 -> Corresponding Pin's Interrupt is Masked (Disabled)
		
*/
#define GPIO_IM_OFFSET		0x410


/**
	@Name: GPIO Raw Interrupt Status Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> RIS 		(RO) (0x00 Upon Reset)
	@Value:
		Reading 1 -> Corresponding Pin Raised an Interrupt
		Reading 0 -> Corresponding Pin Did not Raise an Interrupt
		
*/
#define GPIO_RIS_OFFSET		0x414
	

/**
	@Name: GPIO Masked Interrupt Status Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> MIS 		(R0) (0x00 Upon Reset)
	@Value:
		Reading 1 -> Corresponding Pin Triggered an Interrupt to the Interrupt Controller
		Reading 0 -> Corresponding Pin Has its Interrupt Masked OR Did not Raise an Interrupt
		
*/
#define GPIO_MIS_OFFSET		0x418


/**
	@Name: GPIO Interrupt Clear Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> IC 		(W1C) (0x00 Upon Reset)
	@Value:
		Writing 1 -> Corresponding Pin Interrupt is Cleared
		Writing 0 -> Corresponding Pin Interrupt is Unaffected
		
*/
#define GPIO_ICR_OFFSET		0x41C


/**
	@Name: GPIO Interrupt Clear Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> AFSEL 	(RW) 
	@Value:
		Writing 1 -> Corresponding Pin Functions as the Designated Alternate Function
		Writing 0 -> Corresponding Pin Functions as GPIO and is Controlled by GPIO Registers
*/
#define GPIO_AFSEL_OFFSET		0x420


/**
	@Name: GPIO 2-mA Drive Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DRV2 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin Drives 2-mA
		Writing 0 -> Corresponding Pin has its Drive controlled by GPIODR4R OR GPIODR8R
*/
#define GPIO_DR2R_OFFSET		0x500


/**
	@Name: GPIO 4-mA Drive Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DRV4 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin Drives 4-mA
		Writing 0 -> Corresponding Pin has its Drive controlled by GPIODR2R OR GPIODR8R
*/
#define GPIO_DR4R_OFFSET		0x504


/**
	@Name: GPIO 8-mA Drive Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DRV8 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin Drives 8-mA
		Writing 0 -> Corresponding Pin has its Drive controlled by GPIODR2R OR GPIODR4R
*/
#define GPIO_DR8R_OFFSET		0x508


/**
	@Name: GPIO Open Drain Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> ODE 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin is Configured as Open Drain
		Writing 0 -> Corresponding Pin is not Configured as Open Drain
*/
#define GPIO_ODR_OFFSET		0x50C


/**
	@Name: GPIO Pull-Up Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PUE 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin's weak Pull-Up Resistor is Enabled
		Writing 0 -> Corresponding Pin's weak Pull-Up Resistor is Disabled
*/
#define GPIO_PUR_OFFSET		0x510


/**
	@Name: GPIO Pull-Down Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PDE 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin's weak Pull-Down Resistor is Enabled
		Writing 0 -> Corresponding Pin's weak Pull-Down Resistor is Disabled
*/
#define GPIO_PDR_OFFSET		0x514


/**
	@Name: GPIO Slew Rate Control Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> SRL 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin's Slew Rate Control is Enabled (8mA Drive ONLY)
		Writing 0 -> Corresponding Pin's Slew Rate Control is Disabled (8mA Drive ONLY)
*/
#define GPIO_SLR_OFFSET		0x518


/**
	@Name: GPIO Digital Enable Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DEN 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin's Digital Functions are Enabled (8mA Drive ONLY)
		Writing 0 -> Corresponding Pin's Digital Functions are Disabled (8mA Drive ONLY)
*/
#define GPIO_DEN_OFFSET		0x51C


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
#define GPIO_LOCK_OFFSET		0x520


/**
	@Name: GPIO Commit Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> CR 	    (RW) 
	@Value:
		Writing 1 -> Corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, and GPIODEN bits cannot be Written
		Writing 0 -> Corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, and GPIODEN bits can be Written
*/
#define GPIO_CR_OFFSET		0x524


/**
	@Name: GPIO Analog Mode Select Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> GPIOAMSEL (RW) 
	@Value:
		Writing 1 -> Corresponding Pin's Analog Functions are Enabled and the Isolation ?! is Disabled
		Writing 0 -> Corresponding Pin's Analog Functions are Disabled and the Isolation ?! is Enabled
*/
#define GPIO_AMSEL_OFFSET		0x528


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
		According to Table 10-11 in Datasheet
*/
#define GPIO_PCTL_OFFSET		0x52C


/**
	@Name: GPIO ADC Control Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> ADCEN 	    (RW) 
	@Value:
		Writing 1 -> Corresponding Pin is Used to Trigger ADC
		Writing 0 -> Corresponding Pin is not Used to Trigger ADC
*/
#define GPIO_ADCCTL_OFFSET		0x530


/**
	@Name: GPIO DMA Control Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> DMAEN 	(RW) 
	@Value:
		Writing 1 -> Corresponding Pin is Used to Trigger uDMA
		Writing 0 -> Corresponding Pin is not Used to Trigger uDMA
*/
#define GPIO_DMACTL_OFFSET		0x534


/**
	@Name: GPIO Peripheral Identification 4 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID4 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID4_OFFSET		0xFD0



/**
	@Name: GPIO Peripheral Identification 5 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID5 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID5_OFFSET		0xFD4


/**
	@Name: GPIO Peripheral Identification 6 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID6 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID6_OFFSET		0xFD8


/**
	@Name: GPIO Peripheral Identification 7 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID7 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID7_OFFSET		0xFDC


/**
	@Name: GPIO Peripheral Identification 0 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID0 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID0_OFFSET		0xFE0


/**
	@Name: GPIO Peripheral Identification 1 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID1 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID1_OFFSET		0xFE4


/**
	@Name: GPIO Peripheral Identification 2 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID2 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID2_OFFSET		0xFE8


/**
	@Name: GPIO Peripheral Identification 3 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> PID3 		(R0) 
	@Function:
		Used by Software to Identify the Peripheral
*/
#define GPIO_PID3_OFFSET		0xFEC


/**
	@Name: GPIO PrimeCell Identification 0 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> CID0 		(R0) 
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID0_OFFSET		0xFF0


/**
	@Name: GPIO PrimeCell Identification 1 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> CID1 		(R0) 
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID1_OFFSET		0xFF4


/**
	@Name: GPIO PrimeCell Identification 2 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> CID2 		(R0) 
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID2_OFFSET		0xFF8


/**
	@Name: GPIO PrimeCell Identification 3 Register
	@Layout:
		bit31:bit8 -> reserved 	(RO) 
		bit7:bit0  -> CID3 		(R0) 
	@Function:
		Provides Software a Standard Cross-Peripheral Identification System
*/
#define GPIO_CID3_OFFSET		0xFFC

/*----------GPIO END----------*/

#endif