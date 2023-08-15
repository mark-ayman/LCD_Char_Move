/*
 * EXTI_interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: First
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#define EXTI_RAISING_EDGE		0
#define EXTI_FALLING_EDGE		1
#define EXTI_ON_CHANGE			2
#define EXTI_LOW_LEVEL			3

#define EXTI_INT0				0
#define EXTI_INT1				1
#define EXTI_INT2				2

void EXTI_voidInit	(	void	);

void EXTI_voidChangeSenseControl	(u8 Copy_u8IntId	,	u8 Copy_u8SenseControl	);

void EXTI_voidEnable	(u8 Copy_u8IntId);
void EXTI_voidDisable	(u8 Copy_u8IntId);

void EXTI_voidSetCallBack	(u8 Copy_u8IntId , void (*Pf) (void)	);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
