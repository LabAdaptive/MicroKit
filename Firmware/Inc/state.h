#ifndef DEV_STATE
#define DEV_STATE

#include "stm32f1xx_hal.h"

typedef struct {	
	ADC_HandleTypeDef hadc1;
        ADC_ChannelConfTypeDef sConfig1;
	ADC_HandleTypeDef hadc2;
        ADC_ChannelConfTypeDef sConfig2;
	I2C_HandleTypeDef hi2c2;
	SPI_HandleTypeDef hspi2;
	TIM_HandleTypeDef htim4;
        TIM_MasterConfigTypeDef sTIMMasterConfig;
        TIM_OC_InitTypeDef TIMConfigOC1;
        TIM_OC_InitTypeDef TIMConfigOC2;
        TIM_OC_InitTypeDef TIMConfigOC3;
        TIM_OC_InitTypeDef TIMConfigOC4;
	UART_HandleTypeDef huart3;

	uint8_t i2c_enabled;
} DeviceConfig;

static inline void SetBit64(uint64_t *x, uint8_t bitNum);
static inline void ClearBit64(uint64_t *x, uint8_t bitNum);

uint8_t InitDeviceConfig(DeviceConfig * x);




#endif
