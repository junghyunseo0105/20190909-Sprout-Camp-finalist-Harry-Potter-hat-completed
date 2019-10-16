from datetime import datetime
from pygame import mixer # Load the required library
from mutagen.mp3 import MP3

import time
time_play = 0
path_ = ' '

def play(path, num):
    global time_play
    global path_
    
    now = getTime()
    #print(time_play)
    
    #print(play_sound(path), ' ', now)
    #print(play_sound(path) + now, ' ', now)
    #print(play_sound(path) + now > now)
    #print(play_sound(path) + now < now)
    
    #print(time_play < now)

    a = 3
    
    if time_play + a < now or path_ != path:
        if num == 1: #코소리 
            path_ = path
            music_time = get_play(path)
            total = music_time + now
            time_play = total 
            #print(int(time_play))
        elif num == 2: #하아....
            path_ = path
            music_time = get_play(path)
            total = music_time + now
            time_play = total
            #print(int(time_play))

        elif num == 3: #하아....
            path_ = path
            music_time = get_play(path)
            total = music_time + now
            time_play = total
            #print(int(time_play))
            
def getTime():
    now = datetime.now()
    
    time_int = now.hour * 10000
    time_int = time_int +  now.minute * 100
    time_int = time_int +  now.second * 1
    
    return int(time_int)

def get_play(path):
    #print(path)
    mixer.init()
    mixer.music.load(path)
    audio = MP3(path)
    length = audio.info.length
    #print(length)
    mixer.music.play()

    return int(length)
