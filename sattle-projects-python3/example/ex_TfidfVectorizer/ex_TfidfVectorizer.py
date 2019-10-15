from sklearn.feature_extraction.text import TfidfVectorizer

mydoclist = ['알람 맞춰줘.',
             '알람 설정해줘.']

tfidf_vertorizer = TfidfVectorizer(min_df=1)
tfidf_matrix = tfidf_vertorizer.fit_transform(mydoclist)

document_distances = (tfidf_matrix * tfidf_matrix.T)

print('유사도 분석을 위한 ' + str(document_distances.get_shape()[0])
      + 'x' + str(document_distances.get_shape()[1]) + 'matrix를 만들었습니다.')

print(document_distances.toarray())
