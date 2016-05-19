#include "command.h"
#include "usbd_cdc_if.h"

uint8_t WaitForCommand(){

	uint8_t ret = 0;
	uint8_t buffer[64];
	uint16_t length = 0;

	ret = USB_ReceiveBuffer(buffer, &length);
	
	if(ret == 0 && length == 16){
		if(buffer[0] == 0x55){
			ProcessCommand(buffer);
		}
		else{
			return -2;
		}
	}
	else
	{
		return -1;
	}


	return 0;
}

uint8_t ProcessCommand(uint8_t * buffer){
	
	switch(buffer[1]){
		case CMD_CLASS_CFG:
		
			break;
		case CMD_CLASS_REG:

			break;

		case CMD_CLASS_MEM:
		
			break;


		case CMD_CLASS_ADC:

			break;


		case CMD_CLASS_GPIO:

			break;


		case CMD_CLASS_SPI:

			break;


		case CMD_CLASS_UART:

			break;


		case CMD_CLASS_I2C:

			break;

		case CMD_CLASS_JTAG:


			break;


		case CMD_CLASS_PWR:

			break;

		case CMD_CLASS_WIFI:


			break;
	}

}
