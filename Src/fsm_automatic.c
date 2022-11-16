/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_automatic.h"

int count = 10;
int time_duration = 1;
void fsm_traffic_run(){
	switch(status){
	case INIT:
		status = MODE_1_1;
		setTimer2(100);
		count = 10;
		break;
	case MODE_1_1:					// RED1, GREEN2
		//TODO
		HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
		HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
		HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
		HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
		HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
		HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, SET);
		display7SEG_run(count);
		if (timer2_flag == 1){
			status = MODE_1_1;
			setTimer2(100);
			count--;
			if (count <= 7){
				status = MODE_1_2;
			}
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			time_duration = 1;
			setTimer2(100);
		}
		break;
	case MODE_1_2:					// RED1, YELLOW2
		//TODO
		HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
		HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
		HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
		HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
		HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
		HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
		display7SEG_run(count);
		if (timer2_flag == 1){
			status = MODE_1_2;
			setTimer2(100);
			count--;
			if (count <= 5){
				status = MODE_1_3;
			}
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			time_duration = 1;
			setTimer2(100);
		}
		break;
	case MODE_1_3:					// GREEN1, RED2
		//TODO
		HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
		HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
		HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, SET);
		HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, SET);
		HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
		HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
		display7SEG_run(count);
		if (timer2_flag == 1){
			status = MODE_1_3;
			setTimer2(100);
			count--;
			if (count <= 2){
				status = MODE_1_4;
			}
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			time_duration = 1;
			setTimer2(100);
		}
		break;
	case MODE_1_4:					// YELLOW1, RED2
		//TODO
		HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
		HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
		HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
		HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, SET);
		HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
		HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
		display7SEG_run(count);
		if (timer2_flag == 1){
			status = MODE_1_4;
			setTimer2(100);
			count--;
			if (count <= 0){
				status = MODE_1_1;
				count = 10;
			}
		}
		if (isButton1Pressed() == 1){
			status = MODE_2;
			time_duration = 1;
			setTimer2(100);
		}
		break;
	case MODE_2:
		//TODO
		display7SEG_run(time_duration);
		if (isButton2Pressed()) time_duration++;
		if (timer2_flag == 1){
			status = MODE_2;
			setTimer2(100);
		}
		if (isButton3Pressed()){
			TICK = 1000/time_duration;
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
			HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
			HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, SET);
			HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
			HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
		}
		break;
	case MODE_3:
		//TODO
		display7SEG_run(time_duration);
		if (isButton2Pressed()) time_duration++;
		if (timer2_flag == 1){
			status = MODE_2;
			setTimer2(100);
		}
		if (isButton3Pressed()){
			TICK = 1000/time_duration;
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
			HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
			HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
			HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
		}
		break;
	case MODE_4:
		//TODO
		display7SEG_run(time_duration);
		if (isButton2Pressed()) time_duration++;
		if (timer2_flag == 1){
			status = MODE_2;
			setTimer2(100);
		}
		if (isButton3Pressed()){
			TICK = 1000/time_duration;
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
			HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, SET);
			HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
			HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
			HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, SET);
		}
		break;
	default:
		break;
	}
}

