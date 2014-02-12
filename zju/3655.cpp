#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define fr first
#define sc second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define M(x) (x>>1)

typedef unsigned long long ll;
typedef pair<ll, int> pr;
pr (*mkpr)(ll, int) = make_pair<ll, int>;

int N, M;
ll l, r, a, b, c;
ll p[111111];

deque<ll> q;
vector<pr> node;

struct st {
	int l, r, v;
}t[222222<<2];

void pushup(int n) {
	t[n].v = min(t[L(n)].v, t[R(n)].v);
}

void build(int l, int r, int n) {
	t[n].l = l, t[n].r = r;
	if (l==r) {
		t[n].v = node[l].sc;
		return;
	}
	int m = M(l+r);
	build(l, m, L(n));
	build(m+1, r, R(n));
	pushup(n);
}

int query(int l, int r, int n) {
	if (l<=t[n].l && r>=t[n].r) return t[n].v;
	int res = 0x3fffffff;
	int m = M(t[n].l+t[n].r);
	if (l<=m) res = min(res, query(l, r, L(n)));
	if (r>m) res = min(res, query(l, r, R(n)));
	return res;
}

int bs(ll x) {
	int l = 0, r = M-1, m;
	while (l<r) {
		m = l+r+1>>1;
		if (node[m].fr<=x) l = m;
		else r = m-1;
	}
	return l;
}

int main() {
	int i, j, k;
	ll now;
	while (cin>>N) {
		cin>>l>>r>>a>>b;
		c = a-b;
		for (i = 0; i < N; ++i)
			scanf("%llu", p+i);
		if (a==b) {
			puts("0");
			continue;
		}
		i = 0;
		now = l+c-1;
		node.clear();
		q.clear();
		while (now <= r) {
			while (i<N && p[i]<=now) q.push_back(p[i++]);
			while (!q.empty() && q.front()+c<=now) q.pop_front();
			node.push_back(mkpr(now, (int)q.size()));
			if (i==N && q.empty()) break;
			ll add = i<N ? p[i]-now : INF;
			ll del = q.empty() ? INF : q.front()+c-now;
			now += min(add, del);
		}
		if (node.size()==0) {
			puts("0");
			continue;
		}
		M = node.size();
		build(0, M-1, 1);
		int ans = 0;
		for (i = 0; i < M; ++i) {
			ll up = node[i].fr+b;
			if (up>r) continue;
			j = bs(up);
			if (i<=j) ans = max(ans, query(i, j, 1));
		}
		for (i = 0; i < M; ++i) {
			if (node[i].fr+1<l+a) continue;
			ll down = node[i].fr-b;
			j = bs(down);
			if (j<=i) ans = max(ans, query(j, i, 1));
		}
		printf("%d\n", ans);
	}
	return 0;
}
