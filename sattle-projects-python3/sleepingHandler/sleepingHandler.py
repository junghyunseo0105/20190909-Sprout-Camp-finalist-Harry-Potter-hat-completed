import threading
import time
from onCommand.onCommand import *

from onCommand.onCommandHandler import *
from serialHandler.serialHandler import *
from soundHandler.soundHandler import *
from ai-makers-kit.python3.ex2_getVoice2Text import *

def sum():
    while(True):
        run()

flag = 0

def run():
    time.sleep(0.1)
    tilt = getTilt()
    
    try:
        if tilt == '0':
            print('아하....')
            surprise()
            setSurprise()
            if flag != 1:
                t = threading.Thread(target=loop, args=())
                t.start()
                t = threading.Thread(target=backGroundsound, args=())
                t.start()
        elif flag != 1:
            print('꿈뻑...')
            snoring()
            setSnoring()
    except:
        pass
    
        
def loop():
    global flag
    flag = 1
    text = getVoice2Text()
    onCommand(text)

def sound():
    global flag
    while flag == 1:
        background()
