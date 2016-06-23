#!/usr/bin/python
import argparse 
import time 
import serial 
import sys
from microkit import MicroKit 
from cdefine import CDefine 

CD = CDefine()
CD.Load('../../Common/MKitCommands.h')

CMD_POWER_PAD        = [0x00]*16    
                         

class mkit_pwm():
	def __init__(self,mkit):
	    self.MicroKit = mkit

	def GetConfig(self):

	    return 0 

	def SetConfig(self,period,duty,channel):
            cmd = CMD_POWER_PAD
            cmd[0] = CD.defines['CMD_ID']
            cmd[1] = CD.defines['CMD_CLASS_PWM']
            cmd[2] = 0x00
            cmd[3] = CD.defines['CMD_CLASS_PWM_WRITE_CFG']
            cmd[4] = channel 
            cmd[5] = (period >> 8)
            cmd[6] = (period & 0x00FF)
            cmd[7] = (duty >> 8)
            cmd[8] = (duty & 0x00FF)

            ret = self.MicroKit.WriteCommand(cmd)       
	    return 0

	def StartPWMChannel(self,channel):
            cmd = CMD_POWER_PAD
            cmd[0] = CD.defines['CMD_ID']
            cmd[1] = CD.defines['CMD_CLASS_PWM']
            cmd[2] = 0x00
            cmd[3] = CD.defines['CMD_CLASS_PWM_START']
            cmd[4] = channel 

            ret = self.MicroKit.WriteCommand(cmd)       

	    return 0

	def StopPWMChannel(self, channel):
            cmd = CMD_POWER_PAD
            cmd[0] = CD.defines['CMD_ID']
            cmd[1] = CD.defines['CMD_CLASS_PWM']
            cmd[2] = 0x00
            cmd[3] = CD.defines['CMD_CLASS_PWM_STOP']
            cmd[4] = channel 

            ret = self.MicroKit.WriteCommand(cmd)       

	    return 0

if __name__ == "__main__":
    MicroKit = MicroKit('/dev/ttyACM0')
	
    pwm = mkit_pwm(MicroKit) 	
    pwm.StartPWMChannel(3) 
    time.sleep(3)
    #pwm.StopPWMChannel(2)
    pwm.SetConfig(839,400,3)
    time.sleep(3)
    #pwm.StartPWMChannel(0)
    time.sleep(3)
    #pwm.StopPWMChannel(0)
    pwm.SetConfig(839,500,3)
    time.sleep(3)
    #pwm.StartPWMChannel(0)
    time.sleep(3)
    #pwm.StopPWMChannel(0)
    pwm.SetConfig(839,600,3)
    time.sleep(3)
    #pwm.StartPWMChannel(0)
              
