#include "state.h"


static inline void SetBit64(uint64_t *x, uint8_t bitNum) {
    *x |= (1L << bitNum);
}

static inline void ClearBit64(uint64_t *x, uint8_t bitNum) {
    *x &= ~(1L << bitNum);
}

static inline uint8_t CheckPinState(uint64_t * pinState, uint8_t pinToCheck){
	
	return (uint8_t)((*pinState) >> pinToCheck);
}

uint8_t InitDeviceConfig(DeviceConfig * x){
  //ADC1 state config
  x->hadc1.Instance = ADC1;
  x->hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  x->hadc1.Init.ContinuousConvMode = DISABLE;
  x->hadc1.Init.DiscontinuousConvMode = DISABLE;
  x->hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  x->hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  x->hadc1.Init.NbrOfConversion = 1;
  x->sConfig1.Channel = ADC_CHANNEL_0;
  x->sConfig1.Rank = 1;
  x->sConfig1.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

  //ADC2 state config
  x->hadc2.Instance = ADC2;
  x->hadc2.Init.ScanConvMode = ADC_SCAN_DISABLE;
  x->hadc2.Init.ContinuousConvMode = DISABLE;
  x->hadc2.Init.DiscontinuousConvMode = DISABLE;
  x->hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  x->hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  x->hadc2.Init.NbrOfConversion = 1;
  x->sConfig2.Channel = ADC_CHANNEL_11;
  x->sConfig2.Rank = 1;
  x->sConfig2.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

  //I2C state config
  x->hi2c2.Instance = I2C2;
  x->hi2c2.State    = HAL_I2C_STATE_RESET;
  x->hi2c2.Init.ClockSpeed = 400000;
  x->hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  x->hi2c2.Init.OwnAddress1 = 0;
  x->hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  x->hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  x->hi2c2.Init.OwnAddress2 = 0;
  x->hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  x->hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_ENABLE;
 
  x->i2c_enabled = 1;

  //SPI state config
  x->hspi2.Instance = SPI2;
  x->hspi2.Init.Mode = SPI_MODE_MASTER;
  x->hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  x->hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  x->hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  x->hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  x->hspi2.Init.NSS = SPI_NSS_HARD_INPUT;
  x->hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  x->hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  x->hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  x->hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  x->hspi2.Init.CRCPolynomial = 10;

  //PWM/Timer config 
  x->htim4.Instance = TIM4;
  x->htim4.State = HAL_TIM_STATE_RESET;
  x->htim4.Init.Prescaler = 0;
  x->htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  x->htim4.Init.Period = 8399;
  x->htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  x->sTIMMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  x->sTIMMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

  x->TIMConfigOC1.OCMode = TIM_OCMODE_PWM1;
  x->TIMConfigOC1.Pulse = 8399;
  x->TIMConfigOC1.OCPolarity = TIM_OCPOLARITY_HIGH;
  x->TIMConfigOC1.OCFastMode = TIM_OCFAST_DISABLE;    

  x->TIMConfigOC2.OCMode = TIM_OCMODE_PWM1;
  x->TIMConfigOC2.Pulse = 0;
  x->TIMConfigOC2.OCPolarity = TIM_OCPOLARITY_HIGH;
  x->TIMConfigOC2.OCFastMode = TIM_OCFAST_DISABLE;  

  x->TIMConfigOC3.OCMode = TIM_OCMODE_PWM1;
  x->TIMConfigOC3.Pulse = 0;
  x->TIMConfigOC3.OCPolarity = TIM_OCPOLARITY_HIGH;
  x->TIMConfigOC3.OCFastMode = TIM_OCFAST_DISABLE;  

  x->TIMConfigOC4.OCMode = TIM_OCMODE_PWM1;
  x->TIMConfigOC4.Pulse = 0;
  x->TIMConfigOC4.OCPolarity = TIM_OCPOLARITY_HIGH;
  x->TIMConfigOC4.OCFastMode = TIM_OCFAST_DISABLE;  

  //wifi uart 
  x->huart3.Instance = USART3;
  x->huart3.Init.BaudRate = 115200;
  x->huart3.Init.WordLength = UART_WORDLENGTH_8B;
  x->huart3.Init.StopBits = UART_STOPBITS_1;
  x->huart3.Init.Parity = UART_PARITY_NONE;
  x->huart3.Init.Mode = UART_MODE_TX_RX;
  x->huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  x->huart3.Init.OverSampling = UART_OVERSAMPLING_16;

}





