/*
	Problem: Ural1051
	Algorithm: Game
	Time: O()
	Memory: O()
	Detail: Finding the law
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 100;

int N, M, Ans;

int main()
{
	scanf("%d%d", &N, &M);
	if (N > M) swap(N, M);
	if (N==1) Ans = M+1>>1;
	else
	{
		if (N%3==0 || M%3==0) Ans = 2;
		else Ans = 1;
	}
	printf("%d\n", Ans);
	return 0;
}
