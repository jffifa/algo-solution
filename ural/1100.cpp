/*
	Problem: Ural1100
	Algorithm: stable_sort
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 150001;

struct ST
{int id, p;};
bool operator < (const ST &T1, const ST &T2)
{return T1.p > T2.p;}

int N;
ST T[MaxN];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &T[i].id, &T[i].p);
	stable_sort(T, T+N);
	for (int i = 0; i < N; ++i)
		printf("%d %d\n", T[i].id, T[i].p);
	return 0;
}
