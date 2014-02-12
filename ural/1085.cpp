/*
	Problem: Ural1085
	Algorithm: Floyd-Warshall
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 105;
const int INF = 0x1fffffff;

int N, M, K, L;
int Stop[MaxN], Money[MaxN], S[MaxN], Ans, AnsV, Cnt;
int G[MaxN][MaxN], MonTic[MaxN];

void CheckMin(int v)
{
	int Cnt = 0;
	for (int i = 0; i < K; ++i)
	{
		if (G[S[i]][v] >= INF) return;
		if (!MonTic[i])
			if (G[S[i]][v]*4 > Money[i]) return;
			else Cnt += G[S[i]][v]*4;
	}
	if (Cnt < Ans)
	{
		Ans = Cnt;
		AnsV = v;
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (i == j) G[i][j] = 0;
			else G[i][j] = INF;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &L);
		for (int j = 0; j < L; ++j)
			scanf("%d", &Stop[j]);
		for (int j = 0; j < L; ++j)
			for (int k = j+1; k < L; ++k)
			{
				G[Stop[j]][Stop[k]] = min(G[Stop[j]][Stop[k]], 1);
				G[Stop[k]][Stop[j]] = min(G[Stop[k]][Stop[j]], 1);
			}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
		scanf("%d%d%d", &Money[i], &S[i], &MonTic[i]);
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
	Ans = INF; 
	AnsV = 0;
	for (int i = 1; i <= N; ++i)
		CheckMin(i);
	if (AnsV)
		printf("%d %d\n", AnsV, Ans);
	else
		printf("0\n");
	return 0;
}
