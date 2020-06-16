from flask import Flask
import _thread as thread
import json
import time
import RPi.GPIO as GPIO # Import Raspberry Pi GPIO libraryd
import time
from time import sleep
from multiprocessing import Process, Value


GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
GPIO.setup(5, GPIO.OUT)
GPIO.output(5, GPIO.LOW)


app = Flask(__name__)

status = "Red"
timer = 15


@app.route('/')
def main():

    global status
    return "Current Status: " + status


@app.route('/setGreen')
def hello_world():
    global status
    global timer
    if(status != "Green"):
        timer = 15 
        testing()
    
    status = "Green"

    return status



@app.route('/setRed')
def test():
    global status
    global timer
    if(status != "Red"):
        timer = 15
        testing()
    status = "Red"

    return status


def testing():
    if(GPIO.input(5)):
        GPIO.output(5, GPIO.LOW)
    else:
        GPIO.output(5, GPIO.HIGH)


def main2():
    global status
    global timer
    while(True):
        print(timer)
        time.sleep(1)
        timer -= 1

        if(timer == 0):
            if(GPIO.input(5)):
                GPIO.output(5, GPIO.LOW)
                status = "Red"
            else:
                GPIO.output(5, GPIO.HIGH) 
                status = "Green"

            timer = 15

if __name__ == '__main__':

    
    thread.start_new_thread(main2, ())
    app.run(host='0.0.0.0', debug=False, threaded=True)
