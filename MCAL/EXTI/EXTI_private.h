/*
 * EXTI_private.h
 *
 *  Created on: Aug 12, 2023
 *      Author: First
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


#define MCUCR_REG		*(	(	volatile u8*	)	0x55	)
#define MCUCSR_REG		*(	(	volatile u8*	)	0x54	)
#define GICR_REG		*(	(	volatile u8*	)	0x5B	)
#define GIFR_REG		*(	(	volatile u8*	)	0x5A	)

#define EXTI_INT2_BIT	5
#define EXTI_INT0_BIT	6
#define EXTI_INT1_BIT	7

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
