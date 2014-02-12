#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int sum[505];
int f[505][505];

int main()
{
	int i, j, k;
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", sum+i);
		sum[i] += sum[i-1];
	}
	memset(f, 127, sizeof(f));
	f[0][0] = 0;
	for (j = 1; j <= K; ++j)
		for (i = j; i <= N; ++i)
			for (k = j-1; k < i; ++k)
				f[i][j] = min(f[i][j], f[k][j-1]+(sum[i]-sum[k])*(i-k-(sum[i]-sum[k])));
	printf("%d\n", f[N][K]);
	return 0;
}
