/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Layer                                       */
/*                                                                            */
/* !Component       : main                                                    */
/* !Description     : Application Entry Point                                 */
/*                                                                            */
/* !Module          : main                                                    */
/* !Description     : Main Module implementation                              */
/*                                                                            */
/* !File            : mian.c                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Embedded Diploma Project-1                              */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */ 
/* !Coded by        : Ahmed Hassan Salama                !Date : NOV 25, 2023 */
/*                                                                            */
/******************************************************************************/

/*! Include compiler types header                                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SW_interface.h"
#include "CLCD_interface.h"

#include "MODE_int.h"

#include "avr/delay.h"

static void vidInit(void);
/***********************************************/
/* Definition of SWs & SSDs  */
SSD_Type R_SSD = {SSD_COMMON_CATHODE, SSD_PORTA, SSD_PORTA, SSD_PIN7};
SSD_Type L_SSD = {SSD_COMMON_CATHODE, SSD_PORTB, SSD_PORTB, SSD_PIN7};

SW_Type L_SW ={DIO_PORTC,DIO_PIN7,SW_Int_PULL_UP};
SW_Type H_SW ={DIO_PORTC,DIO_PIN6,SW_Int_PULL_UP};
SW_Type R_SW ={DIO_PORTC,DIO_PIN5,SW_Int_PULL_UP};

/***********************************************/
void main(void)
{
	/*! Initialize the software                                               */
	vidInit();

	/*! Start the Application                                                 */
	while(1)
	{
		CLCD_voidClearScreen();
		CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
		MODE_vidTask();
		_delay_ms(500);
	}

}

static void vidInit(void)
{
	/*! Initialize HAL layer                                                  */
	// Define SSD1 settings

	    SSD_voidInitialDataPort(R_SSD);
	    SSD_voidInitialDataPort(L_SSD);

	    // Define SW1 settings

	    SW_voidInit(R_SW);
	    SW_voidInit(L_SW);
	    SW_voidInit(H_SW);

	    /*Initialize LCD pins direction*/
	    CLCD_voidInit();
        /*Initialize MODE */
	    MODE_vidInit();

	


}
