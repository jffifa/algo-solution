#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1010;

int N, M, K;
int match[MAX];
vector<int> g[MAX];
bool vis[MAX];

void init()
{
	memset(match, 0, sizeof(match));
	for (int u = 1; u <= N; ++u)
		g[u].clear();
}

bool dfs(int u)
{
	int v;
	for (int i = 0; i < g[u].size(); ++i)
	{
		v = g[u][i];
		if (vis[v]) continue;
		vis[v] = 1;
		if (!match[v] || dfs(match[v]))
		{
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int hgr()
{
	int res = 0;
	for (int u = 1; u <= N; ++u)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(u)) ++res;
	}
	return res;
}

int main()
{
	int u, v;
	cin>>N>>M>>K;
	init();
	while (K--)
	{
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	printf("%d\n", N+M-hgr());
	return 0;
}
