/*
 * STM32F030C8T6.h
 *
 *  Created on: 16.08.2019
 *      Author: Pawel
 */

#ifndef INC_STM32F030C8T6_H_
#define INC_STM32F030C8T6_H_

#include <stdint.h>

/*****************************************************************
 * ******************** BASE ADDRESSES DEFINES********************
 *****************************************************************/

/*
 * Busses addresses
 */
#define APB_BASE_ADDR			0x40000000
#define AHB1_BASE_ADDR			0x40020000
#define AHB2_BASE_ADDR			0x48000000
#define SRAM_BASE_ADDR			0x20000000
#define FLASH_BASE_ADDR			0x08000000



/*
 * RCC Base Address
 */
#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x1000)



/*
 * GPIO Base Addresses
 */
#define GPIOA_BASE_ADDR			(AHB2_BASE_ADDR)
#define GPIOB_BASE_ADDR			(AHB2_BASE_ADDR + 0x400)
#define GPIOC_BASE_ADDR			(AHB2_BASE_ADDR + 0x800)
#define GPIOD_BASE_ADDR			(AHB2_BASE_ADDR + 0xC00)
//there is no GPIO E port in this MCU
#define GPIOF_BASE_ADDR			(AHB2_BASE_ADDR + 0x1400)



/*
 * EXTI Base Addresses
 */
#define EXTI_BASE_ADDR			(APB_BASE_ADDR + 0x10400)



/*
 * NVIC Base addresses
 */

#define NVIC_ISER0_BASEADDR		0xE000E100						//DOCUMENTATION PM0215

#define NVIC_ICER0_BASEADDR		(NVIC_ISER0_BASEADDR + 0x80)

/*
 * TIMER Base Addresses
 */
#define TIM3_BASE_ADDR			(APB_BASE_ADDR + 0x0400)
#define TIM6_BASE_ADDR			(APB1_BASE_ADDR + 0x1000)	//BASIC TIMER
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR + 0x1400)	//BASIC TIMER







/******************************************************************
 * **************** HANDLE STRUCTURES DEFINES *********************
 ******************************************************************/

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
	volatile uint32_t CFGR3;
	volatile uint32_t CR2;
}RCC_RegDef_t;


typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
	volatile uint32_t BRR;
}GPIO_RegDef_t;

//TODO
//typedef struct
//{
//	volatile uint32_t CR1;
//	volatile uint32_t CR2;
//	volatile uint32_t reserved;
//	volatile uint32_t DIER;
//	volatile uint32_t SR;
//	volatile uint32_t EGR;
//	volatile uint32_t reserved2[3];
//	volatile uint32_t CNT;
//	volatile uint32_t PSC;
//	volatile uint32_t ARR;		//AUTORELOAD REGISTER
//}TIMER6_7_RegDef_t;
//
//typedef struct
//{
//	volatile uint32_t CR1;
//	volatile uint32_t CR2;
//	volatile uint32_t SMCR;
//	volatile uint32_t DIER;
//	volatile uint32_t SR;
//	volatile uint32_t EGR;
//	volatile uint32_t CCMR1;
//	volatile uint32_t CCMR2;
//	volatile uint32_t CCER;
//	volatile uint32_t CNT;
//	volatile uint32_t PSC;
//	volatile uint32_t ARR;		//AUTORELOAD REGISTER
//	volatile uint32_t reserved1;
//	volatile uint32_t CCR1;
//	volatile uint32_t CCR2;
//	volatile uint32_t CCR3;
//	volatile uint32_t CCR4;
//	volatile uint32_t reserved2;
//	volatile uint32_t DCR;
//	volatile uint32_t DMAR;
//}TIMER2_5_RegDef_t;
//
//typedef struct
//{
//	volatile uint32_t IMR;
//	volatile uint32_t EMR;
//	volatile uint32_t RTSR;
//	volatile uint32_t FTSR;
//	volatile uint32_t SWIER;
//	volatile uint32_t PR;
//}EXTI_RegDef_t;

/******************************************************************
 * **************** GPIO Macros ************************************
 ******************************************************************/

#define GPIOA					((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC					((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD					((GPIO_RegDef_t*)GPIOD_BASE_ADDR)

#define GPIOF					((GPIO_RegDef_t*)GPIOF_BASE_ADDR)





/******************************************************************
 * **************** RCC Functions *********************************
 ******************************************************************/
#define RCC_AHBENR_IOPAEN		17
#define RCC_AHBENR_IOPBEN		18
#define RCC_AHBENR_IOPCEN		19
#define RCC_AHBENR_IOPDEN		20

#define RCC_AHBENR_IOPFEN		22

#define RCC_APB1ENR_TIMER2		0
#define RCC_APB1ENR_TIMER3		1
#define RCC_APB1ENR_TIMER6		4
#define RCC_APB1ENR_TIMER7		5


#define RCC_APB1RSTR_TIMER2		0
#define RCC_APB1RSTR_TIMER3		1
#define RCC_APB1RSTR_TIMER6		4
#define RCC_APB1RSTR_TIMER7		5

#define RCC_APB2ENR_EXTI		//todo

#define RCC_p				((RCC_RegDef_t*)RCC_BASE_ADDR)

#define TIMER2					((TIMER2_5_RegDef_t*)TIM2_BASE_ADDR)
#define TIMER3					((TIMER2_5_RegDef_t*)TIM3_BASE_ADDR)
#define TIMER6					((TIMER6_7_RegDef_t*)TIM6_BASE_ADDR)
#define TIMER7					((TIMER6_7_RegDef_t*)TIM7_BASE_ADDR)





/****************************************************************
 * ****************** NVIC and EXTI pointers *****************************
 ****************************************************************/

#define NVIC_pISER0				((volatile uint32_t*)NVIC_ISER0_BASEADDR)

#define NVIC_pICER0				((volatile uint32_t*)NVIC_ICER0_BASEADDR)

#define EXTI_p			((EXTI_RegDef_t*)EXTI_BASE_ADDR)



/***************************************************
 * ******************* IRQ numbers******************
 ***************************************************/


#define IRQ_TIMER2				28
#define IRQ_TIMER3				29
#define IRQ_TIMER6				54
#define IRQ_TIMER7				55
#define IRQ_EXTI0				6
#define IRQ_EXTI1				7
#define IRQ_EXTI2				8
#define IRQ_EXTI3				9
#define IRQ_EXTI4				10
#define IRQ_EXTI9_5				23
#define IRQ_EXTI15_10			40



/***************************************************
 * ******************* IRQ numbers******************
 ***************************************************/

#define EXTI_IMR_FTSR				0
#define EXTI_IMR_RTSR				1


/*****************************************************
 * *********** Generic macros*************************
 *****************************************************/

#define F_CPU					8000000		//CPU frequency is 8MHz
#define ENABLE					1
#define DISABLE					0
#define SET_PNP					0
#define RESET_PNP				1




#endif /* INC_STM32F030C8T6_H_ */