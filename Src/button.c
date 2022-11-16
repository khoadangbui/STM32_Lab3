/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;

int KeyReg20 = NORMAL_STATE;
int KeyReg21 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;

int KeyReg30 = NORMAL_STATE;
int KeyReg31 = NORMAL_STATE;
int KeyReg32 = NORMAL_STATE;

int KeyReg40 = NORMAL_STATE;
int KeyReg41 = NORMAL_STATE;
int KeyReg42 = NORMAL_STATE;
int TimerForKeyPress = 300;

int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKey1Process(){
	button1_flag = 1;
}
void subKey2Process(){
	button2_flag = 1;
}
void subKey3Process(){
	button3_flag = 1;
}

void getKey1Input(){
	KeyReg10 = KeyReg11;
	KeyReg11 = KeyReg12;
	KeyReg12 = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);

	if ((KeyReg10 == KeyReg11) && (KeyReg11 == KeyReg12)){
		if (KeyReg40 != KeyReg12){                 // nhấn thả
			KeyReg40 = KeyReg12;
			if (KeyReg12 == PRESSED_STATE){
				//TODO
				subKey1Process();
				TimerForKeyPress = 300;
			}
		}
		else{									   // nhấn đè
			TimerForKeyPress--;
			if (TimerForKeyPress == 0){
				if (KeyReg12 == PRESSED_STATE){
					//TODO
					subKey1Process();
					TimerForKeyPress = 300;
				}
			}
		}
	}
}
void getKey2Input(){
	KeyReg20 = KeyReg21;
	KeyReg21 = KeyReg22;
	KeyReg22 = HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);

	if ((KeyReg20 == KeyReg21) && (KeyReg21 == KeyReg22)){
		if (KeyReg41 != KeyReg22){                 // nhấn thả
			KeyReg41 = KeyReg22;
			if (KeyReg22 == PRESSED_STATE){
				//TODO
				subKey2Process();
				TimerForKeyPress = 300;
			}
		}
		else{									 // nhấn đè
			TimerForKeyPress--;
			if (TimerForKeyPress == 0){
				if (KeyReg22 == PRESSED_STATE){
					//TODO
					subKey2Process();
					TimerForKeyPress = 300;
				}
			}
		}
	}
}
void getKey3Input(){
	KeyReg30 = KeyReg31;
	KeyReg31 = KeyReg32;
	KeyReg32 = HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);

	if ((KeyReg30 == KeyReg31) && (KeyReg31 == KeyReg32)){
		if (KeyReg42 != KeyReg32){                 // nhấn thả
			KeyReg42 = KeyReg32;
			if (KeyReg32 == PRESSED_STATE){
				//TODO
				subKey3Process();
				TimerForKeyPress = 300;
			}
		}
		else{									 // nhấn đè
			TimerForKeyPress--;
			if (TimerForKeyPress == 0){
				if (KeyReg32 == PRESSED_STATE){
					//TODO
					subKey3Process();
					TimerForKeyPress = 300;
				}
			}
		}
	}
}
