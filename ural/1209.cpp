/*
	Problem: Ural1209
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

LL T, K, N, R;

int main()
{
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld", &K);
		N = (LL)floor(sqrt((double)2*K));
		if (N*(N+1LL) >= K*2LL) N--;
		R = K-N*(N+1LL)/2LL;
		if (R == 1LL) printf("1");
		else printf("0");
		if (T) printf(" ");
		else printf("\n");
	}
	return 0;
}
