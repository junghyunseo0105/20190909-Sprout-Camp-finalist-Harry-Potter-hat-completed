from konlpy.tag import Mecab

mecab = Mecab()

def loadDoc_nouns(mydoclist):
    doc_nouns_list = []

    for doc in mydoclist:
        nouns = mecab.morphs(doc)
        doc_nouns = ''

        for noun in nouns:
            doc_nouns += noun + ' '

        doc_nouns_list.append(doc_nouns)

    #for i in range(0, len(mydoclist)):
        #print('doc' + str(i + 1) + ' : ' + str(doc_nouns_list[i]))

    return doc_nouns_list

