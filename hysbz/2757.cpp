#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 20120427;
const ll mx = 1000000000000000000ll;
typedef pair<ll, ll> pr;
pr (*mkpr)(ll, ll) = make_pair<ll, ll>;
#define fr first
#define sc second

int T;
int n[22], sum[22];
int cnt = 0;
ll hmr[66666];
ll l, r, k;
int t;
int exp[22];
int news[66666][10];
int fac[5]={2,3,5,7};
pr f[22][66666], f0[22][3], NIL=mkpr(-1, -1);

void operator%=(pr &lhs, int rhs) {
	lhs.fr %= rhs;
	lhs.sc %= rhs;
}

pr dfs(int i, int s, bool e) {
	if (i==-1) return mkpr(s==1, 0);
	if (!e && f[i][s]!=NIL) return f[i][s];
	pr res = mkpr(0, 0);
	int u = e?n[i]:9;
	for (int d = 1; d <= u; ++d) {
		if (news[s][d]==-1) continue;
		pr tra = dfs(i-1, news[s][d], e&&d==u);
		res.fr += tra.fr;
		res.sc += d*exp[i]*tra.fr+tra.sc;
	}
	res %= mod;
	return e?res:f[i][s]=res;
}

pr dfs0(int i, int s, bool e) {
	if (i==-1) return mkpr(s==0, 0);
	if (!e && f0[i][s]!=NIL) return f0[i][s];
	pr res = mkpr(0, 0);
	int u = e?n[i]:9;
	for (int d = 0; d <= u; ++d) {
		pr tra;
		if (d) tra = dfs0(i-1, s==2?1:s, e&&d==u);
		else tra = dfs0(i-1, s==2?2:0, e&&d==u);
		res.fr += tra.fr;
		res.sc += d*exp[i]*tra.fr+tra.sc;
	}
	res %= mod;
	return e?res:f0[i][s]=res;
}

void pre(int i, ll now) {
	if (i==4) {
		hmr[cnt++] = now;
		return;
	}
	while (now<=mx) {
		pre(i+1, now);
		now *= fac[i];
	}
}

void init() {
	hmr[cnt++] = 0;
	pre(0, 1);
	sort(hmr, hmr+cnt);
	int i, j, k;
	for (i = 1; i < cnt; ++i) {
		for (j = 1; j < 10; ++j) {
			if (hmr[i]%j) news[i][j] = -1;
			else news[i][j] = lower_bound(hmr, hmr+cnt, hmr[i]/j)-hmr;
		}
	}
	exp[0] = 1;
	for (i = 1; i <= 20; ++i)
		exp[i] = (exp[i-1]*10)%mod;
}

ll solve(ll x) {
	if (t==-1) return 0;
	int len = 0;
	int i, j, k;
	for (; x; x/=10) n[len++] = x%10;
	if (t==0) return dfs0(len-1, 2, 1).sc;
	ll res = 0;
	for (i = 1; i < len; ++i)
		res += dfs(i-1, t, 0).sc;
	res += dfs(len-1, t, 1).sc;
	return res%mod;
}

int main() {
	init();
	memset(f, -1, sizeof f);
	memset(f0, -1, sizeof f0);
	cin>>T;
	while (T--) {
		cin>>l>>r>>k;
		t = lower_bound(hmr, hmr+cnt, k)-hmr;
		if (k==cnt || hmr[t]!=k) t = -1;
		//cout<<solve(r)<<'\n';
		cout<<(solve(r)-solve(l-1)+mod)%mod<<'\n';
	}
	return 0;
}
