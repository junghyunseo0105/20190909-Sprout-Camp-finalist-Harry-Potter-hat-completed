from sklearn.feature_extraction.text import TfidfVectorizer
from konlpy.tag import Mecab

mecab = Mecab()

mydoclist = ['영희가 사랑하는 강아지 백구를 산책시키고 있다.',
             '철수가 사랑하는 소 누렁이를 운동시키고 있다.',
             '영희와 철수는 소와 강아지를 산책 및 운동시키고 있다.']

doc_nouns_list = []

for doc in mydoclist:
    nouns = mecab.nouns(doc)
    doc_nouns = ''

    for noun in nouns:
        doc_nouns += noun + ' '

    doc_nouns_list.append(doc_nouns)

for i in range(0, 3):
    print('doc' + str(i + 1) + ' : ' + str(doc_nouns_list[i]))

tfidf_vectorizer = TfidfVectorizer(min_df=1)
tfidf_matrix = tfidf_vectorizer.fit_transform(doc_nouns_list)

document_distances = (tfidf_matrix * tfidf_matrix.T)

print('유사도 분석을 위한 ' + str(document_distances.get_shape()[0]) + 'x' +
      str(document_distances.get_shape()[1]) + ' matrix를 만들었습니다.')

print(document_distances[1, 2])
