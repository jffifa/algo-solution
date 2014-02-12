/*
	Problem: Ural1073
	Algorithm: DP
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 60000;

int N, F[MaxN+1], bd;

int main()
{
	scanf("%d", &N);
	memset(F, 255, sizeof(F));
	F[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		bd = (int)floor(sqrt((double)i));
		F[i] = MaxN;
		for (int j = bd; j >= 1; --j)
			F[i] = min(F[i], F[i-j*j]+1);
	}
	printf("%d\n", F[N]);
	return 0;
}
