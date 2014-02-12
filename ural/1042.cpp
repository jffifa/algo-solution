/*
	Problem: Ural1042
	Algorithm: Gauss Elimination
	Time: O(N^3)
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 255;

int N, M, t;
char a[MAXN][MAXN];

//modulo 2: "+"=="^", "*"=="&"

//AX=B
//a=[A|B]
//return value: -1 for no sol, 0 for only one sol, >0 for how many free elements
int gauss(int N, int M, char a[][MAXN])
{
	int i, j, k, r;
	for (i = 0; i < N; ++i)
	{
		for (r = i; r < N; ++r)
			if (a[r][i]) break;
		//if (r==N) return -1;
		for (k = i; k <= N; ++k)
			swap(a[i][k], a[r][k]);
		for (j = i+1; j < N; ++j)
		if (a[j][i])
			for (k = i; k <= N; ++k)
				a[j][k] ^= a[i][k];
	}
	for (i = N-1; i >= 0; --i)
		for (j = i+1; j < N; ++j)
			a[i][N] ^= a[j][N]&a[i][j];
	return 0;
}

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		while (scanf("%d", &t), t!=-1) a[t-1][i] = 1;
		a[i][N] = 1;
	}
	gauss(N, N, a);
	for (i = 0; i < N; ++i)
		if (a[i][N]) printf("%d ", i+1);
	puts("");
	return 0;
}
