#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define M(x) (x>>1)

typedef long long ll;
ll a[555555];

struct snode {
	int l, r;
	ll f, fl, fr, s;
	snode() {f = fl = fr = s = 0;}
	snode(ll a, ll b, ll c, ll d): f(a), fl(b), fr(c), s(d) {}
}st[555555<<2];

void pushup(int n) {
	st[n].s = st[L(n)].s+st[R(n)].s;
	st[n].fl = max(st[L(n)].fl, st[L(n)].s+st[R(n)].fl);
	st[n].fr = max(st[R(n)].fr, st[R(n)].s+st[L(n)].fr);
	ll &res = st[n].f;
	res = max(res, st[L(n)].f);
	res = max(res, st[R(n)].f);
	res = max(res, st[L(n)].fr+st[R(n)].fl);
}

void build(int l, int r, int n) {
	st[n].l = l; st[n].r = r;
	if (l==r) {
		st[n].s = a[l];
		st[n].f = st[n].fl = st[n].fr = max(a[l], 0ll);
		return;
	}
	int m = M(l+r);
	build(l, m, L(n));
	build(m+1, r, R(n));
	pushup(n);
}

snode query(int l, int r, int n) {
	if (l<=st[n].l && r>=st[n].r) return st[n];
	int m = M(st[n].l+st[n].r);
	snode ln, rn, res;
	if (l<=m) ln = query(l, r, L(n));
	if (r>m) rn = query(l, r, R(n));
	res.s = ln.s+rn.s;
	res.fl = max(ln.fl, ln.s+rn.fl);
	res.fr = max(rn.fr, rn.s+ln.fr);
	res.f = max(ln.f, rn.f);
	if (l<=m && r>m) res.f = max(res.f, ln.fr+rn.fl);
	return res;
}

int N, M, C;
int x[555555];
int p[555555];

int main() {
	int i, j, k;
	int t = 0;
	while (cin>>N>>M>>C) {
		++t;
		for (i = 0; i < N; ++i)
			scanf("%d", x+i);
		for (i = 1; i < N; ++i) {
			scanf("%d", p+i);
			a[i] = (x[i]-x[i-1])*50ll-1ll*p[i]*C;
		}
		build(1, N-1, 1);
		ll ans = 0;
		while (M--) {
			scanf("%d%d", &i, &j);
			ans += query(i, j-1, 1).f;
		}
		printf("%.10f\n", ans*0.01);
	}
	return 0;
}
