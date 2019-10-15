import serial
import re
import time
ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(5)
print('open the serial!')

def getTilt():
    #print(ser.portstr)
    
    ser.write('tilt\n'.encode())
    text = str(ser.readline())
    num = re.findall("\d+", text)[0]
    
    return num
