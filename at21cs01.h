/*
 * at21cs01.h
 *
 *  Created on: Oct 7, 2023
 *      Author: kotzu
 */

#ifndef INC_AT21CS01_H_
#define INC_AT21CS01_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>
#endif /* INC_AT21CS01_H_ */

#define AT21CS01_SPEED_SLOW 0xD0
#define AT21CS01_SPEED_FAST 0xE0

#define AT21CS01_CMD_EEPROMREADWRITE 0xA0

typedef struct {

	uint8_t prefCommunicationSpeed;
	TIM_HandleTypeDef *timer;
	GPIO_TypeDef* TX_RX_GPIO;
	uint16_t TX_RX_GPIO_Pin;
	uint8_t debug;
} AT21CS01_Struct;

void at21cs01_Init(AT21CS01_Struct *settings);
void at21cs01_Connect(void);
void at21cs01_FillWholeMemory(uint8_t byte);
void at21cs01_ReadFromAddress(uint8_t address, uint8_t *readData, uint8_t size);
uint8_t at21cs01_WriteToAddress(uint8_t address, uint8_t Data[],uint8_t size);
