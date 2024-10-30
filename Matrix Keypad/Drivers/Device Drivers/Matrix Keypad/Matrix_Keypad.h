/*
 * Matrix_Keypad.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Mario Soliman
 */

#ifndef DEVICE_DRIVERS_MATRIX_KEYPAD_MATRIX_KEYPAD_H_
#define DEVICE_DRIVERS_MATRIX_KEYPAD_MATRIX_KEYPAD_H_

#include "stdint.h"

#include "stm32f1xx_hal.h"

typedef struct {

	uint8_t Rows;
	uint8_t Columns;

	uint32_t KeysStatus;

	GPIO_TypeDef *InputPort;
	GPIO_TypeDef *OutputPort;

	uint8_t InputStartingPin;
	uint8_t OutputStartingPin;

	uint16_t IP_Mask;
	uint16_t OP_Mask;

} Matrix_Keypad_t;


void Keypad_Init(Matrix_Keypad_t *Keypad);
void Keypad_Refresh(Matrix_Keypad_t *Keypad);
uint8_t Keypad_Get_Key(Matrix_Keypad_t *Keypad, uint8_t Key);


#endif /* DEVICE_DRIVERS_MATRIX_KEYPAD_MATRIX_KEYPAD_H_ */
