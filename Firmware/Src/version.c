#include "version.h"
#include "tfp_printf.h"

void PrintVersion(){

	printf("MicroKit Controller Firmware\n\r");
	printf("\tMajor Revision: %x\n\r",MICROKIT_MAJOR_REV);
	printf("\tMinor Revision: %x\n\r",MICROKIT_MINOR_REV);
}
