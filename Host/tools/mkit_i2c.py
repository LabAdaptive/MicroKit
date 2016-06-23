#!/usr/bin/python
import argparse 
import time 
import serial 
import sys
from microkit import MicroKit 
from cdefine import CDefine 

CD = CDefine()
CD.Load('../../Common/MKitCommands.h')

CMD_I2C_PAD        = [0x00]*12    
                         

class mkit_i2c():
	def __init__(self,mkit):
		self.MicroKit = mkit

		self.MicroKit_I2C_Config = {'Enabled'            : 0,
                       				'ClockSpeed'         : CD.defines['I2C_SPEED_100K'],
                       				'GeneralCallDisable' : 0,
                       				'ClockStretching'    : 0}
	def GetConfig(self):
		ret = 0
		cmd = [CD.defines['CMD_ID'],CD.defines['CMD_CLASS_I2C'],0x00,CD.defines['CMD_CLASS_I2C_READ_CFG']] + CMD_I2C_PAD
		ret = self.MicroKit.WriteCommand(cmd)

		self.MicroKit_I2C_Config['Enabled']           = ret[4]
		self.MicroKit_I2C_Config['ClockSpeed']         = ret[5]
		self.MicroKit_I2C_Config['GeneralCallDisable'] = ret[6]
		self.MicroKit_I2C_Config['ClockStretching']    = ret[7]
        
		for items in self.MicroKit_I2C_Config:
			print items + ": " + str(self.MicroKit_I2C_Config[items])

		return 0 

	def SetConfig(self,enable,speed,generalCall,clockStretch):
		self.MicroKit_I2C_Config['Enabled']            = enable
		self.MicroKit_I2C_Config['ClockSpeed']         = speed
		self.MicroKit_I2C_Config['GeneralCallDisable'] = generalCall
		self.MicroKit_I2C_Config['ClockStretching']    = clockStretch
 
		ret = 0
		cmd = [CD.defines['CMD_ID'],CD.defines['CMD_CLASS_I2C'],0x00,CD.defines['CMD_CLASS_I2C_WRITE_CFG']] + [0x00]*12
		cmd = cmd + [self.MicroKit_I2C_Config['Enabled']]
		cmd = cmd + [self.MicroKit_I2C_Config['ClockSpeed']]
		cmd = cmd + [self.MicroKit_I2C_Config['GeneralCallDisable']]
		cmd = cmd + [self.MicroKit_I2C_Config['ClockStretching']]

		ret = self.MicroKit.WriteCommand(cmd)       

		return 0

	def MasterRegWrite8(self,slaveAddress,regAddr,data):
		ret = 0 
		cmd = [CD.defines['CMD_ID'],CD.defines['CMD_CLASS_I2C'],0x00,CD.defines['CMD_CLASS_I2C_M_WRITE'],slaveAddress,regAddr,data] + [0x00]*9
		ret = self.MicroKit.WriteCommand(cmd)
		
		print ret
		return 0

	def MasterRegRead8(self, slaveAddress,regAddr):
		ret = 0 
		cmd = [CD.defines['CMD_ID'],CD.defines['CMD_CLASS_I2C'],0x00,CD.defines['CMD_CLASS_I2C_M_READ'],slaveAddress,regAddr] + [0x00] *10
		ret = self.MicroKit.WriteCommand(cmd)	
        
		retData = ret[5]
		return 0

if __name__ == "__main__":
	MicroKit = MicroKit('/dev/ttyACM0')
	
	i2c = mkit_i2c(MicroKit) 	

	i2c.GetConfig()
	#i2c.MasterRegWrite8(0x55,0xAA,0xFF);     
      
