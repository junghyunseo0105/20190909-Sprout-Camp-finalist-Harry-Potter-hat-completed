import threading
import time

from pygame import mixer # Load the required library
from mutagen.mp3 import MP3

flag = False

def getFlag():
    return flag

def startThread(path):
    print(path)
    th1 = threading.Thread(target=run, args=(path))
    th1.start()

def run(path):
    flag = True
    print('1 ', flag)
    while flag:
        mixer.init()
        mixer.music.load(path)
        audio = MP3(path)
        length = audio.info.length
        mixer.music.play()
        
        time.sleep(length)
        flag =  False
        
