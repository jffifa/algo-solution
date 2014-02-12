#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
set<int> info[222];
map<int, int> id;
int lim[222];

struct se {
	int v, c;
	int n;
	se() {}
	se(int p, int q, int r): v(p), c(q), n(r) {}
}e[11111];
int V, E;
int fst[444];
int s, t;
int h[444], gap[444];

void init() {
	memset(fst, -1, sizeof(fst));
	memset(gap, 0, sizeof(gap));
	memset(h, 0, sizeof(h));
	E = 0;
}

void ae(int u, int v, int c) {
	e[E] = se(v, c, fst[u]);
	fst[u] = E++;
	e[E] = se(u, 0, fst[v]);
	fst[v] = E++;
}

int sap(int u, int f) {
	if (u==t) return f;
	int i, minh=V, rf=f, cf;
	for (i = fst[u]; i != -1; i = e[i].n)
		if (e[i].c && h[e[i].v]+1==h[u])
		{
			cf = sap(e[i].v, min(e[i].c, rf));
			e[i].c -= cf; e[i^1].c += cf;
			rf -= cf;
			if (h[s]==V || !rf) return f-rf;
		}
	for (i = fst[u]; i != -1; i = e[i].n)
		if (e[i].c) minh = min(minh, h[e[i].v]);
	if (!--gap[h[u]]) h[s] = V;
	else ++gap[h[u]=minh+1];
	return f-rf;
}

int maxflow() {
	int res = 0;
	gap[0] = V;
	while (h[s] < V) res += sap(s, 0x3fffffff);
	return res;
}

int main() {
	int i, j, k;
	while (cin>>N) {
		for (i = 1; i <= N; ++i)
			info[i].clear();
		for (i = 1; i <= N; ++i) {
			scanf("%d%d%d", &j, &k, lim+i);
			while (j--) {
				scanf("%d", &k);
				info[i].insert(k);
			}
		}
		cin>>M;
		for (set<int>::iterator it=info[M].begin(); it!=info[M].end(); ++it) {
			int x = *it;
			for (i = 1; i <= N; ++i) {
				if (i==M) continue;
				info[i].erase(x);
			}
		}
		id.clear();
		init();
		int cnt = 0;
		for (i = 1; i <= N; ++i) {
			if (i==M) continue;
			ae(0, i, lim[i]);
			for (set<int>::iterator it=info[i].begin(); it!=info[i].end(); ++it) {
				int x = *it;
				if (id.find(x)==id.end())
					id[x] = ++cnt;
				ae(i, N+id[x], 1);
			}
		}
		s = 0; t = N+cnt+1; V = N+cnt+2;
		for (i = N+1; i <= N+cnt; ++i)
			ae(i, t, 1);
		int ans = info[M].size()+maxflow();
		printf("%d\n", ans);
	}
	return 0;
}
