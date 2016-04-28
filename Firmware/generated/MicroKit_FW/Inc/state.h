#ifndef DEV_STATE
#define DEV_STATE

#include "stm32f1xx_hal.h"


static inline void SetBit64(uint64_t *x, uint8_t bitNum);
static inline void ClearBit64(uint64_t *x, uint8_t bitNum);
static inline uint8_t CheckPinState(uint64_t * pinState, uint8_t pinToCheck);

uint8_t InitPinStates(uint64_t * pinState);
uint8_t CheckPinState(uint64_t * pinState, uint8_t pinToCheck);

typedef struct {
	uint64_t state;
	uint64_t usable;
	uint64_t direction;
	uint64_t defaultVal;
	
	ADC_HandleTypeDef hadc1;
	ADC_HandleTypeDef hadc2;

	I2C_HandleTypeDef hi2c2;

	SPI_HandleTypeDef hspi2;

	TIM_HandleTypeDef htim4;

	UART_HandleTypeDef huart3;
} PinList;


#endif
