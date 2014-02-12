/*
	Problem: Ural1078
	Algorithm: MemSch, Graph
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MaxN = 600;

int N, L[MaxN], R[MaxN], F[MaxN], Next[MaxN], AnsV, Path[MaxN];
vector<int> Adj[MaxN];

void Print(int u)
{
	int v = Next[u];
	if (v) Print(v);
	printf("%d ", u);
}

int MemSch(int u)
{
	if (F[u] > 0) return F[u];
	int v;
	int Tmp, Max = 0;
	for (int i = 0; i < Adj[u].size(); ++i)
	{
		v = Adj[u][i];
		if ((Tmp = MemSch(v)) > Max)
		{
			Max = Tmp;
			Next[u] = v;
		}
	}
	return F[u] = Max+1;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &L[i], &R[i]);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (L[i]<L[j] && R[i]>R[j])
				Adj[i].push_back(j);
	for (int i = 1; i <= N; ++i)
		MemSch(i);
	AnsV = 0;
	for (int i = 1; i <= N; ++i)
		if (F[i] > F[AnsV]) AnsV = i;
	printf("%d\n", F[AnsV]);
	Print(AnsV);
	printf("\n");
	return 0;
}
