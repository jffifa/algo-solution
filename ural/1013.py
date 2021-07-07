N = int(input())
K = int(input())
M = int(input())

def mul(m1, m2):
    m = [[0,0],[0,0]]
    for i in range(0,2):
        for j in range(0,2):
            for k in range(0,2):
                m[i][j] = m[i][j]+m1[i][k]*m2[k][j]
            m[i][j] = m[i][j] % M
    return m

def mpow(m, p):
    res = [[1,0],[0,1]]
    while p > 0:
        if p & 1:
            res = mul(res, m)
        m = mul(m, m)
        p = p >> 1
    return res

m = [[K-1,K-1],[1,0]]
r = mpow(m, N)
print(r[0][0])
