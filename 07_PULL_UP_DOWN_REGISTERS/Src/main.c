/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/*
	Using Pull up/down registers to clear the state of the PA0 pin.
 	THe logic is to trigger a resistor to see the changing state between
 	HIGH and LOW.
 */


#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdio.h>
#include <stdint.h>
#include "main.h"

#define RCC_AHB1ENR 0x40023830;

#define GPIOA_MODER 0x40020000;
#define GPIOA_IDR   0x40020010;
#define GPIOA_PUPDR 0x4002000C;

#define GPIOD_MODER 0x40020C00;
#define GPIOD_ODR   0x40020C14;

int main(void)
{
	volatile RCC_AHB1ENR_t *const pRCC_AHB1 = (RCC_AHB1ENR_t*)RCC_AHB1ENR;

	volatile GPIOx_PUPDR_t *const pGPIOA_pupdreg = (GPIOx_PUPDR_t*)GPIOA_PUPDR;
	volatile GPIOx_MODER_t *const pGPIOA_pin_mode = (GPIOx_MODER_t*)GPIOA_MODER;
	volatile const GPIOx_IDR_t *const pGPIOA_pin = (GPIOx_IDR_t*)GPIOA_IDR;

	volatile GPIOx_MODER_t *const pGPIOD_pin_mode = (GPIOx_MODER_t*)GPIOD_MODER;
	volatile GPIOx_ODR_t *const pGPIOD_pin = (GPIOx_ODR_t*)GPIOD_ODR;

	pRCC_AHB1->gpioa_en = 1;
	pRCC_AHB1->gpiod_en = 1;

	pGPIOA_pin_mode->pin_0 = 0;
	pGPIOD_pin_mode->pin_12 = 1;

	//if PA0 HIGH, turn on LED4, else turn OFF and put PA0 to LOW
	while(1) {
		if (pGPIOA_pin->pin_0) {
			pGPIOD_pin->pin_12 = 1;
		} else {
			pGPIOA_pupdreg->pin_0 = 2;
			pGPIOD_pin->pin_12 = 0;

		}
	}
}
