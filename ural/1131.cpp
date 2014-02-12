/*
	Problem: Ural1131
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

inline int min(int a, int b)
{return a<b ? a : b;}

int N, K, now, ans, r;

int main()
{
	scanf("%d%d", &N, &K);
	now = 1;
	while (now < K && now < N)
	{
		ans++;
		now <<= 1;
	}
	//printf("%d %d\n", ans, now);
	if (now < N)
	{
		r = (N-now)/K;
		ans += r;
		now += r*K;
		if (now < N) {now += K; ans++;}
	}
	printf("%d\n", ans);
	return 0;
}
