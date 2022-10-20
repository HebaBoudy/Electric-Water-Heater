/*
 * FAN_Prog.c
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO.SXM10
 */

#include"Fan_Interface.h"
#include"Fan_Private.h"
#include"Fan_Configure.h"
void H_Fan_Void_FanInit()
{
	M_DIO_Void_SetPinDirection(FAN_PIN,OUTPUT);
}
void H_Fan_Void_FanSetOn()
{

	M_DIO_Void_SetPinValue(FAN_PIN,HIGH);


}
void H_Fan_Void_FanSetOff()
{
	M_DIO_Void_SetPinValue(FAN_PIN,LOW);

}
u8 H_Fan_U8_FanRead()
{
	return M_DIO_U8_GetPinValue(FAN_PIN);
}
