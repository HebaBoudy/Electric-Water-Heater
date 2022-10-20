/*
 * FAN_Interface.h
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO.SXM10
 */

#ifndef HAL_FAN_FAN_INTERFACE_H_
#define HAL_FAN_FAN_INTERFACE_H_
#include"DIO_Interface.h"
#include"BitMath.h"
#include"STD.h"

void H_Fan_Void_FanInit();
void H_Fan_Void_FanSetOn();
void H_Fan_Void_FanSetOff();
u8 H_Fan_U8_FanRead();



#endif /* HAL_FAN_FAN_INTERFACE_H_ */
