#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000000007ll;

int N;
ll f[2][5555], sum[2][5555];

int main() {
	int i, j, k;
	while (cin>>N) {
		memset(f, 0, sizeof f);
		memset(sum, 0, sizeof sum);
		for (j = 1; j <= N; ++j)
			sum[0&1][j] = 1;
		int now, prev;
		for (i = 1; i < N; ++i) {
			now = i&1, prev = !now;
			sum[now][i] = 0;
			for (j = i+1; j <= N; ++j) {
				f[now][j] = (f[prev][j]*(j-1)+sum[prev][j])%mod;
				sum[now][j] = sum[now][j-1]+f[now][j];
				if (sum[now][j]>=mod) sum[now][j] -= mod;
			}
		}
		cout<<sum[now][N]*N%mod<<'\n';
	}
	return 0;
}
