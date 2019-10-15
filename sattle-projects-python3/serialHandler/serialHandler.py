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

def setStop():
    ser.write('stop\n'.encode())

def setSnoring():
    ser.write('snoring\n'.encode())

def setSurprise():
    ser.write('surprise\n'.encode())

def setTalk():
    ser.write('talk\n'.encode())
