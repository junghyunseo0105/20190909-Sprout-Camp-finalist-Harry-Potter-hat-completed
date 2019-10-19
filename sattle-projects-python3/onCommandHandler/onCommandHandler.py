from onCommandHandler.onCommand import *
from inputData.inputData import *

def command():
    #text = inputData('명령을 입력해주세요.\n>')
    text = inputVoice_data()
    
    onCommand(text)
