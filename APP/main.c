/*
 * main.c
 *
 *  Created on: Sep 14, 2020
 *      Author: Omar Fahmy
 */

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/External Interrupts/EXIT_Interface.h"
#include "../MCAL/Global Interrupt/GI_Interface.h"

void toggle0(void);

int main (void)
{
	EXIT_U8EXIT0Init();
	EXIT_U8EXIT0Enable();
	EXIT_U8EXIT0SetCallBack(toggle0);
	DIO_U8SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT); // Switch - Input
	DIO_U8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT); // LED0 - Output
	GI_U8Enable();

	while (1)
	{

	}

	return 0;
}

void toggle0(void)
{
	static u8 counts = 0;
	DIO_U8TogglePin(DIO_PORTA, DIO_PIN0);
	if (counts == 3)
	{
		EXIT_U8EXIT0SenseControl(EXIT0_FALLING_EDGE);
	}
	else
	{
		counts++;
	}
}
