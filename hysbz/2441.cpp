#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000000007ll;

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define M(x) (x>>1)

inline int lowbit(int x) {
	return x&-x;
}

struct sp {
	int id, x, y;
	sp() {}
	sp(int a, int b, int c): id(a), x(b), y(c) {}
	bool operator<(const sp &rhs) const {
		if (y==rhs.y) return x>rhs.x;
		return y<rhs.y;
	}
}p[222222];

struct snode {
	int l, r, c;
	int f;
	ll sum;
}st[222222<<2];

void pushup(int n) {
	st[n].f = st[L(n)].f+st[R(n)].f;
	st[n].sum = st[L(n)].sum+st[R(n)].sum;
}

void pushdown(int n, int len) {
	if (st[n].c) {
		st[L(n)].c += st[n].c;
		st[R(n)].c += st[n].c;
		st[L(n)].sum += (ll)(len-M(len))*st[n].c;
		st[R(n)].sum += (ll)M(len)*st[n].c;
		st[n].c = 0;
	}
}

void build(int l, int r, int n) {
	st[n].l = l; st[n].r = r;
	st[n].c = 0;
	if (l==r) {
		st[n].sum = 0;
		return;
	}
	int m = M(l+r);
	build(l, m, L(n));
	build(m+1, r, R(n));
	pushup(n);
}

void update(int l, int r, int d, int n) {
	if (l<=st[n].l && r>=st[n].r) {
		st[n].c += d;
		st[n].sum += (ll)(st[n].r-st[n].l+1)*d;
		return;
	}
	pushdown(n, st[n].r-st[n].l+1);
	int m = M(st[n].l+st[n].r);
	if (l <= m) update(l, r, d, L(n));
	if (r > m) update(l, r, d, R(n));
	pushup(n);
}

ll query(int l, int r, int n) {
	if (l<=st[n].l && r>=st[n].r) return st[n].sum;
	pushdown(n, st[n].r-st[n].l+1);
	ll res = 0;
	int m = M(st[n].l+st[n].r);
	if (l <= m) res += query(l, r, L(n));
	if (r > m) res += query(l, r, R(n));
	return res;
}

int N, M;
map<int, int> hash;
int x[222222], y[222222];
int ta[222222];
ll l[222222], r[222222];

int getsum(int p) {
	int res = 0;
	for (; p; p -= lowbit(p))
		res += ta[p];
	return res;
}

void update(int p, int d) {
	for (; p<=M; p += lowbit(p))
		ta[p] -= d;
}

void solve(ll cnt[]) {
	int i, j, k;
	sort(p, p+N);
	memset(ta, 0, sizeof ta);
	build(1, M, 1);
	int now = 0, nowpos = -1;
	for (i = 0; i < N; ++i) {
		if (p[i].y^now) {
			for (j = i; p[j].y==p[i].y; ++j)
				update(p[j].x, -1);
			for (j = nowpos; j < i; ++j)
				update(p[j].x, p[j].x, getsum(p[j].x-1), 1);

			now = p[i].y; nowpos = i;
		}
		cnt[p[i].id] = query(1, p[i].x-1, 1)%mod;
	}
}

int main() {
	int i, j, k;
	cin>>N;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", x+i, y+i);
		sp[i] = sp(i, x[i], y[i]);
	}

	hash.clear();
	sort(x, x+N);
	for (i = 0; i < N; ++i)
		if (!hash.count(x[i])) hash[x[i]] = i+1;
	M = hash.size();
	for (i = 0; i < N; ++i)
		sp[i].x = hash[sp[i].x];
	hash.clear();
	sort(y, y+N);
	for (i = 0; i < N; ++i)
		if (!hash.count(y[i])) hash[y[i]] = i+1;
	for (i = 0; i < N; ++i)
		sp[i].y = hash[sp[i].y];

	solve(l);
	for (i = 0; i < N; ++i)
		sp[i].x = M+1-sp[i].x;
	solve(r);

	ll res = 0;
	for (i = 0; i < N; ++i)
		res = (res+l[i]*r[i])%mod;
	cout<<res<<'\n';
	return 0;
}
