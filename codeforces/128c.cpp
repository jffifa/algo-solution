#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007LL;

int N, M, K;
LL c[1010][1010];

int main()
{
	int i, j, k;
	scanf("%d%d%d", &N, &M, &K);
	if (K*2>N-1 || K*2>M-1)
	{
		puts("0");
		return 0;
	}
	c[0][0] = 1LL;
	for (i = 1; i <= max(N-1, M-1); ++i)
	{
		c[i][0] = 1;
		for (j = 1; j <= i; ++j)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%MOD;
	}
	printf("%lld\n", (c[N-1][2*K]*c[M-1][2*K])%MOD);
	return 0;
}
