from onCommand.onCommand import *
from inputData.inputData import *

def command():
    text = inputData('명령을 입력해주세요.\n>')

    onCommand(text)
