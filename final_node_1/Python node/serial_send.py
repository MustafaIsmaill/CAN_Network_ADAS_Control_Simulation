import serial
import time

while True:
	try:
		# s = serial.Serial("/dev/ttyACM2", 256000)
		s = serial.Serial(
    		port='/dev/ttyACM2',
		    baudrate=256000,
		    bytesize=serial.EIGHTBITS
		)
		break
	except:
		print("No device connected, attempting reconnection")
		time.sleep(1)


s.write(bytearray([int(0)]))
s.write(bytearray([int(0)]))

while True:
	try:
		inp = input(">>")
		s.write(bytearray([int(inp)]))
	except KeyboardInterrupt:
		s.close()
