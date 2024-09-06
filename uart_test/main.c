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

/**
 * will use UART0
 * Tx -> PA1
 * Rx -> PA0
 * */

void send_char(char c);
unsigned char receive_char(void);

void main(void)
{
    /** UART */
    // enable chosen chosen modules by writing 1 in corresponding bit (bit0->bit3 for 4 modules) RCGCSSI
    SYSCTL_RCGCUART_R |= (1U << 0); // UART0
    // enable clock for chosen SPI modules via GPIO port clock RCGCGPIO
    SYSCTL_RCGCGPIO_R |= (1U << 0); // port A
    // enable advanced high-performance bus for port A && F cuz why not
    SYSCTL_GPIOHBCTL_R |= (1U << 0);
    // enable AFSEL for GPIO pins corresponding to chosen uart module
    GPIO_PORTA_AHB_AFSEL_R |= ((1U << 0) | (1U << 1));
    //enable MUX for GPIO pins GPIOPCTL
    GPIO_PORTA_AHB_PCTL_R |= ((0x01 << 0) | (0x01 << 4));
    // digital enable for UART pins
    GPIO_PORTA_AHB_DEN_R |= ((1U << 0) | (1U << 1));
    // drive current select for SPI pins (8mA)
    //GPIO_PORTA_AHB_DR8R_R |= ((1U << 0) | (1U << 1));
    // slew rate control for uart pins
    //GPIO_PORTA_AHB_SLR_R |= ((1U << 0) | (1U << 1));
    // disable uart0
    UART0_CTL_R &= ~(1U << 0);
    // set baud rate divisors (for 9600 @16MHz)
    UART0_IBRD_R = 104; // integer value
    UART0_FBRD_R = 11; // fraction value
    // for 8-bit data + 1 stop bit + no parity
    UART0_LCRH_R = ((0x03 << 5));
    // choosing default clock source for uart0
    UART0_CC_R = (0x0);
    // enable uart0 + enable transmit + enable receive
    UART0_CTL_R = ((1U << 0) | (1U << 8) | (1U << 9));
    // configure LEDs for displaying output
    SYSCTL_RCGCGPIO_R |= (1U << 5); // enable port F clk
    SYSCTL_GPIOHBCTL_R |= (1U << 5); // enable AHB for port F
    GPIO_PORTF_AHB_DIR_R |= (RED_LED | BLUE_LED | GREEN_LED); // set pins to output
    GPIO_PORTF_AHB_DEN_R |= (RED_LED | BLUE_LED | GREEN_LED); // set digital enable
    // temp variable to hold sent/received data
    unsigned char c = 0;

    while(1)
    {
        c = receive_char();
        send_char(c);
        switch (c)
        {
            case 'r':
                GPIO_PORTF_AHB_DATA_R = RED_LED;
            break;

            case 'g':
                GPIO_PORTF_AHB_DATA_R = GREEN_LED;
            break;

            case 'b':
                GPIO_PORTF_AHB_DATA_R = BLUE_LED;
            break;

            default:
                GPIO_PORTF_AHB_DATA_R = 0x00;
            break;
        }
    }
}

void send_char(char c)
{
    while ((UART0_FR_R & (1U << 5)) != 0);
    UART0_DR_R = c;
}

unsigned char receive_char(void)
{
    unsigned char c;
    while ((UART0_FR_R & (1U << 4)) != 0);
    c = UART0_DR_R;
    return c;
}





