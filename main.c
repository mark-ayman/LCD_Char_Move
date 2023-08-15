/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: marka
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "MCAL/ADC/ADC_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/LED/LED_interface.h"
#include <util/delay.h>


int main(){

	u8 LCD_Char[] = {
			  0x0E,
			  0x0A,
			  0x04,
			  0x0E,
			  0x15,
			  0x04,
			  0x0A,
			  0x11
				};
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_INPUT);
	//MOTOR DERIVER
	DIO_voidSetPinDirection(DIO_PORTC , DIO_PIN3 , DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC , DIO_PIN4 , DIO_OUTPUT);

	CLCD_voidInit();
	ADC_voidInit();
	CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);

	u16 digital_value;
	u32 analog_value;

	while(1){
		 digital_value= ADC_u16ConvertedValue(ADC_CHANNEL_0);
		 CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
		 analog_value= ( ( ((u32)digital_value)*5000)/1024);
		 CLCD_voidSendExtraChar(0,LCD_Char,CLCD_ROW_1,(analog_value/312));
		// _delay_ms(50);
		// CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
		// _delay_ms(50);
		//CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_1);
		//CLCD_voidSendNumber(analog_value );
		//_delay_ms(250);
		//CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
		//CLCD_voidSetPosition(1,8);
		//value of pot > VAL
		 /*
		if(analog_value>2500){
			//righ
			/*
			for(u8 counter=CLCD_COL_8;counter<16;counter++) {
				CLCD_voidSendExtraChar(0,LCD_Char,CLCD_ROW_1,counter);
				_delay_ms(250);
				CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
				}
				*/

			//}

		//value of pot < VAL
		//if(analog_value<2500){
			//left
			/*for(u8 counter=CLCD_COL_8;counter>0;counter--){
				CLCD_voidSendExtraChar(0,LCD_Char,CLCD_ROW_1,counter);
				_delay_ms(250);
				CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
				}
				*/
			//}
		 if(analog_value>2500){
			 DIO_voidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
			 DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,DIO_LOW);
			 _delay_ms(250);
		 }
		 if(analog_value<2500){
			 DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,DIO_HIGH);
			 DIO_voidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
			  _delay_ms(250);
		 }

	  }
}
