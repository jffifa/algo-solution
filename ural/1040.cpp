/*
	Problem: Ural1040
	Algorithm: DFS, Maths
	Time: O()
	Memory: O()
	Detail: Tricky
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MaxN = 51;

vector<int> Adj[MaxN];
int N, M, u, v, No;
int G[MaxN][MaxN];
int ID[MaxN*MaxN];
char Vis[MaxN];

void DFS(int u)
{
	Vis[u] = 1;
	int v;
	for (int i = 0; i < Adj[u].size(); ++i)
	{
		v = Adj[u][i];
		if (!Vis[v])
		{
			ID[G[u][v]] = ++No;
			DFS(v);
		}
		else
			if (!ID[G[u][v]]) ID[G[u][v]] = ++No;
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d%d", &u, &v);
		Adj[u].push_back(v);
		Adj[v].push_back(u);
		G[u][v] = G[v][u] = i;
	}
	for (int u = 1; u <= N; ++u)
		if (!Vis[u]) DFS(u);
	printf("YES\n");
	for (int i = 1; i < M; ++i)
		printf("%d ", ID[i]);
	printf("%d\n", ID[M]);
	return 0;
}
