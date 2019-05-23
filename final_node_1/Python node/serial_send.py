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

counter = 1
byte1 = 0
service_id = 0
parameter = 0

while True:
	try:
		# if counter == 1:
		# 	s_node = input("Source Node: ")
		# 	d_node = input("Destination Node: ")
		# 	byte1 |= (s_node<<4)
		# 	byte1 |= d_node
		# 	counter = 2
		# 	print("**********************")
		# elif counter == 2:
		# 	service_id = input("Service id: ")
		# 	counter = 3
		# 	print("**********************")
		# elif counter == 3:
		# 	parameter = input("Parameter: ")
		# 	# BYTES = bytearray([(byte1), (service_id), (parameter)])
			
		# 	s.write(byte1.encode())

		# 	# print BYTES

		# 	counter = 1			
		# 	print("**********************")

		inp = input(">>")
		s.write(bytearray([int(inp)]))

	except KeyboardInterrupt:
		s.close()
