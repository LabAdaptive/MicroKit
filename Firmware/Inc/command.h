#ifndef COMMAND_H
#define COMMAND_H

#include "state.h"

#define CMD_ID 0x55


#define CMD_CLASS_CFG  0x00
#define CMD_CLASS_REG  0x01
#define CMD_CLASS_MEM  0x02
#define CMD_CLASS_ADC  0x03
#define CMD_CLASS_GPIO 0x04
#define CMD_CLASS_SPI  0x05
#define CMD_CLASS_UART 0x06
#define CMD_CLASS_I2C  0x07
#define CMD_CLASS_JTAG 0x08
#define CMD_CLASS_PWR  0x09
#define CMD_CLASS_WIFI 0x0A


// I2C Command Defines
#define CMD_CLASS_I2C_READ_CFG  0x00
#define CMD_CLASS_I2C_WRITE_CFG 0x01
#define CMD_CLASS_I2C_M_READ    0x02
#define CMD_CLASS_I2C_M_WRITE   0x03

#define I2C_SPEED_100K 0x00
#define I2C_SPEED_400K 0x01

uint8_t WaitForCommand(DeviceConfig *cfg);

uint8_t ProcessCommand(uint8_t * command, DeviceConfig *cfg);

uint8_t ProcessI2C(uint8_t *command, DeviceConfig *cfg);
#endif 
