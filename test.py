import serial as sr
import serial.tools.list_ports as sl
import time

ser = sr.Serial(str(sl.comports()[0].device), 57600, timeout=0.005)
time.sleep(2)
str1=""
ser.write(b's/500/40/0/-40')
time.sleep(0.8)
for i in range (10000):
    # ser.write(b'r')
    # time.sleep(0.01)
    str1 = ser.readline()
    print(str1)
ser.close()
