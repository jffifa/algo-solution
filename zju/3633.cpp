#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

#define L(x) (x<<1)
#define R(x) ((x<<1)|1)
#define M(x) (x>>1)

typedef pair<int, int> pr;
pr (*mkpr)(int, int) = make_pair<int, int>;

map<int, int> hmr;
int N, M;
int a[555555];
int last[555555];

struct snode {
	int l, r;
	pr v;
}st[555555<<2];

void pushup(int n) {
	st[n].v = max(st[L(n)].v, st[R(n)].v);
}

void build(int l, int r, int n) {
	st[n].l = l; st[n].r = r;
	if (l == r) {
		st[n].v = mkpr(last[l], a[l]);
		return;
	}
	int m = M(l+r);
	build(l, m, L(n));
	build(m+1, r, R(n));
	pushup(n);
}

pr query(int l, int r, int n) {
	if (l<=st[n].l && r>=st[n].r)
		return st[n].v;
	int m = M(st[n].l+st[n].r);
	pr res = mkpr(0, 0);
	if (l <= m) res = max(res, query(l, r, L(n)));
	if (r > m) res = max(res, query(l, r, R(n)));
	return res;
}

int main() {
	int i, j, k, l, r;
	while (cin>>N) {
		for (i = 1; i <= N; ++i)
			scanf("%d", a+i);
		hmr.clear();
		for (i = 1; i <= N; ++i) {
			if (hmr.find(a[i])==hmr.end())
				last[i] = 0;
			else
				last[i] = hmr[a[i]];
			hmr[a[i]] = i;
		}
		build(1, N, 1);
		cin>>M;
		while (M--) {
			scanf("%d%d", &l, &r);
			pr ans = query(l, r, 1);
			if (ans.first >= l) printf("%d\n", ans.second);
			else puts("OK");
		}
		puts("");
	}
	return 0;
}
