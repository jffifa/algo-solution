#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL f[50][3];
int N;

int main()
{
	int i, j, k, l;
	scanf("%d", &N);
	f[1][0]=f[1][1]=f[2][0]=f[2][1]=1;
	for (i = 3; i <= N; ++i)
	{
		for (j = 0; j < 2; ++j)
			f[i][j] = f[i-1][!j]+f[i-2][!j];
	}
	printf("%lld\n", f[N][0]+f[N][1]);
	return 0;
}
