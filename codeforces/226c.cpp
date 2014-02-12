#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll mod, l, r, k;

const int MAX = 1000010;

struct sm {
	ll m[2][2];
	void init() {memset(m, 0, sizeof m);}
	void eye() {init(); for (int i=0;i<2;++i) m[i][i]=1;}
}f;

sm operator*(const sm &a, const sm &b) {
	sm res;
	res.init();
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				if (a.m[i][k] && b.m[k][j])
					res.m[i][j] = (res.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
	return res;
}

sm operator^(sm x, ll p) {
	sm res;
	res.eye();
	for (; p; p>>=1) {
		if (p&1ll) res = res*x;
		x = x*x;
	}
	return res;
}

int main() {
	ll i, j;
	cin>>mod>>l>>r>>k;
	f.init();
	f.m[0][0] = f.m[0][1] = f.m[1][0] = 1;
	ll d = 1;
	for (i = 1; i < MAX; ++i) {
		ll t = r/(i+k-1);
		if (i*t>=l) d = max(d, t);
	}
	for (i = 1; i < MAX; ++i) {
		ll t = r/i;
		if (i*(t-k+1)>=l) d = max(d, i);
	}
	sm res = f^(d-1);
	cout<<res.m[0][0]%mod<<'\n';
	return 0;
}
