/*
 * ADC_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: First
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADC_CHANNEL_0		0
#define ADC_CHANNEL_1		1
#define ADC_CHANNEL_2		2
#define ADC_CHANNEL_3		3


void ADC_voidInit	(void);

u16 ADC_u16ConvertedValue	(u8 Copy_u8Channel );

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
