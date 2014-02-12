/*
	Problem: Ural1146
	Algorithm: DP
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 101;
const int INF = 99999999;

int R, C, Ans;
int M[MaxN][MaxN];
int SumC[MaxN][MaxN];
int Sum[MaxN], F[MaxN];

int main()
{
	scanf("%d", &R); C = R;
	for (int r = 1; r <= R; ++r)
		for (int c = 1; c <= C; ++c)
			scanf("%d", &M[r][c]);
	for (int c = 1; c <= C; ++c)
	{
		SumC[0][c] = 0;
		for (int r = 1; r <= R; ++r)
			SumC[r][c] = SumC[r-1][c]+M[r][c];
	}
	Ans = -INF;
	for (int r1 = 1; r1 <= R; ++r1)
		for (int r2 = r1; r2 <= R; ++r2)
		{
			for (int c = 1; c <= C; ++c)
				Sum[c] = SumC[r2][c]-SumC[r1-1][c]+Sum[c-1];
			int Min = 0;
			for (int c = 1; c <= C; ++c)
			{
				Ans = max(Ans, Sum[c]-Min);
				Min = min(Min, Sum[c]);
			}
		}
	printf("%d\n", Ans);
	return 0;
}
