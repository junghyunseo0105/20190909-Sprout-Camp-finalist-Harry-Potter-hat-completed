from sklearn.feature_extraction.text import TfidfVectorizer

from fileIO.fileIO import *
from sentenceLikelihood.konlpySet import *

def request(text):
    mydoclist = list()
    mydoclist.append(text)
    mydoclist.extend(readSentence())

    doc_nouns_list = loadDoc_nouns(mydoclist)
    
    tfidf_vectorizer = TfidfVectorizer(min_df=1)
    tfidf_matrix = tfidf_vectorizer.fit_transform(doc_nouns_list)
        
    document_distances = (tfidf_matrix * tfidf_matrix.T)
    
    #print('유사도 분석을 위한 ' + str(document_distances.get_shape()[0]) + 'x' +
          #str(document_distances.get_shape()[1]) + ' matrix를 만들었습니다.')
    
    #print(document_distances.toarray())
    
    similarity = list()
    for i in range (0, len(mydoclist)):
        similarity.append(document_distances[0, i])

    return similarity
