/*
 * ADC_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: First
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"



void ADC_voidInit	(void)
{
	/*
		 * reference volatge = 5 v
		 * Right Adjustment
		 * ADC0
		 * Enable ADC
		 * Disable PIE ((	Polling		))
		 * prescaler / 128
		 * */
		ADMUX_REG =  0b01000000;
		ADCSRA_REG = 0b10010111;
}

u16 ADC_u16ConvertedValue	(u8 Copy_u8Channel )
{
	ADMUX_REG = ADMUX_REG & MASKING_REG ;
	ADMUX_REG |= Copy_u8Channel ;
	u16 Local_u16Conv  = 0 ;
	// Start Conversion
	SET_BIT(ADCSRA_REG , 6 );
	// PIF == 1 -> ADC finish conversion
	while(GET_BIT(ADCSRA_REG , 4) == 0 );

	// Clear Flag
	SET_BIT(ADCSRA_REG , 4) ;
	//Read Converted Data
	Local_u16Conv = (ADCL_REG) | (ADCH_REG << 8) ;

	return Local_u16Conv ;
}
