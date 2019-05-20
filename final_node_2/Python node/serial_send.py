import serial
import time

while True:
	try:
		s = serial.Serial("/dev/ttyACM1", 115200)
		break
	except:
		print("No device connected, attempting reconnection")
		time.sleep(1)

while True:
	try:
		data = input("Duty Cycle: ")
		data = bytearray([int(data)])
		s.write(data)
			
	except KeyboardInterrupt:
		s.close()