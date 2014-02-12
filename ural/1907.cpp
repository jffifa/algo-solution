#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX = 1000010;
int p[100010], pcnt=0;
int minf[MAX];
ll f[20];
int nf[20], cnt;
ll n, a;
ll ans;

ll gcd(ll a, ll b) {
	return b?gcd(b, a%b):a;
}

void init() {
	for (int i = 2; i < MAX; ++i) {
		if (!minf[i]) {
			minf[i] = i;
			p[pcnt++] = i;
		}
		for (int j = 0; j<pcnt && p[j]*i<MAX; ++j) {
			minf[p[j]*i] = p[j];
			if (i%p[j]==0) break;
		}
	}
}

int pf(ll n, ll f[], int nf[]) {
	int cnt = 0;
	int n2 = (int)sqrt((double)n);
	for (int i = 0; n>1 && p[i]<=n2; ++i)
		if (n%p[i]==0) {
			for (nf[cnt]=0; n%p[i]==0; n/=p[i]) ++nf[cnt];
			f[cnt++] = p[i];
		}
	if (n > 1) {
		nf[cnt] = 1;
		f[cnt++] = n;
	}
	return cnt;
}

void dfs(int i, int sgn, ll now) {
	if (i==cnt) {
		if (now>1) ans += sgn*n/now;
		return;
	}
	dfs(i+1, -sgn, now*f[i]);
	dfs(i+1, sgn, now);
}

int main() {
	init();
	//printf("%d %d\n", pcnt, p[pcnt-1]);
	while (cin>>a>>n) {
		cnt = pf(a, f, nf);
		ans = 0;
		ll orz = n;
		if (a%2==1) {
			assert(f[0]!=2ll);
			ans += n-n/2;
			n /= 2;
			dfs(0, -1, 1ll);
		}
		else {
			assert(f[0]==2ll);
			dfs(0, -1, 1ll);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
