from inputData.inputData import *

def alarm():
    check = False
    text = inputData('시간을 입력하십시오. (예 > 오전 1시 48분)\n>')
    try:
        array = text.split(' ')

        print(array)
    
        time = array[0]
        hour = array[1][:-1]
        min = array[2][:-1]
        
        check = True
    except:
        pass
    #print(time)
    #print(hour)
    #print(min)
    
    return check
