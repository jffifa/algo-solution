#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define M(x) (x>>1)

typedef long long ll;

const double EPS = 1e-6;

struct snode {
	int l, r;
	ll c, sum;
}st[55555<<3];

int N, Q, cnt;
int l[55555], r[55555], id[55555<<1];
vector<int> son[55555];
ll s[55555];

void pushup(int n) {
	st[n].sum = st[L(n)].sum+st[R(n)].sum;
}

void pushdown(int n, int len) {
	if (st[n].c) {
		st[L(n)].c += st[n].c;
		st[L(n)].sum += st[n].c*(len-M(len));
		st[R(n)].c += st[n].c;
		st[R(n)].sum += st[n].c*M(len);
		st[n].c = 0;
	}
}

void build(int l, int r, int n) {
	st[n].l = l; st[n].r = r;
	st[n].c = 0;
	if (l==r) {
		st[n].sum = s[id[l]];
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
		st[n].sum += (ll)d*(st[n].r-st[n].l+1);
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

void dfs(int u) {
	id[++cnt] = u;
	l[u] = cnt;
	for (int i = 0; i < son[u].size(); ++i)
		dfs(son[u][i]);
	id[++cnt] = u;
	r[u] = cnt;
}

char op[20];
int x, y, z;

int main() {
	int i, j, k;
	cin>>N>>Q>>s[0];
	for (i = 1; i < N; ++i) {
		scanf("%d%lld", &j, s+i);
		son[j].push_back(i);
	}
	cnt = 0;
	dfs(0);
	//assert(cnt==2*N);
	build(1, cnt, 1);
	while (Q--) {
		scanf("%s%d%d%d", op, &x, &y, &z);
		if (op[0]=='e') {
			if (query(l[x], l[x], 1)<y) {
				update(l[x], l[x], z, 1);
				update(r[x], r[x], z, 1);
			}
		}
		else {
			if (query(l[x], r[x], 1)<(ll)y*(r[x]-l[x]+1))
				update(l[x], r[x], z, 1);
		}
	}
	for (i = 0; i < N; ++i)
		printf("%lld\n", query(l[i], l[i], 1));
	return 0;
}
