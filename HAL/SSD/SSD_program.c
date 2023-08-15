/*
 * SSD_program.c
 *
 *  Created on: Aug 3, 2023
 *      Author: First
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


void SSD_voidInit			(SSD_t * Copy_pstructSSD)
{
	/* Port - > OUTPUT*/
	DIO_voidSetPortDirection(Copy_pstructSSD -> Port , DIO_OUTPUT );
	/*Disable the ssd*/
	switch(Copy_pstructSSD->CommonState)
	{
	case SSD_COMMON_ANODE:
		DIO_voidSetPortValue(Copy_pstructSSD->Port , 0xff );
		break ;
	case SSD_COMMON_CATHODE :
		DIO_voidSetPortValue(Copy_pstructSSD->Port , 0x00 );
		break ;
	default :
		break;
	}

}
void SSD_voidEnable			(SSD_t * Copy_pstructSSD ,u8 Copy_u8Number )
{
	switch( Copy_pstructSSD -> CommonState)
	{
	case SSD_COMMON_CATHODE :
		DIO_voidSetPortValue(Copy_pstructSSD -> Port ,ArrayNumbers[Copy_u8Number] );
		break ;
	case SSD_COMMON_ANODE :
		DIO_voidSetPortValue(Copy_pstructSSD -> Port , ~ArrayNumbers[Copy_u8Number] );
		break;
	}
}
void SSD_voidDisable		(SSD_t * Copy_pstructSSD)
{
	/*Disable the ssd*/
		switch(Copy_pstructSSD->CommonState)
		{
		case SSD_COMMON_ANODE:
			DIO_voidSetPortValue(Copy_pstructSSD->Port , 0xff );
			break ;
		case SSD_COMMON_CATHODE :
			DIO_voidSetPortValue(Copy_pstructSSD->Port , 0x00 );
			break ;
		default :
			break;
		}
}
