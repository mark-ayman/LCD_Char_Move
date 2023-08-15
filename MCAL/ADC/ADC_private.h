/*
 * ADC_private.h
 *
 *  Created on: Aug 14, 2023
 *      Author: First
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX_REG		*((volatile u8*)0x27)
#define ADCSRA_REG		*((volatile u8*)0x26)
#define ADCL_REG		*((volatile u8*)0x24)
#define ADCH_REG		*((volatile u8*)0x25)
#define SFIOR_REG		*((volatile u8*)0x50)


#define ADC_REG			*((volatile u16*)0x24)

#define MASKING_REG 0b11100000

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
