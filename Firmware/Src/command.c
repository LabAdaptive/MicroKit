#include "stm32f1xx_hal.h"
#include "command.h"
#include "usbd_cdc_if.h"
#include "state.h"
#include "usb_device.h"

#include "../../Common/MKitCommands.h"

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


		case CMD_CLASS_PWM:
                        ProcessPWM(command,cfg);

			break;

		case CMD_CLASS_WIFI:


			break;
	}

	return 0;
}

uint8_t ProcessI2C(uint8_t *command, DeviceConfig *cfg){
	HAL_StatusTypeDef ret = HAL_OK;
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
			//DeInit I2C Controller 
			HAL_I2C_MspDeInit(&cfg->hi2c2);

			if(command[5] == 0x00)
				cfg->hi2c2.Init.ClockSpeed  = 100000;
	
			else if(command[5] = 0x01)
				cfg->hi2c2.Init.ClockSpeed = 400000;

			else
				cfg->hi2c2.Init.ClockSpeed = 100000;
			
			cfg->hi2c2.Init.GeneralCallMode = command[6];
			cfg->hi2c2.Init.NoStretchMode   = command[7];
		
			//ReInit with new config options 
			HAL_I2C_MspInit(&cfg->hi2c2);

			ack[3] = CMD_CLASS_I2C_WRITE_CFG;
			ack[4] = 0x00;
	
			//send ack response 
			USB_SendBuffer(ack,16);
			break;

		case CMD_CLASS_I2C_M_READ:
			ack[3] = CMD_CLASS_I2C_M_READ;

			ack[5] = 0xff;
			ack[6] = 0xff;

			//write reg offset
			ret = HAL_I2C_Master_Transmit(&cfg->hi2c2,(uint16_t)command[4],&command[5],1,3000);
		
			ack[5] = ret;
		
			//if first write completed successfully 
			if (ack[5] == 0x00){
				//write data 
				ret = HAL_I2C_Master_Receive(&cfg->hi2c2,(uint16_t)command[4],&ack[4],1,3000);
				ack[6] = 0x01;	
					
			}
			
			USB_SendBuffer(ack,16);
			break;

		case CMD_CLASS_I2C_M_WRITE:
			ack[3] = CMD_CLASS_I2C_M_WRITE;

			ack[5] = 0xff;
			ack[6] = 0xff;

			//write reg offset
			ret = HAL_I2C_Master_Transmit(&cfg->hi2c2,(uint16_t)command[4],&command[5],1,3000);
			ack[5] = ret;
					
			
			//if first write completed successfully 
			if (ack[5] == 0x00){
				//write data 
				ret = HAL_I2C_Master_Transmit(&cfg->hi2c2,(uint16_t)command[4],&command[6],1,3000);
					
				ack[6] = ret;
				}
			
			USB_SendBuffer(ack,16);
			break;

	}

	return 0;
}

uint8_t ProcessPWM(uint8_t *command, DeviceConfig *cfg){
	HAL_StatusTypeDef ret = HAL_OK;
	uint8_t ack[16] = {CMD_ID,CMD_CLASS_PWM,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
        uint32_t channel = 0; 
        uint16_t period = 0;
        uint16_t duty = 0;        
        switch(command[3]){
                case CMD_CLASS_PWM_READ_CFG:
                    break;
                    
                case CMD_CLASS_PWM_WRITE_CFG:
                    period = ((command[5] << 8) | (command[6]));                    
                    duty   = ((command[7] << 8) | (command[8]));
                    //cfg->htim4.Init.Period = period; 
                    
                    //HAL_TIM_PWM_DeInit(&(cfg->htim4));
                    //HAL_TIM_OC_DeInit(&(cfg->htim4));
            
                    //HAL_TIM_PWM_Init(&(cfg->htim4));
                    //HAL_TIM_OC_Init(&(cfg->htim4));
                    //HAL_TIMEx_MasterConfigSynchronization(&(cfg->htim4),&(cfg->sTIMMasterConfig));
               
                    if(command[4] == 0x00){
                        cfg->TIMConfigOC1.Pulse = 1000;
                        HAL_TIM_PWM_ConfigChannel(&(cfg->htim4),&(cfg->TIMConfigOC1),TIM_CHANNEL_1);
                    }
                    else if(command[4] == 0x01){
                        cfg->TIMConfigOC2.Pulse = duty;
                        //HAL_TIM_PWM_ConfigChannel(&(cfg->htim4),&(cfg->TIMConfigOC2),TIM_CHANNEL_2);
                    }
                    else if(command[4] == 0x02){
                        cfg->TIMConfigOC3.Pulse = duty;
                        //HAL_TIM_PWM_ConfigChannel(&(cfg->htim4),&(cfg->TIMConfigOC3),TIM_CHANNEL_3);
                    }
                    else if(command[4] == 0x03){
                        cfg->TIMConfigOC4.Pulse = duty;
                        //HAL_TIM_PWM_ConfigChannel(&(cfg->htim4),&(cfg->TIMConfigOC4),TIM_CHANNEL_4);
                    }
                    else{
                        return -1;
                    } 


                    //HAL_TIM_MspPostInit(&(cfg->htim4));

                    ack[3] = CMD_CLASS_PWM_WRITE_CFG;
                    USB_SendBuffer(ack,16);
                    break;

		case CMD_CLASS_PWM_START:
                    if(command[4] == 0x00){
                        channel = TIM_CHANNEL_1;
                    }
                    else if(command[4] == 0x01){
                        channel = TIM_CHANNEL_2;

                    }
                    else if(command[4] == 0x02){
                        channel = TIM_CHANNEL_3;
                    }
                    else if(command[4] == 0x03){
                        channel = TIM_CHANNEL_4;
                    }
                    else{
                        return -1;
                    }
                    

                    HAL_TIM_PWM_Start(&(cfg->htim4),channel);
                    ack[3] = CMD_CLASS_PWM_READ_CFG;
                    USB_SendBuffer(ack,16);            
                    break;

                case CMD_CLASS_PWM_STOP:
                    if(command[4] == 0x00){
                        channel = TIM_CHANNEL_1;
                    }
                    else if(command[4] == 0x01){
                        channel = TIM_CHANNEL_2;

                    }
                    else if(command[4] == 0x02){
                        channel = TIM_CHANNEL_3;
                    }
                    else if(command[4] == 0x03){
                        channel = TIM_CHANNEL_4;
                    }
                    else{
                        return -1;
                    }
                    

                    HAL_TIM_PWM_Stop(&(cfg->htim4),channel);
                    ack[3] = CMD_CLASS_PWM_STOP;
                    USB_SendBuffer(ack,16);

                    break;
        }
    return 0;
    
}

