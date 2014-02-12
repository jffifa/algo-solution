/*
	Problem: Ural1053
	Algorithm: GCD...
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

int N, Ans, Tmp;

int gcd(int p, int q)
{
	int r;
	while (q)
	{
		r = p % q;
		p = q;
		q = r;
	}
	return p;
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &Tmp);
	Ans = Tmp;
	for (int i = 1; i < N; ++i)
	{
		scanf("%d", &Tmp);
		Ans = gcd(Ans, Tmp);
	}
	printf("%d\n", Ans);
	return 0;
}
