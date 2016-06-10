#!/usr/bin/python
import argparse 
import time 
import serial 
import sys


class MicroKit():
	def __init__(self,port):
		#setup serial port 
		self.ser = serial.Serial(
			port=port,
			timeout=10
		)
    
	def WriteCommand(self,command=[]):
        
		ret = [] 

		#write command packet
		self.ser.write(command)
		#wait for ack response, 16 bytes long 
		ret = self.ser.read(16)
		
		ret = list(ret)
		for i in range(16):
			ret[i] = hex(ord(ret[i]))

		return ret
        
	

def main(self):
    #start of main program 
    #argument parsing 
    parser = argparse.ArgumentParser(description='Hex Programmer Utility')
    parser.add_argument('-s','--serial', help='Serial Port Device File', required=True)


    logfile = None 
    args         = vars(parser.parse_args())

if __name__ == "__MAIN__":
	mkit = MicroKit('/dev/ttyUSB0')
	mkit.main()

      	
      
      
