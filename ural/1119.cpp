/*
	Problem: Ural1119
	Algorithm: DP
	Time: O()
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 1002;
const double INF = 1e10;
const double S2 = sqrt(2e4);

int C, R, K, c, r;
double F[2][MaxN];
bool Dig[MaxN][MaxN];

int main()
{
	scanf("%d%d", &C, &R);
	scanf("%d", &K);
	while (K--)
	{
		scanf("%d%d", &c, &r);
		Dig[r][c] = 1;
	}
	int Cur = 0;
	F[Cur][0] = 0;
	for (r = 0; r <= R; ++r)
	{
		for (c = 0; c <= C; ++c)
		{
			if (r==0 && c==0) continue;
			F[Cur][c] = INF;
			if (r > 0) F[Cur][c] = min(F[Cur][c], F[1-Cur][c]+100);
			if (c > 0) F[Cur][c] = min(F[Cur][c], F[Cur][c-1]+100);
			if (Dig[r][c]) F[Cur][c] = min(F[Cur][c], F[1-Cur][c-1]+S2);
		}
		for (c = 0; c <= C; ++c)
			F[1-Cur][c] = F[Cur][c];
		Cur = 1-Cur;
	}
	printf("%.0f\n", F[1-Cur][C]);
	return 0;
}
