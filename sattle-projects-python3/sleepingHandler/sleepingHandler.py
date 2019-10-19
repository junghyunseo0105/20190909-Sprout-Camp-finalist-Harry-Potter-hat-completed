import threading
import time

from onCommandHandler.onCommandHandler import *
from serialHandler.serialHandler import *
from soundHandler.soundHandler import *

import threading

def sum():
    while(True):
        run()
        

def run():
    time.sleep(0.1)
    tilt = getTilt()
    print('hello')
    try:
        if tilt == '0':
            print('아하....')
            surprise()
            setSurprise()
            command()
        else:
            print('꿈뻑...')
            snoring()
            setSnoring()
    except:
        pass
