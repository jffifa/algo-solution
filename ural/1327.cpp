/*
	Problem: 1327
	Algorithm: none
	Time: O()
	Memory: O()
	Detail: simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100;

int N, M, ans;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = N; i <= M; ++i)
		if (i&1) ++ans;
	printf("%d\n", ans);
	return 0;
}
