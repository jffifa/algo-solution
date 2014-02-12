/*
	Problem: Ural1057
	Algorithm: DP
	Time: O()
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100;

int X, Y, K, B;
int F[33][22], C[33][22];
int Len, Dig[33];

int Calc(int x)
{
	if (x == 0) return 0;
	Len = 0;
	memset(Dig, 0, sizeof(Dig));
	while (x)
	{
		Dig[Len++] = x % B;
		x /= B;
	}
	memset(F, 0, sizeof(F));
	F[0][0] = 1;
	for (int i = 1; i <= Len; ++i)
		for (int j = 0; j <= i; ++j)
			if (j == 0) F[i][j] = 1;
			else if (Dig[i-1] == 0) F[i][j] = F[i-1][j];
			else if (Dig[i-1] == 1) F[i][j] = C[i-1][j]+F[i-1][j-1];
			else F[i][j] = C[i][j];
	return F[Len][K];
}

int main()
{
	scanf("%d%d%d%d", &X, &Y, &K, &B);
	C[0][0] = 1;
	for (int i = 1; i < 33; ++i)
		for (int j = 0; j < 22; ++j)
			if (!j) C[i][j] = 1;
			else C[i][j] = C[i-1][j]+C[i-1][j-1];
	printf("%d\n", Calc(Y)-Calc(X-1));
	return 0;
}
