import RPi.GPIO as GPIO
import time
import sys
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
DATA = 8            #Data-Input (Pin14 Ser) on 74HC595
LATCH = 10          #Latch-Input (Pin12 RCLK) on 74HC595
CLOCK = 12          #Clock-Input (Pin11 SRCLK) on 74HC595
A1 = 11
A2 = 13
A3 = 15
GPIO.setup(A1, GPIO.OUT)
GPIO.setup(A2, GPIO.OUT)
GPIO.setup(A3, GPIO.OUT)
GPIO.setup(CLOCK, GPIO.OUT)
GPIO.setup(DATA, GPIO.OUT)
GPIO.setup(LATCH, GPIO.OUT)

GPIO.output(CLOCK,GPIO.LOW)
GPIO.output(DATA,GPIO.LOW)
GPIO.output(LATCH,GPIO.LOW)

SLEEP = 0.01
#setup completed
############################

#Functions for writing a bit to the register
def write0():
    GPIO.output(DATA,GPIO.LOW)
    GPIO.output(CLOCK,GPIO.HIGH)
    time.sleep(SLEEP)
    GPIO.output(CLOCK,GPIO.LOW)
    GPIO.output(DATA,GPIO.LOW)
    time.sleep(SLEEP)

def write1():
    GPIO.output(DATA,GPIO.HIGH)
    GPIO.output(CLOCK,GPIO.HIGH)
    time.sleep(SLEEP)
    GPIO.output(CLOCK,GPIO.LOW)
    GPIO.output(DATA,GPIO.LOW)
    time.sleep(SLEEP)

#Values for debuggen static
zahl = int(sys.argv[1])
selected = int(sys.argv[2])

#Chipselect
GPIO.output(A1,GPIO.LOW)
GPIO.output(A2,GPIO.LOW)
GPIO.output(A3,GPIO.LOW)
if (selected & 0x04)==4 :
    GPIO.output(A1,GPIO.HIGH)
if (selected & 0x02)==2 :
    GPIO.output(A2,GPIO.HIGH)
if (selected & 0x01)==1 :
    GPIO.output(A3,GPIO.HIGH)

#Set every Shiftregister state according to the wiring    
for n in range(2):
    byte = zahl%10
    print byte

    for count in range(8):
        if (count==0 and (byte==0 or byte==1 or byte==7)):
            write0()
        elif(count==1 and (byte==1 or byte==2 or byte==3 or byte==7)):
            write0()
        elif(count==2 and (byte==1 or byte==3 or byte==4 or byte==5 or byte==7 or byte==9)):
            write0()
        elif(count==3 and (byte==1 or byte==4 or byte==7)):
            write0()
        elif(count==4 and (byte==2)):
            write0()
        elif(count==5 and (byte==5 or byte==6)):
            write0()
        elif(count==6 and (byte==1 or byte==4)):
            write0()
        elif count==7:
            write0()
        else:
            write1()
    zahl= zahl/10

GPIO.output(LATCH,GPIO.HIGH)
time.sleep(SLEEP)
GPIO.output(LATCH,GPIO.LOW)


#while True:
#    GPIO.output(CLOCK,GPIO.LOW)
#    GPIO.output(A2,GPIO.LOW)
#    GPIO.output(A3,GPIO.LOW)
#    time.sleep(3)
#    GPIO.output(CLOCK,GPIO.HIGH)
#    GPIO.output(A2,GPIO.HIGH)
#    GPIO.output(A3,GPIO.HIGH)
#    time.sleep(3)
