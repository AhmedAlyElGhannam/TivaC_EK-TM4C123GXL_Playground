#include "tm4c123gh6pm.h"

#define RED_LED         (1U << 1)
#define BLUE_LED        (1U << 2)
#define GREEN_LED       (1U << 3)

/**
RGB LED:
Red LED: Connected to PF1 (Port F, Pin 1)
Blue LED: Connected to PF2 (Port F, Pin 2)
Green LED: Connected to PF3 (Port F, Pin 3)
User Switches:
SW1 (Left Switch): Connected to PF4 (Port F, Pin 4)
SW2 (Right Switch): Connected to PF0 (Port F, Pin 0)
*/

// counter for delay
unsigned long counter = 0;

void main(void)
{
    /** GPIO */
    // enable gpio clk for port F
    SYSCTL_RCGCGPIO_R |= (1U << 5);
    // enable advanced high-performance bus for port F
    SYSCTL_GPIOHBCTL_R |= (1U << 5);
    // set pins direction to output (write 1)
    GPIO_PORTF_AHB_DIR_R |= (RED_LED | BLUE_LED | GREEN_LED);
    // digital enable (write 1)
    GPIO_PORTF_AHB_DEN_R |= (RED_LED | BLUE_LED | GREEN_LED);

    /** Watchdog */
    // enable and provide clk to WD0
    SYSCTL_RCGCWD_R |= (1U << 0);
    // enable WD0 reset
    WATCHDOG0_CTL_R |= (1U << 1);
    // load WD0 counter value (check current counter value from WATCHDOG0_VALUE_R)
    WATCHDOG0_LOAD_R = (unsigned long)(0x00000F00);
    // stop WD0 counter when debugging and resume upon exiting debug
    WATCHDOG0_TEST_R |= (1U << 8);
    // enable WD0
    WATCHDOG0_CTL_R |= (1U << 0);
    while(1)
    {
        // set INDIVIDUAL BITS in data register (MIND = BLOWN!)
        GPIO_PORTF_AHB_DATA_BITS_R[BLUE_LED] = BLUE_LED; // equivalent to setting pin 3
        // delay
        //while ((++counter) < 500000);
        //counter = 0;
        // kick the dog!
        // WATCHDOG0_LOAD_R = (unsigned long)(0xFEFEAB00);
        // clear INDIVIDUAL BITS in data register (MIND = BLOWN!)
        GPIO_PORTF_AHB_DATA_BITS_R[BLUE_LED] = 0; // equivalent to clearing pin 3
        // delay
        //while ((++counter) < 9000000);
        //counter = 0;
        //while ((++counter) < 9000000);

        GPIO_PORTF_AHB_DATA_BITS_R[RED_LED] = RED_LED; // equivalent to setting pin 1 (will not be reached)

    }
}
