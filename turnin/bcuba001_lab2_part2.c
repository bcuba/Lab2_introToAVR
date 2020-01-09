/*	Author: bcuba001
 *  Partner(s) Name: Bennett Cuba
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char cntavail = 0x00;
	
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	if (tmpA == 0x00) { // all parking is open
		cntavail = 0x04;
	} else if(tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08){ // 3 parking spots are open
		cntavail = 0x03;	
	} else if(tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09 || tmpA == 0x0A || tmpA == 0x0C){ // 2 parkings are open
		cntavail = 0x02;
	} else if(tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0D || tmpA == 0x0E){
		cntavail = 0x01;
	} else if(tmpA == 0x0F){
		cntavail = 0x00;
	}
			
	PORTC = cntavail;		
    }
    return 0;
}
