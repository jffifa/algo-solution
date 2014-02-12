/*
	Problem: Ural1080
	Algorithm: DFS
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MaxN = 100;

int N, u, v;
vector<int> Adj[MaxN];
bool Vis[MaxN], Color[MaxN], Ans;

void DFS(int u, bool c)
{
	//printf("%d %d\n", u, c);
	Vis[u] = 1;
	Color[u] = c;
	for (int i = 0; i < Adj[u].size(); ++i)
		if (!Vis[Adj[u][i]]) DFS(Adj[u][i], !c);
}

bool Check()
{
	for (int u = 1; u <= N; ++u)
		for (int i = 0; i < Adj[u].size(); ++i)
			if (Color[u]^Color[Adj[u][i]] == 0) return 0;
	return 1;
}

int main()
{
	scanf("%d", &N);
	for (int u = 1; u <= N; ++u)
	{
		while (scanf("%d", &v), v)
		{
			Adj[u].push_back(v);
			Adj[v].push_back(u);
		}
	}
	for (int u = 1; u <= N; ++u)
		if (!Vis[u]) DFS(u, 0);
	Ans = Check();
	if (!Ans) printf("-1\n");
	else
		for (int u = 1; u <= N; ++u) printf("%d", Color[u]);
	printf("\n");
	return 0;
}
