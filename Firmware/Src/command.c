#include "stm32f1xx_hal.h"
#include "command.h"
#include "usbd_cdc_if.h"
#include "state.h"
#include "usb_device.h"

uint8_t WaitForCommand(DeviceConfig *cfg){

	uint8_t ret = 0;
	uint8_t buffer[64];
	uint16_t length = 0;

	ret = USB_ReceiveBuffer(buffer, &length);
	
	if(ret == 0 && length == 16){
		if(buffer[0] == 0x55){
			ProcessCommand(buffer,cfg);
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

uint8_t ProcessCommand(uint8_t * command, DeviceConfig *cfg){	
	switch(command[1]){
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
			ProcessI2C(command,cfg);
			break;

		case CMD_CLASS_JTAG:


			break;


		case CMD_CLASS_PWR:

			break;

		case CMD_CLASS_WIFI:


			break;
	}

	return 0;
}

uint8_t ProcessI2C(uint8_t *command, DeviceConfig *cfg){

	uint8_t ack[16] = {CMD_ID,CMD_CLASS_I2C,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	switch(command[3]){
		case CMD_CLASS_I2C_READ_CFG:
			ack[3] = CMD_CLASS_I2C_READ_CFG;
			ack[4] = cfg->i2c_enabled;

			if(cfg->hi2c2.Init.ClockSpeed == 100000)
				ack[5] = 0x00;
	
			else if(cfg->hi2c2.Init.ClockSpeed == 400000)
				ack[5] = 0x01;

			else
				ack[5] = 0xff;

			ack[6] = (uint8_t)cfg->hi2c2.Init.GeneralCallMode;
			ack[7] = (uint8_t)cfg->hi2c2.Init.NoStretchMode;
			
			USB_SendBuffer(ack,16);
			break;

		case CMD_CLASS_I2C_WRITE_CFG:

			break;

		case CMD_CLASS_I2C_M_READ:

			break;

		case CMD_CLASS_I2C_M_WRITE:

			break;

	}

	return 0;
}
