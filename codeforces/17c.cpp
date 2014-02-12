#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 51123987;

int N, M, L;
char s[200];
int f[2][3][52][52][52];

inline void inc(int &a, int b) {
    a += b;
    if (a>=mod) a -= mod;
}

inline int g(int x) {
	return x>=0?x:51;
}

int main() {
    int i, j, k, l, a, b, c;
    cin>>N>>s;
    L = N;
    for (i = 0; i < N; ++i)
        s[i] -= 'a';
    M = N/3; if (N%3) M++;
    N = unique(s, s+N)-s;
	int now, prev;
    for (i = 1; i <= N; ++i) {
		now = i&1, prev = !now;
        for (j = 0; j < 3; ++j)
            for (a = 0; a <= M; ++a) for (b = 0; b <= M; ++b) for (c = 0; c <= M; ++c) {
                int &res = f[now][j][a][b][c] = 0;
                if (s[i-1]!=j) {
					res = f[prev][j][a][b][c];
                    continue;
                }
				for (k = 0; k < 3; ++k) {
					if (j==k) inc(res, f[now][k][g(a-(j==0))][g(b-(j==1))][g(c-(j==2))]);
					else inc(res, f[prev][k][g(a-(j==0))][g(b-(j==1))][g(c-(j==2))]);
				}
				if (a+b+c==1) inc(res, a&j==0|b&j==1|c&j==2);
            }
	}
    int ans = 0;
    for (a = M-1; a <= M; ++a)
        for (b = M-1; b <= M; ++b)
            for (c = M-1; c <= M; ++c) {
                if (a+b+c!=L) continue;
                for (j = 0; j < 3; ++j)
                    inc(ans, f[now][j][a][b][c]);
            }
    cout<<ans%mod<<'\n';
    return 0;
}
