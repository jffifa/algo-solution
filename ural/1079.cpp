/*
	Problem: Ural1079
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

int A[MaxN+1];
int Ans[MaxN+1], Max, N;

int main()
{
	A[0] = 0; A[1] = 1;
	Ans[0] = 0; Ans[1] = 1;
	Max = 1;
	for (int i = 2; i <= MaxN; ++i)
	{
		if (i & 1) A[i] = A[i>>1]+A[(i>>1)+1];
		else A[i] = A[i>>1];
		Max = max(Max, A[i]);
		Ans[i] = Max;
	}
	while (scanf("%d", &N), N)
		printf("%d\n", Ans[N]);
	return 0;
}
