/*
	Problem: Ural1056
	Algorithm: Graph, Diameter of Tree
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int MaxN = 10001;

int N, u, v, S, T, Dia;
int Ans[2], a;
char Vis[MaxN];
int Prev[MaxN], d[MaxN];
vector<int> Adj[MaxN];
vector<int> DiaV;

void DFS(int u)
{
	Vis[u] = 1;
	int v;
	for (int i = 0; i < Adj[u].size(); ++i)
	{
		v = Adj[u][i];
		if (!Vis[v])
		{
			Prev[v] = u;
			d[v] = d[u]+1;
			DFS(v);
		}
	}
}

int FindDia()
{
	memset(Vis, 0, sizeof(Vis));
	memset(d, 0, sizeof(d));
	memset(Prev, 0, sizeof(Prev));
	DFS(1);
	S = 1;
	for (u = 1; u <= N; ++u)
		if (d[u] > d[S]) S = u;
	memset(Vis, 0, sizeof(Vis));
	memset(d, 0, sizeof(d));
	memset(Prev, 0, sizeof(Prev));
	DFS(S);
	T = S;
	for (u = 1; u <= N; ++u)
		if (d[u] > d[T]) T = u;
	u = T;
	while (u) {DiaV.push_back(u); u = Prev[u];}
	return d[T];
}

int main()
{
	scanf("%d", &N);
	for (int i = 2; i <= N; ++i)
	{
		scanf("%d", &u);
		Adj[u].push_back(i);
		Adj[i].push_back(u);
	}
	Dia = FindDia();
	/*
	for (int i = 0; i < DiaV.size(); ++i)
		printf("%d ", DiaV[i]);
	printf("\n");
	*/
	for (int i = 0; i < DiaV.size(); ++i)
		if (abs(Dia-(d[DiaV[i]]<<1)) < 2) Ans[a++] = DiaV[i];
	if (a == 1)
		printf("%d\n", Ans[0]);
	else
	{
		if (Ans[0]>Ans[1]) swap(Ans[0], Ans[1]);
		printf("%d %d\n", Ans[0], Ans[1]);
	}
	return 0;
}
