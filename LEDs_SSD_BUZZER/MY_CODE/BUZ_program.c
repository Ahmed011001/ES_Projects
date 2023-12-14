/*
*---------------------------------------------------------------------------------------------*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   BUZ_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*
*---------------------------------------------------------------------------------------------*
*
* Author  : Ahmed Hassan Salama
* Layer  : HAL
* SWC   : BUZ
*
*/ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_config.h"


#include "BUZ_interface.h"


//----------------------------------------------------------------------------//
/*
* Breif : This Function initialize the pin which connected to buz as output pin
* Parameters :
            => struct has the buz port , pin , status
* return : void 
*/
void BUZ_voidInit( BUZ_Type BUZ_Configuration )
{
	
	DIO_enumSetPinDirection( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_OUTPUT );
	
}

//-----------------------------------------------------------------------------//
/*
* Breif : This Function set high on buz pin ( buz on )
* Parameters :
            => struct has the buz port , pin , status
* return : void 
*/
void BUZ_voidOn  ( BUZ_Type BUZ_Configuration )
{
	
	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_HIGH );
		
	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_LOW  );
		
	}
	
}

//-----------------------------------------------------------------------------//
/*
* Breif : This Function set low on buz pin ( buz off )
* Parameters :
             => struct has the buz port , pin , status
* return : void 
*/
void BUZ_voidOff ( BUZ_Type BUZ_Configuration )
{
	
	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_LOW  );
		
	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_HIGH  );
		
	}
	
}

//-----------------------------------------------------------------------------//
/*
* Breif : This Function toggle buz pin
* Parameters :
             => struct has the buz port , pin , status
* return : void 
*/
void BUZ_voidToggle      ( BUZ_Type BUZ_Configuration )
{
	DIO_enumTogglePinValue  ( BUZ_Configuration.Port , BUZ_Configuration.Pin );
}

