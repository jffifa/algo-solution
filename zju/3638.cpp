#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 100000007ll;

ll ans;
int cnt;
int N, M;
int lim[22];
char str[100];
char u[22], v[22], w[22];
bool g[22];
ll inv[22];

ll pow(ll x, int p) {
	ll res = 1;
	for (; p; p>>=1) {
		if (p&1) res = res*x%mod;
		x = x*x%mod;
	}
	return res;
}

ll c(int n, int m) {
	if (n < m) return 0;
	ll res = 1;
	int i=n, j=m;
	for (; j; --i,--j) {
		res = res*i%mod;
		res = res*inv[j]%mod;
	}
	return res;
}

void dfs(int i, int sum, int sgn) {
	//printf("%d %d %d\n", i, sum, sgn);
	if (i==cnt) {
		ans = (ans+sgn*c(sum+N-1, N-1))%mod;
		return;
	}
	if (g[i]) {
		dfs(i+1, sum, sgn);
		if (sum-lim[i]>=0)
			dfs(i+1, sum-lim[i], -1*sgn);
	}
	else {
		if (sum-lim[i]>=0)
			dfs(i+1, sum-lim[i], sgn);
	}
}

int main() {
	int i, j, k;
	int t = 0;
	for (i = 1; i <= 20; ++i)
		inv[i] = pow(i, mod-2);
	while (scanf("%d%d", &N, &M), N) {
		getchar();
		memset(g, 0, sizeof g);
		cnt = 0;
		while (gets(str), str[0]) {
			sscanf(str, "%s%s%s%d", u, v, w, lim+cnt);
			if (v[0]=='g') lim[cnt]++;
			else g[cnt] = 1;
			cnt++;
		}
		ans = 0;
		dfs(0, M, 1);
		if (ans<0) ans += mod;
		printf("%lld\n", ans);
	}
	return 0;
}
