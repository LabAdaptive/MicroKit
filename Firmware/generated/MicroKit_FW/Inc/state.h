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

} PinList;


#endif
