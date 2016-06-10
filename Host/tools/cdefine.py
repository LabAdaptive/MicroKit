error_to_catch = getattr(__builtins__,'FileNotFoundError', IOError)

class CDefine():
	def Load(self,cdefines):
		self.defines = {}

		try:
			fhandle = open(cdefines,'r')
		
		except error_to_catch:
			print "Invalid C #Define file: " + str(cdefines)
			return -1

		lineNum = 0 
		for lines in fhandle:
			if (lines.find('#define') >= 0 or lines.find('#DEFINE') >= 0):
				temp   = lines.split(' ') 
				#print temp	
				if ( len(temp) > 2):
					define = temp[1]
					val    = temp[len(temp)-1]	
					if (val.find('x') >= 0 or val.find('X') >=0):
						val = int(val,16) 

					else:
						val = int(val,10)
					self.defines[define] = val;
	
	def ListDefines(self):
		for items in self.defines:
			print str(items) + " : " + str(self.defines[items])


if __name__ == "__main__":
	Imports = CDefine()
	Imports.Load('../../Common/MKitCommands.h')
	Imports.ListDefines()
		
