import serial
import re
import time
ser = serial.Serial('/dev/ttyACM0', 9600)

time.sleep(5)

while True:
    ser.write('tilt'.encode())
    text = str(ser.readline())
    numbers = re.findall("\d+", text)
    
    print(numbers)
