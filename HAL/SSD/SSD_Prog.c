/*
 * SSD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "SSD_Interface.h"
#include "SSD_Private.h"

void H_SSD_Void_SSDInit(void) {
	M_DIO_Void_SetPinDirection(SSD_A_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_B_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_C_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_D_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_E_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_F_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_G_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_H_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_EN, OUTPUT);
	M_DIO_Void_SetPinValue(SSD_EN, LOW);

}
void H_SSD_Void_SSDBlink()
{
	M_DIO_Void_SetPinValue(SSD_EN, HIGH);
	_delay_ms(500);
	M_DIO_Void_SetPinValue(SSD_EN, LOW);
}
void H_SSD_Void_SSDWriteNumber(u8 Copy_U8_Number) {


		u8 Local_U8_Ones = Copy_U8_Number % 10;
		u8 Local_U8_Tens = Copy_U8_Number / 10;
		H_SSD_Void_SSDDigitDisplayTens(Local_U8_Tens);
		H_SSD_Void_SSDDigitDisplayUnits(Local_U8_Ones);


}

static void H_SSD_Void_SSDDigitDisplayTens(u8 Copy_U8_Number) {
	switch (Copy_U8_Number) {
	case 0:
		M_DIO_Void_SetPinValue(SSD_A_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_B_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_C_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 1:
		M_DIO_Void_SetPinValue(SSD_A_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_B_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_C_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 2:
		M_DIO_Void_SetPinValue(SSD_A_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_B_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_C_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 3:
		M_DIO_Void_SetPinValue(SSD_A_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_B_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_C_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 4:
		M_DIO_Void_SetPinValue(SSD_A_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_B_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_C_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 5:
		M_DIO_Void_SetPinValue(SSD_A_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_B_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_C_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 6:
		M_DIO_Void_SetPinValue(SSD_A_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_B_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_C_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 7:
		M_DIO_Void_SetPinValue(SSD_A_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_B_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_C_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_D_PIN, LOW);
		break;
	case 8:
		M_DIO_Void_SetPinValue(SSD_A_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_B_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_C_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_D_PIN, HIGH);
		break;
	case 9:
		M_DIO_Void_SetPinValue(SSD_A_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_B_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_C_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_D_PIN, HIGH);
		break;
	default:
		break;
	}
}
static void H_SSD_Void_SSDDigitDisplayUnits(u8 Copy_U8_Number) {
	switch (Copy_U8_Number) {
	case 0:
		M_DIO_Void_SetPinValue(SSD_E_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_F_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_G_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 1:
		M_DIO_Void_SetPinValue(SSD_E_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_F_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_G_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 2:
		M_DIO_Void_SetPinValue(SSD_E_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_F_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_G_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 3:
		M_DIO_Void_SetPinValue(SSD_E_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_F_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_G_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 4:
		M_DIO_Void_SetPinValue(SSD_E_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_F_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_G_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 5:
		M_DIO_Void_SetPinValue(SSD_E_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_F_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_G_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 6:
		M_DIO_Void_SetPinValue(SSD_E_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_F_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_G_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 7:
		M_DIO_Void_SetPinValue(SSD_E_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_F_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_G_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_H_PIN, LOW);
		break;
	case 8:
		M_DIO_Void_SetPinValue(SSD_E_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_F_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_G_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_H_PIN, HIGH);
		break;
	case 9:
		M_DIO_Void_SetPinValue(SSD_E_PIN, HIGH);
		M_DIO_Void_SetPinValue(SSD_F_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_G_PIN, LOW);
		M_DIO_Void_SetPinValue(SSD_H_PIN, HIGH);
		break;
	default:
		break;
	}

}

