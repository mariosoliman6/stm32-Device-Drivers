/*
 * Matrix_Keypad.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Mario Soliman
 *
 */

#include "Matrix_Keypad.h"

static uint16_t Keypad_Get_Inputs(Matrix_Keypad_t *Keypad) {
	uint16_t Input = Keypad->InputPort->IDR & Keypad->IP_Mask;
	return (Input >> Keypad->InputStartingPin);

}

static void Keypad_Set_Outputs(Matrix_Keypad_t *Keypad, uint8_t OutputState) {

	Keypad->OutputPort->BRR |= Keypad->OP_Mask;
	Keypad->OutputPort->BSRR |= (OutputState << Keypad->OutputStartingPin);

}

static void Keypad_Delay(uint32_t delay_ms) {
	HAL_Delay(delay_ms);

}

void Keypad_Init(Matrix_Keypad_t *Keypad) {
	GPIO_InitTypeDef Config;

	uint8_t Pins = 0;

	for (int x = 0; x < Keypad->Columns; x++) {

		Pins |= 1 << (Keypad->InputStartingPin + x);
	}

	Keypad->IP_Mask = Pins;

	Config.Pin = Pins;
	Config.Mode = GPIO_MODE_INPUT;
	Config.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(Keypad->InputPort, &Config);

	Pins = 0;

	for (int x = 0; x < Keypad->Rows; x++) {

		Pins |= 1 << (Keypad->OutputStartingPin + x);
	}

	Keypad->OP_Mask = Pins;

	Config.Pin = Pins;
	Config.Mode = GPIO_MODE_OUTPUT_PP;
	Config.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(Keypad->OutputPort, &Config);

}

void Keypad_Refresh(Matrix_Keypad_t *Keypad) {
	uint32_t TempKeys = 0;
	uint16_t OutputStat = 1 << (Keypad->Rows - 1);

	uint16_t x = 0;

	do {
		TempKeys <<= Keypad->Columns;
		Keypad_Set_Outputs(Keypad, OutputStat);

		Keypad_Delay(1);

		TempKeys |= Keypad_Get_Inputs(Keypad);
		OutputStat >>= 1;
		x++;

	} while (x < Keypad->Rows);

}

uint8_t Keypad_Get_Key(Matrix_Keypad_t *Keypad, uint8_t Key) {
	return (Keypad->KeysStatus & (1 << Key) ? 1 : 0);
}
