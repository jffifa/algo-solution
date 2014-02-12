/*
	Problem: Ural1110
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100;

int N, M, Y, Cnt;

int Pow(int x, int p)
{
	int ans = 1;
	for(; p; p >>= 1)
	{
		if (p & 1) ans = (ans*x) % M;
		x = (x*x) % M;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &N, &M, &Y);
	for (int i = 0; i < M; ++i)
	{
		if (Pow(i, N) == Y)
		{
			if (Cnt) printf(" ");
			printf("%d", i);
			++Cnt;
		}
	}
	if (!Cnt) printf("-1");
	printf("\n");
	return 0;
}
