#ifndef COMMAND_H
#define COMMAND_H

#include "state.h"

uint8_t WaitForCommand(DeviceConfig *cfg);

uint8_t ProcessCommand(uint8_t * command, DeviceConfig *cfg);

uint8_t ProcessI2C(uint8_t *command, DeviceConfig *cfg);
uint8_t ProcessPWM(uint8_t *command, DeviceConfig *cfg);
uint8_t ProcessPWR(uint8_t *command, DeviceConfig *cfg);
#endif 
