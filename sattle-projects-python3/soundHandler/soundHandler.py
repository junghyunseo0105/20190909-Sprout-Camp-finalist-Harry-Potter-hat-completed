from soundHandler.playSound import *

def snoring():
    path = '/home/pi/audioFile/코소리.mp3'
    play(path, 1)
    
def surprise():
    path = '/home/pi/audioFile/하아.....mp3'
    play(path, 2)

def background():
    path = '/home/pi/audioFile/브금-[AudioTrimmer.com].mp3'
    play(path, 3)

def play_queen():
    path = '/home/pi/audioFile/music/Queen - Bohemian Rhapsody.mp3'
    play(path, 4)

def play_alarmSetting():
    path = '/home/pi/audioFile/목표를 향해서 돌진하는 강한 힘이 느껴져.mp3'
    play_delay(path)
    print('hello')
