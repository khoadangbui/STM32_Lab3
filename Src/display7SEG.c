/*
 * display7SEG.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */
#include "display7SEG.h"

void display7SEG_run(int num){
	if (num == 10){ GPIOB->ODR = 0xB092; }
	if (num == 1) { GPIOB->ODR = 0xF9F9; }
	if (num == 2) { GPIOB->ODR = 0xA4A4; }
	if (num == 3) { GPIOB->ODR = 0xB0F9; }
	if (num == 4) { GPIOB->ODR = 0x99A4; }
	if (num == 5) { GPIOB->ODR = 0x92B0; }
	if (num == 6) { GPIOB->ODR = 0xF9F9; }
	if (num == 7) { GPIOB->ODR = 0xA4A4; }
	if (num == 8) { GPIOB->ODR = 0xF9B0; }
	if (num == 9) { GPIOB->ODR = 0xA499; }
}
