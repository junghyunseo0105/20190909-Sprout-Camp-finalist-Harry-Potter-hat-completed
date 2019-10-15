from pygame import mixer # Load the required library

mixer.init()
mixer.music.load('/home/pi/ai-makers-kit/data/sample_sound.wav')
mixer.music.play()
