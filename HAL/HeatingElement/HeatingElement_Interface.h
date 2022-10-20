/*
 * HeatingElement_Interface.h
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO.SXM10
 */

#ifndef HAL_HEATINGELEMENT_HEATINGELEMENT_INTERFACE_H_
#define HAL_HEATINGELEMENT_HEATINGELEMENT_INTERFACE_H_
#include"STD.h"
#include"BitMath.h"
#include"DIO_Interface.h"
#include"HeatingElement_Configure.h"

void H_HeatingElement_Void_HeatingElementInit();
void H_HeatingElement_Void_HeatingElementStart();
void H_HeatingElement_Void_HeatingElementStop();
u8   H_HeatingElement_U8_HeatingElementRead();
void H_HeatingElement_U8_HeatingElementBlink();

#endif /* HAL_HEATINGELEMENT_HEATINGELEMENT_INTERFACE_H_ */
