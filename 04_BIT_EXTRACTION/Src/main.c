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

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdio.h>
#include <stdint.h>

int main(void)
{
	 uint16_t data = 0xB410;

	 /*
	  * This is just an example with numbers but it should be done with pointers.
	  * End result is 0x002A, we discard 00 and we keep 2A, the relevant data.
	  *
	  * You first need to see where the data you need relies into the registry and then
	  * you move it with the proper shift to reach the LSB, then you export it with the
	  * bitmask that preserves the moved bits to extract them.
	  */

	 uint8_t extracted_portion = (uint8_t) ((data >> 9) & 0x003F);

	 printf("Extracted bits of data: %x: ", extracted_portion);

	for(;;);
}
