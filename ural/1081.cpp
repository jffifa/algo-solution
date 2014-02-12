/*
	Problem: Ural1081
	Algorithm: DP
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int MaxN = 100;

int N, K;
int F[MaxN][2];
char Str[MaxN];

bool Gen()
{
	if (K > F[N][0]+F[N][1]) return 0;
	int Prev = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Prev == 1)
		{
			Str[i] = '0';
			Prev = 0;
			continue;
		}
		if (K <= F[N-i][0])
		{
			Str[i] = '0';
			Prev = 0;
		}
		else
		{
			Str[i] = '1';
			K -= F[N-i][0];
			Prev = 1;
		}
	}
	return 1;
}

int main()
{
	F[1][0] = 1;
	F[1][1] = 1;
	for (int i = 2; i <= 44; ++i)
	{
		F[i][0] = F[i-1][0]+F[i-1][1];
		F[i][1] = F[i-1][0];
	}
	scanf("%d%d", &N, &K);
	if (Gen())
		printf("%s\n", Str);
	else
		printf("-1\n");
	return 0;
}
