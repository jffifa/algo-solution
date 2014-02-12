#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1000000007ll;

int N, K;
int a[5555];
int id, pos;
int eq, gr, ls;
ll fac[5555], facinv[5555];

ll com(int n, int m) {
	//if (n<m) return 0;
	return fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}

ll inv(ll x) {
	int p = mod-2;
	ll res = 1ll;
	for (; p; p>>=1) {
		if (p&1) res = res*x%mod;
		x = x*x%mod;
	}
	return res;
}

int main() {
	int i, j, k;
	while (cin>>N>>K) {
		for (i = 0; i < N; ++i)
			cin>>a[i];
		cin>>id>>pos;
		id--; pos--;
		eq = gr = ls = 0;
		for (i = 0; i < N; ++i)
			if (a[i]==a[id]) ++eq;
			else if (a[i]>a[id]) ++gr;
			else ++ls;
		--eq;
		//printf ("%d %d %d\n", eq, gr, ls);
		fac[0] = 1; facinv[0] = 1;
		for (i = 1; i <= N; ++i) {
			fac[i] = fac[i-1]*i%mod;
			facinv[i] = facinv[i-1]*inv(i)%mod;
		}
		ll ans = 0;
		for (i = 0; i <= min(K-1,eq); ++i)
			for (j = 0; j <= i; ++j) {
				int l = pos-j, r = K-1-(pos+i-j);
				if (l<0 || ls<l || r<0 || gr<r) continue;
				ans += com(eq, i)*com(ls, l)%mod*com(gr, r)%mod;
				if (ans>=mod) ans -= mod;
			}
		cout<<ans%mod<<'\n';
	}
	return 0;
}
