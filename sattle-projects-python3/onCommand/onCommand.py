from sentenceLikelihood.sentenceLikelihood import *

def onCommand(text):
    print('[onCommand] <', text)
    similarity = request(text)

    count = 0

    for i in range(len(similarity)):
        if i >= 1 and i <= 3:
            if similarity[i] > 0.5:
                print('[ ', i, ' 번쨰 감지] > 알람 기능 감지')
                
        elif i >= 3 and i <= 5:
            if similarity[i] > 0.5:
                print('[ ', i, ' 번쨰 감지] > 날씨 알림 감지')
                
        count = count + 1
        #print(count, ' ', len(similarity))    

    if count == len(similarity):
        print('아무런 명령어가 감지되지 않았습니다.')
