/*
 * STM32F030C8T6_irq.c
 *
 *  Created on: 31.08.2019
 *      Author: Pawel
 */

#include <STM32F030C8T6.h>
#include <STM32F030C8T6_irq.h>

/******************************************************************************************
 ********************** Private functions *************************************************
 ******************************************************************************************/

static void SetIRQVector(uint8_t nvicIRQNumber);

static void ResetIRQVector(uint8_t nvicIRQNumber);

/******************************************************************************************
 ********************** Main functions definitions ****************************************
 ******************************************************************************************/

void NVICInitVector(uint8_t nvicIRQNumber){
	ResetIRQVector(nvicIRQNumber);
	SetIRQVector(nvicIRQNumber);
}

void NVICDeInitVector(uint8_t nvicIRQNumber){
	ResetIRQVector(nvicIRQNumber);
}

void NVICPendingRegisterHandling(uint8_t nvicIRQNumber){
	NVIC_p->ICPR |= (ENABLE << nvicIRQNumber);
}

/******************************************************************************************
 ********************** Private functions *************************************************
 ******************************************************************************************/

static void SetIRQVector(uint8_t nvicIRQNumber){
	NVIC_p->ICER &= ~(ENABLE << nvicIRQNumber);
	NVIC_p->ISER |= (ENABLE << nvicIRQNumber);
}

static void ResetIRQVector(uint8_t nvicIRQNumber){
	NVIC_p->ISER &= ~(ENABLE << nvicIRQNumber);
	NVIC_p->ICER |= (ENABLE << nvicIRQNumber);
}
