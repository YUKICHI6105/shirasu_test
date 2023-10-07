#include <main.h>

extern "C" {
extern TIM_HandleTypeDef htim1;
extern void kusoOutputCompare(TIM_HandleTypeDef *htim, uint32_t Channel);
extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);
}

uint32_t ARRMax = 300 ;
void kusoOutputCompare(TIM_HandleTypeDef *htim, uint32_t Channel){
	HAL_TIM_OC_Start (&htim1, Channel);
	TIM_CHANNEL_STATE_SET(&htim1, Channel, HAL_TIM_CHANNEL_STATE_READY);
	HAL_TIMEx_OCN_Start(&htim1, Channel);
	TIM_CHANNEL_N_STATE_SET(&htim1, Channel, HAL_TIM_CHANNEL_STATE_READY);
}

uint8_t convertToUint8(uint32_t value) {

    return static_cast<uint8_t>(value & UINT8_MAX);
}

void main_cpp(void)
{
	kusoOutputCompare(&htim1, TIM_CHANNEL_1);
	kusoOutputCompare(&htim1, TIM_CHANNEL_2);
	kusoOutputCompare(&htim1, TIM_CHANNEL_3);
/*	while (true){
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ARRMax/2);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, ARRMax);
	}*/

/*	while(true){
		CDC_Transmit_FS((uint8_t*)ARRMax, 32);
		HAL_Delay(1000);
	}
*/
}

