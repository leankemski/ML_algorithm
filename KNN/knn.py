'''
knn的尝试
训练数据来自skleearn的datasets
knn不需要训练模型，本身就是模型
author: Lean
version: 0.1
last edit: 2020.06.17
'''
import numpy as np

class knn_classifier():

    def __init__(self, k=5):
        self.k = k
        self.x = None
        self.y = None

    def fit(self, x, y):
        self.x = x
        self.y = y

    def predict(self, X_test):
        output = np.zeros((X_test.shape[0], 1))
        for i in range(X_test.shape[0]):
            dis = []
            for j in range(self.x.shape[0]):
                dis.append(np.linalg.norm(X_test[i] - self.x[j]))
            labels = []
            index = sorted(range(len(dis)), key=dis.__getitem__)
            #print("index = ",index)
            for j in range(self.k):
                labels.append(self.y[index[j]])
            #print("labels = ", labels)
            counts = []
            for label in labels:
                counts.append(labels.count(label))
            #print("counts = ", counts)
            output[i] = labels[np.argmax(counts)]
            #print("output[i] = ", output[i])
        return output

    def score(self, x, y):
        pred = self.predict(x)
        err = 0
        for i in range((x.shape[0])):
            if pred[i] != y[i]:
                err += 1
        return 1-float(err/x.shape[0])


if __name__ == "__main__":
    from sklearn import datasets
    iris = datasets.load_iris()
    x = iris.data
    y = iris.target
    clf = knn_classifier(k=3)
    clf.fit(x, y)
    print("my knn score: ", clf.score(x, y))

    from sklearn.neighbors import KNeighborsClassifier
    clf_sklearn = KNeighborsClassifier(n_neighbors=3)
    clf_sklearn.fit(x,y)
    print('sklearn score:',clf_sklearn.score(x,y)) 
            