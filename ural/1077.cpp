//ural1077
//无向图dfs不存在横叉边
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[202];
int N, M, cnt;
bool vis[202], g[202][202];
int pr[202];
vector<int> path[40404];

inline void ae(int u, int v)
{
	adj[u].push_back(v);
	g[u][v] = 1;
}

void dfs(int u)
{
	vis[u] = 1;
	int v;
	for (int i = 0; i < adj[u].size(); ++i)
	{
		v = adj[u][i];
		if (!vis[v])
		{
			g[u][v] = g[v][u] = 0;
			pr[v] = u;
			dfs(v);
		}
		
		else if (g[u][v])
		{
			g[u][v] = g[v][u] = 0;
			int p = u;
			while (p != v)
			{
				path[cnt].push_back(p);
				p = pr[p];
			}
			path[cnt].push_back(v);
			cnt++;
		}
		
	}
}

void solve()
{
	int i, j, k, u, v;
	for (u = 1; u <= N; ++u)
		if (!vis[u]) dfs(u);
	/*
	for (u = 1; u <= N; ++u)
		printf("%d ", pr[u]);
	puts("#");
	*/
}

int main()
{
	int u, v;
	scanf("%d%d", &N, &M);
	while (M--)
	{
		scanf("%d%d", &u, &v);
		ae(u, v);
		ae(v, u);
	}
	solve();
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
	{
		printf("%d", path[i].size());
		for (int j = 0; j < path[i].size(); ++j)
			printf(" %d", path[i][j]);
		puts("");
	}
	return 0;
}
