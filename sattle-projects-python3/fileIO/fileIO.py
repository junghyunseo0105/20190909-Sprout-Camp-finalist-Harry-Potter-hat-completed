def readSentence():
    f = open("doit/sentence.txt", 'r')
    sentence = list()
    
    while True:
        line = f.readline()
        
        if not line: break
        sentence.append(line)
        #print(line)
    f.close()

    return sentence
