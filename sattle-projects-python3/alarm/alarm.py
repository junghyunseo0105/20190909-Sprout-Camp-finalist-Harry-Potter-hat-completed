from fileIO.fileIO import *
import re

def alarm(text):
    numbers = getnumberArray(text)

    if len(numbers) < 2:
        print('[alarm] error 시간을 입력해주세요.')
        return False
    
    writeSentence(numbers) 
    
def get_numberArray(text):
    tmp_string = str(text)
    numbers = re.findall("\d+", tmp_string)
    #print(numbers)
    return numbers
