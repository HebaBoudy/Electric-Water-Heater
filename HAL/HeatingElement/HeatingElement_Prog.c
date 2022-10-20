/*
 * HeatingElement_Prog.c
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO.SXM10
 */
#include"HeatingElement_Interface.h"
#include"HeatingElement_Private.h"
void H_HeatingElement_Void_HeatingElementInit()
{
	M_DIO_Void_SetPinDirection(HEATING_ELEMENT_PIN,OUTPUT);
}
void H_HeatingElement_Void_HeatingElementStart()
{
	M_DIO_Void_SetPinValue(HEATING_ELEMENT_PIN,HIGH);
}
void H_HeatingElement_Void_HeatingElementStop()
{
	M_DIO_Void_SetPinValue(HEATING_ELEMENT_PIN,LOW);

}
u8 H_HeatingElement_U8_HeatingElementRead()
{
	return M_DIO_U8_GetPinValue(HEATING_ELEMENT_PIN);

}
void H_HeatingElement_U8_HeatingElementBlink()
{
	M_DIO_Void_TogPin(HEATING_ELEMENT_PIN);
}
