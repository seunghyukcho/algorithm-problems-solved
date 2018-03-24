import pandas as pd
import numpy as np
import numpy.linalg as lin
import matplotlib.pyplot as plt

def ridge(X, y, lmb):
    I = []
    for i in range(X[0].size) :
        row = []
        for j in range(X[0].size) :
            if i == j :
                row.append(lmb)
            else :
                row.append(0)
        I.append(row)

    I = np.matrix(I)
    w = np.dot(X.T, X) + I
    w = w.astype(np.float32)
    w = lin.inv(w)
    w = np.dot(w, X.T)
    w = np.dot(w, y)

    return w

dataset = np.array(pd.read_csv('prostate.csv', sep='\t'))
X = np.matrix(pd.DataFrame(dataset[:, 1:9]))
y = np.matrix(pd.DataFrame(dataset[:, 9]))
w = []
x_range = range(10000)

for i in x_range :
    result = ridge(X, y, i)
    w.append(result)
    print(w[0])
w = np.array(w)
graph = plt.gca()
for i in range(X[0].size) :
    graph.plot(x_range, w[:, i])
graph.set_xscale('log')
graph.set_xlim(graph.get_xlim()[::-1])
graph.legend(['lcavol', 'lweight', 'age', 'lbph', 'svi', 'lcp', 'gleason', 'pgg45'], loc='upper left')
plt.show()
