/*
	Problem: Ural1059
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 1001;

int N, M;

int main()
{
	scanf("%d", &N);
	printf("%d\n", 0);
	for (int i = 1; i <= N; ++i)
		printf("X\n*\n%d\n+\n", i);
	return 0;
}
