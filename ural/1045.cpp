/*
	Problem: Ural1045
	Algorithm: Tree DP, SG
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MaxN = 1001;

int N, S, u, v;
int FStep;
char Ans, Vis[MaxN], SG[MaxN];
vector<int> Adj[MaxN];

char MemSch(int u)
{
	Vis[u] = 1;
	for (int i = 0; i < Adj[u].size(); ++i)
		if (!Vis[Adj[u][i]])
			SG[u] |= !MemSch(Adj[u][i]);
	return SG[u];
}

int main()
{
	scanf("%d%d", &N, &S);
	for (int i = 1; i < N; ++i)
	{
		scanf("%d%d", &u, &v);
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	memset(Vis, 0, sizeof(Vis));
	memset(SG, 0, sizeof(SG));
	Ans = MemSch(S);
	if (Ans)
	{
		FStep = 99999;
		for (int i = 0; i < Adj[S].size(); ++i)
			if (!SG[Adj[S][i]]) FStep = min(FStep, Adj[S][i]);
		printf("First player wins flying to airport %d\n", FStep);
	}
	else
		printf("First player loses\n");
	return 0;
}
