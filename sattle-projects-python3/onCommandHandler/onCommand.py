from sentenceLikelihood.sentenceLikelihood import *
from inputData.inputData import *
from soundHandler.soundHandler import *
from serialHandler.serialHandler import *

import time

def onCommand(text):
    #print(text)
    similarity = request(text)
    print(similarity)
    
    count = 0
    
    for i in range(len(similarity)):
        if 1 <= i and i <= 5:
            if similarity[i] > 0.5:
                print('[ ', i, ' 번쨰 감지] > 알람 기능 감지')
                setTalk()
                play_alarmSetting()
                time.sleep(1)
                break
        elif 6 <= i and i <= 8:
            if similarity[i] > 0.5:
                print('[ ', i, ' 번쨰 감지] > 날씨 알림 감지')
                break
        elif 9 <= i and i <= 10:
            if similarity[i] > 0.5:
                print('퀸 노래재생 감지')
                play_queen()
                setSing()
                switch = True
                while switch:
                    time.sleep(1)
                    tilt = getTilt()
                    #print('tilt',tilt)
                    if tilt == '0':
                        switch = False
                        
                break
        count = count + 1
        #print(count, ' ', len(similarity))    

    if count == len(similarity):
        print('아무런 명령어가 감지되지 않았습니다.')
