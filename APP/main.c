/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "STD.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "LCD_Interface.h"
#include "SSD_Interface.h"
#include <util/delay.h>
#include "EXT_INT_Interface.h"
#include "LM35_Interface.h"
#include "Timer_Interface.h"
#include "GIE_Interface.h"
#include "ADC_Interface.h"
#include "AT24C16A_Interface.h"
#include"Fan_Interface.h"
#include"HeatingElement_Interface.h"
#include"DIO_Interface.h"
#include"DIO_Private.h"
#include"BitMath.h"
#define True					1
#define False 					0
#define MAXIMUM_TEMPRATURE		75
#define MINIMUM_TEMPRATURE		35
#define HEATER_BLINKING_TIME	5
#define SSD_BLINKING_TIME		5

void A_EXT_INT0_Execution(void);
void A_EXT_INT1_Execution(void);
void A_Timer2_Execution(void);
void A_Timer0_Execution(void);
u32 A_Get_Average_Last_10_Readings(void);

u8 LM35_Reading = 0;
u8 Temprature_Array[10]; //FOR STORING THE LAST 10 READINGS INSTED OF EEPROM
u8 Temprature_Array_Counter = 0;
u8 Enter_Temprature_Setting_Mode = False;
u8 Up_Button_Pressed = False;
u8 Down_Button_Pressed = False;
u8 Set_Temprature = 0;
u8 _1_sec_Counter = 0; //for heater and fan

int main() {
	//FLAG ON WHEN SET TEMP EXCEEDS MAX OR BELOW MIN
	H_LED_Void_LedInit(LED3);
	//FLAG OF HEATING ELEMENT
	H_LED_Void_LedInit(LED1);
	//SEVEN SEGMENT DISPLAY
	H_SSD_Void_SSDInit();
	//COOLING ELEMENT INIT
	H_Fan_Void_FanInit();
	//HEATING ELEMENT INIT
	H_HeatingElement_Void_HeatingElementInit();
	//PUSH BUTTON UP AND DOWN
	M_EXT_INT_Void_ExtIntInit(EXT_INT_0);
	M_EXT_INT_Void_ExtIntInit(EXT_INT_1);
	M_EXT_INT_Void_SetCallBack(EXT_INT_0, A_EXT_INT0_Execution);
	M_EXT_INT_Void_SetCallBack(EXT_INT_1, A_EXT_INT1_Execution);
	//TEMP SENSOR
	H_LM35_Void_LM35Init();
	//H_AT24C16A_Void_EEPROMInit();
	// SET TIMER0 TO 100 MS TO READ TEMP
	M_Timer_Void_TimerInit(TIMER0_CHANNEL);
	M_Timer_Void_SetCallBack(TIMER0_CHANNEL, A_Timer0_Execution);
	M_Timer_Void_TimerSetTime(TIMER0_CHANNEL, 100);
	M_GIE_Void_GlobalInterruptEnable();
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);
	//SET TIMER 2 EVERY 5 SECONDS
	M_Timer_Void_TimerInit(TIMER2_CHANNEL);
	M_Timer_Void_SetCallBack(TIMER2_CHANNEL, A_Timer2_Execution);
	M_Timer_Void_TimerSetTime(TIMER2_CHANNEL, 5000);

	while (1) {
		if (Up_Button_Pressed == True) {

			Set_Temprature = LM35_Reading + 5;
			if (Set_Temprature <= MAXIMUM_TEMPRATURE) {
				H_HeatingElement_Void_HeatingElementStart();
				//H_LED_Void_LedSetOn(LED1);
				H_SSD_Void_SSDWriteNumber(Set_Temprature);
			} else {
				H_SSD_Void_SSDWriteNumber(MAXIMUM_TEMPRATURE);
				//FLAG ON WHEN SET TEMP OUT OF RANGE[MIN-MAX]
				H_LED_Void_LedSetOn(LED3);
				_delay_ms(2000);
				H_LED_Void_LedSetOff(LED3);
			}
			Up_Button_Pressed = False;
		}
		if (Down_Button_Pressed == True) {
			Set_Temprature = LM35_Reading - 5;
			if (Set_Temprature >= MINIMUM_TEMPRATURE) {
				H_Fan_Void_FanSetOn();
				H_LED_Void_LedSetOn(LED1);
				H_SSD_Void_SSDWriteNumber(Set_Temprature);
			} else {
				H_SSD_Void_SSDWriteNumber(MINIMUM_TEMPRATURE);
				//FLAG ON WHEN SET TEMP OUT OF RANGE[MIN-MAX]
				H_LED_Void_LedSetOn(LED3);
				_delay_ms(2000);
				H_LED_Void_LedSetOff(LED3);
			}
			Down_Button_Pressed = False;
		}
		if (LM35_Reading == Set_Temprature) {
			H_Fan_Void_FanSetOff();
			//TURN OFF HEATER/COOLER FLAG
			H_LED_Void_LedSetOff(LED1);
			H_HeatingElement_Void_HeatingElementStop();
		}
	}

	return 0;
}
//DOWN BUTTON PRESSED
void A_EXT_INT1_Execution(void)
{
	if (Enter_Temprature_Setting_Mode == False) {
		//ENTER TEMPRATURE SETTING MODE
		Enter_Temprature_Setting_Mode = True;
	}
	else //TO ENSURE THAT BOTH ARE NOT WORKING TOGETHER
	{
		Down_Button_Pressed = True;
		H_HeatingElement_Void_HeatingElementStop();
		H_LED_Void_LedSetOff(LED1);

	}
//START COUNTING 5 SECOND SO THAT IF UP/DOWN BUTTONS ARE NOT PRESSED -> EXIT TEMP SETTING MODE
	M_Timer_Void_TimerStop(TIMER2_CHANNEL);
	M_Timer_Void_TimerStart(TIMER2_CHANNEL);
}
//UP BUTTON PRESSED
void A_EXT_INT0_Execution(void)
{
	if (Enter_Temprature_Setting_Mode == False) {
		Enter_Temprature_Setting_Mode = True;
	}
	else
	{
		Up_Button_Pressed = True;
		H_Fan_Void_FanSetOff();
		H_LED_Void_LedSetOff(LED1);
	}
	M_Timer_Void_TimerStop(TIMER2_CHANNEL);
	M_Timer_Void_TimerStart(TIMER2_CHANNEL);

}

void A_Timer0_Execution(void) {

	_1_sec_Counter++;

	if (_1_sec_Counter == HEATER_BLINKING_TIME)
	{
		_1_sec_Counter = 0;
		if (H_HeatingElement_U8_HeatingElementRead() == HIGH)
			H_LED_Void_LedTog(LED1);
		_1_sec_Counter = 0;
				if (Enter_Temprature_Setting_Mode == True)
					M_DIO_Void_TogPin(SSD_EN);
				else
					M_DIO_Void_SetPinValue(SSD_EN, LOW);
	}

	LM35_Reading = H_LM35_Void_LM35Read();
	if (Temprature_Array_Counter == 10)
		Temprature_Array_Counter = 0;
	//stores the last ten values of lm35 readings instead of eeprom
	Temprature_Array[Temprature_Array_Counter] = LM35_Reading;
	Temprature_Array_Counter++;
	if (Enter_Temprature_Setting_Mode == False) {
		H_SSD_Void_SSDWriteNumber(LM35_Reading);

	}
}
void A_Timer2_Execution(void) {
	//if up and down buttons are not pressed for 5 seconds , exit temp setting mode and disolay current water temp
	if (Up_Button_Pressed == False && Down_Button_Pressed == False) {
		Enter_Temprature_Setting_Mode = False;
	}

}
//THIS FUNCTION IS USELESS IN SIMULATION MODE -> WILL BE USED IN HARDWARE
u32 A_Get_Average_Last_10_Readings(void)
{
	u8 Local_U8_Counter = 0;
	u32 Local_U32_Sum = 0;

	for (Local_U8_Counter = 0; Local_U8_Counter < 10; Local_U8_Counter++) {
		Local_U32_Sum += Temprature_Array[Local_U8_Counter];
	}
	return (Local_U32_Sum / 10);
}
