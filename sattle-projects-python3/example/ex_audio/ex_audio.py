from pygame import mixer # Load the required library
from mutagen.mp3 import MP3
import time

mixer.init()
path = '/home/pi/sattle-projects-python3/audioFile/나중에넌아주크게될텐데.mp3'
mixer.music.load(path)
audio = MP3(path)
length = audio.info.length
print(length)
mixer.music.play()

time.sleep(length)

mixer.init()
mixer.music.load('/home/pi/sattle-projects-python3/audioFile/코소리.mp3')
mixer.music.play()

while True:
    pass
    
