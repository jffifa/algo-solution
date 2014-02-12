#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct se
{
	int u, v;
	se(int a, int b): u(a), v(b) {}
};

int N, M, cnt, cost, costnow;
int deg[8], scc[8];
bool g[8][8], has[8], vis[8];
vector<se> ansnow, ans, hmr;

void dfs(int u)
{
	vis[u] = 1;
	scc[u] = cnt;
	for (int v = 1; v <= 6; ++v)
		if (g[u][v] && !vis[v]) dfs(v);
}

void search(int i)
{
	if (i==N)
	{
		memset(vis, 0, sizeof(vis));
		int u, v;
		for (u = 1; u <= 6; ++u)
			if (has[u]) {dfs(u); break;}
		for (u = 1; u <= 6; ++u)
			if (has[u] && !vis[u]) return;
		vector<int> mdk;
		for (u = 1; u <= 6; ++u)
			if (has[u] && deg[u]&1) mdk.push_back(u);
		sort(mdk.begin(), mdk.end());
		reverse(mdk.begin(), mdk.end());
		int tmp = costnow;
		vector<se> et = ansnow;
		while (mdk.size()>2)
		{
			u = mdk.back(); mdk.pop_back();
			v = mdk.back(); mdk.pop_back();
			et.push_back(se(u, v));
			tmp += u+v;
		}
		if (tmp < cost)
		{
			cost = tmp;
			ans = et;
		}
		return;
	}
	search(i+1);
	if (costnow+hmr[i].u+hmr[i].v < cost)
	{
		costnow += hmr[i].u+hmr[i].v;
		ansnow.push_back(hmr[i]);
		g[hmr[i].u][hmr[i].v] = g[hmr[i].v][hmr[i].u] = 1;
		deg[hmr[i].u]++; deg[hmr[i].v]++;
		search(i+1);
		costnow -= hmr[i].u+hmr[i].v;
		ansnow.pop_back();
		g[hmr[i].u][hmr[i].v] = g[hmr[i].v][hmr[i].u] = 0;
		deg[hmr[i].u]--; deg[hmr[i].v]--;
	}
}

int main()
{
	int i, j, k, u, v;
	scanf("%d", &N);
	for (u = 1; u <= 6; ++u)
		g[u][u] = 1;
	for (i = 0; i < N; ++i)
	{
		scanf("%d%d", &u, &v);
		deg[u]++; deg[v]++;
		has[u] = has[v] = g[u][v] = g[v][u] = 1;
	}
	for (u = 1; u <= 6; ++u)
	{
		if (!has[u]) continue;
		if (!vis[u]) {dfs(u); cnt++;}
	}
	for (u = 1; u <= 6; ++u)
	{
		if (!has[u]) continue;
		for (v = u+1; v <= 6; ++v)
		{
			if (!has[v]) continue;
			if (scc[u] != scc[v]) hmr.push_back(se(u, v));
		}
	}
	N = hmr.size();
	/*
	for (i = 0; i < N; ++i)
		printf("%d %d\n", hmr[i].u, hmr[i].v);
	*/
	cost = 0x3fffffff;
	search(0);
	printf("%d\n", cost);
	N = ans.size();
	printf("%d\n", N);
	for (i = 0; i < N; ++i)
		printf("%d %d\n", ans[i].u, ans[i].v);
	return 0;
}

