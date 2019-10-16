from soundHandler.playSound import *

def snoring():
    path = '/home/pi/sattle-projects-python3/soundHandler/audioFile/코소리.mp3'
    play(path, 1)
    
def surprise():
    path = '/home/pi/sattle-projects-python3/soundHandler/audioFile/하아.....mp3'
    play(path, 2)

def background():
    path = '/home/pi/sattle-projects-python3/soundHandler/audioFile/브금-[AudioTrimmer.com].mp3'
    play(path, 3)
