/*
 *
 *Ahmed Hassan Salama
 *SW_APP
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SSD_interface.h"
#include "BUZ_interface.h"


#define NUM_OF_LEDS    8
#define LOOP(N) for(u8 i = 0; i < N; ++i)


// Define All Configuration for LEDs
LED_Type_t Leds[NUM_OF_LEDS] = {
		{LED_PORTA, LED_PIN0, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN1, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN2, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN3, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN4, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN5, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN6, ACTIVE_HIGH},
		{LED_PORTA, LED_PIN7, ACTIVE_HIGH}
};

SSD_Type SSD1 = {SSD_COMMON_CATHODE, SSD_PORTC, SSD_PORTC, SSD_PIN7};
BUZ_Type BUZ1 = {LED_PORTD, LED_PIN0, ACTIVE_HIGH}                  ;
LED_Type_t RED_led ={LED_PORTD, LED_PIN1, ACTIVE_HIGH};

void main()
{
	SSD_voidInitialDataPort   (SSD1);
	SSD_voidEnable         (SSD1);
	BUZ_voidInit           (BUZ1);
	LED_voidInit            (RED_led);
    LOOP(NUM_OF_LEDS) {
    	LED_voidInit   (Leds[i]);
    }

    while (1)
    {
    	LOOP(NUM_OF_LEDS + 1) {
    		LED_voidOff     (RED_led);

    		if (i == 0) {
			LOOP(8) {
				LED_voidOff   (Leds[i]);
    	                }

    			BUZ_voidOff            (BUZ1);
    			SSD_voidSendNumber     (SSD1, i);
    			_delay_ms(1000);
    		}

    		else {
    			LED_voidOn             (Leds[i - 1]);
    			SSD_voidSendNumber     (SSD1, i);
    			_delay_ms(1000);
    		}
	}
    	SSD_voidSendNumber     (SSD1,9);
    	BUZ_voidOn     (BUZ1);
    	LED_voidOn     (RED_led);
    	_delay_ms(1000);
    }
}

