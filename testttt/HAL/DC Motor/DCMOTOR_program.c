/*
 * Dc_Motor.c
 *
 * Created: 2023-12-08 4:12:28 AM
 *  Author: Abdelrahman Ellithy
 */

 

#include "../../LIB/BIT_OPERATIONS.h"

#include "DCMOTOR_Interface.h"
void DCMOTOR_Control (DCMOTOR * DcMotor)
{
	switch (DcMotor->State)
	{
		case DCMOTOR_FW:
			DIO_PIN_write(DcMotor->DcMotorPort,DcMotor->DcMotorPinA,DIO_PIN_HIGH);
			DIO_PIN_write(DcMotor->DcMotorPort,DcMotor->DcMotorPinB,DIO_PIN_LOW);
			break;
		case DCMOTOR_BK:
			DIO_PIN_write(DcMotor->DcMotorPort,DcMotor->DcMotorPinA,DIO_PIN_LOW);
			DIO_PIN_write(DcMotor->DcMotorPort,DcMotor->DcMotorPinB,DIO_PIN_HIGH);
			break;
		case DCMOTOR_STOP :
			DIO_PIN_write(DcMotor->DcMotorPort,DcMotor->DcMotorPinA,DIO_PIN_LOW);
			DIO_PIN_write(DcMotor->DcMotorPort,DcMotor->DcMotorPinB,DIO_PIN_LOW);
			break;
	}
}
