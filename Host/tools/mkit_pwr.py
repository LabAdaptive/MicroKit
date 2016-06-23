#!/usr/bin/python
import argparse 
import time 
import serial 
import sys
from mkit_pwm import mkit_pwm
from microkit import MicroKit 
from cdefine import CDefine 

CD = CDefine()
CD.Load('../../Common/MKitCommands.h')

CMD_POWER_PAD        = [0x00]*16    


class PowerSupply():
    def __init__(self,name,channel):
        self.name = name
        self.status = 0
        self.trim = 0
        self.trim_channel = channel
        self.boost_sel = 0
                         


class mkit_pwr():
	def __init__(self,mkit):
	    self.MicroKit = mkit
            self.pwm = mkit_pwm(mkit)
            self.period = 893

            VA0 = PowerSupply('VA0',0x03)
            VA1 = PowerSupply('VA1',0x02)
            BOOST = PowerSupply('BOOST',-1)
            self.supplies = {VA0.name:VA0,VA1.name:VA1,BOOST.name:BOOST}
        
	def GetStatus(self):
            cmd = CMD_POWER_PAD
            cmd[0] = CD.defines['CMD_ID']
            cmd[1] = CD.defines['CMD_CLASS_PWR']
            cmd[2] = 0x00
            cmd[3] = CD.defines['CMD_CLASS_PWR_STAT']

            ret = self.MicroKit.WriteCommand(cmd)
            for i in range(len(ret)):
                ret[i] = int(ret[i],16)
            self.supplies['VA0'].status         = ret[4]
            self.supplies['VA0'].trim           = (0xFFFF & ((ret[5] << 8) | ret[6]))
            self.supplies['VA1'].status         = ret[7]
            self.supplies['VA1'].trim           = (0xFFFF & ((ret[8] << 8) | ret[9]))
            self.supplies['BOOST'].status       = ret[10]
            self.supplies['BOOST'].boost_sel    = ret[11]

            for sup in self.supplies:
                print "Supply:",self.supplies[sup].name
                print "State:",self.supplies[sup].status
                print "Trim:",hex(self.supplies[sup].trim)
                print "Boost:",self.supplies[sup].boost_sel

	    return 0 

	def EnableChannel(self,channel):
            cmd = CMD_POWER_PAD
            cmd[0] = CD.defines['CMD_ID']
            cmd[1] = CD.defines['CMD_CLASS_PWR']
            cmd[2] = 0x00
            cmd[3] = CD.defines['CMD_CLASS_PWR_ON']
            cmd[4] = channel 

            ret = self.MicroKit.WriteCommand(cmd)       

	    return 0

	def DisableChannel(self, channel):
            cmd = CMD_POWER_PAD
            cmd[0] = CD.defines['CMD_ID']
            cmd[1] = CD.defines['CMD_CLASS_PWR']
            cmd[2] = 0x00
            cmd[3] = CD.defines['CMD_CLASS_PWR_OFF']
            cmd[4] = channel 

            ret = self.MicroKit.WriteCommand(cmd)       

	    return 0

        def EnableTrim(self,supply,duty):
            supply = self.supplies[supply]
            ret = self.pwm.SetConfig(self.period,duty,supply.trim_channel)
            return ret 
        
        def UpdateTrim(self,supply,duty):
            supply = self.supplies[supply]
            ret = self.pwm.SetConfig(self.period,duty,supply.trim_channel)
            

if __name__ == "__main__":
    MicroKit = MicroKit('/dev/ttyACM0')
	
    pwr = mkit_pwr(MicroKit) 	
    pwr.GetStatus()       

    print "Supply VA0 Test\n"
    time.sleep(1)
    pwr.EnableChannel(0x01)
    time.sleep(10)
    pwr.EnableTrim('VA1',0)
    time.sleep(2)
    pwr.UpdateTrim('VA1',100)
    time.sleep(2)
    pwr.UpdateTrim('VA1',200)
    time.sleep(2)
    pwr.UpdateTrim('VA1',300)
    time.sleep(2)
    pwr.UpdateTrim('VA1',400)
    time.sleep(2)
    pwr.UpdateTrim('VA1',500)
    time.sleep(2)
    pwr.UpdateTrim('VA1',600)
    time.sleep(2)
    pwr.UpdateTrim('VA1',700)
    time.sleep(2)
    pwr.UpdateTrim('VA1',800)
    pwr.GetStatus()
    pwr.DisableChannel(0x01)  

'''
    print "\nSupply VA1 Test\n"
    pwr.EnableChannel(0x01)
    time.sleep(10)
    pwr.GetStatus()
    pwr.DisableChannel(0x01)  

 
    print "\nSupply BOOST Test\n"
    pwr.EnableChannel(0x02)
    time.sleep(10)
    pwr.GetStatus()
    pwr.DisableChannel(0x02)

 
    print "\nSupply BOOST HV Test\n"
    pwr.EnableChannel(0x02)
    time.sleep(1)
    pwr.GetStatus()
    pwr.EnableChannel(0x03) 
    time.sleep(10)
    pwr.GetStatus()
    pwr.DisableChannel(0x03)
    time.sleep(1)
    pwr.DisableChannel(0x02)
'''
