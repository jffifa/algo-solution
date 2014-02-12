/*
	Problem: Ural1086
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 15000;

int P[MaxN+10];
int N, now, t;

bool Prime(int x)
{
	for (int i = 0; P[i]<=(int)sqrt((double)x); ++i)
		if (x%P[i] == 0) return 0;
	return 1;
}

int main()
{
	P[now++] = 2;
	P[now++] = 3;
	for (int x = 4; now < MaxN; ++x)
		if (Prime(x)) P[now++] = x;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &t);
		printf("%d\n", P[t-1]);
	}
	return 0;
}
