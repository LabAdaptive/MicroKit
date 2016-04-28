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

uint8_t InitPinList(PinList * x){

	/* pin state struct, each bit represents one of the 64 pins
       state:  0 gpio , 1 special function
       usable: 0 not available, 1 available 
       direction: 0 input, 1 output */

	x->state      = 0x360c000f3579e200;
	x->usable     = 0x37ff21ff3ff9e800;
	x->direction  = 0x37f7210b30800600;
    x->defaultVal = 
}





