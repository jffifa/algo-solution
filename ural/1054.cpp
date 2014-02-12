/*
	Problem: Ural1054
	Algorithm: Recursion
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 31;

int N, D[MaxN], Ans;

char Search(int i, int from, int to, int tmp)
{
	if (i < 0) return 1;
	if (D[i] == tmp) return 0;
	if (D[i] == from)
		return Search(i-1, from, tmp, to);
	else
	{
		Ans += 1<<i;
		return Search(i-1, tmp, to, from);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &D[i]);
	if (Search(N-1, 1, 2, 3))
		printf("%d\n", Ans);
	else
		printf("-1\n");
	return 0;
}
