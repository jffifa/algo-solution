#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, ans, cnt;
int g[111][111];
int up[111], down[111];

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			scanf("%d", &g[i][j]);
	memset(up, 0, sizeof(up));
	memset(down, 0, sizeof(down));
	for (i = 0; i < N; ++i)
		for (j = i+1; j < N; ++j)
			up[i] += g[i][j];
	for (j = 0; j < N; ++j)
		for (i = 0; i < j; ++i)
			down[j] += g[i][j];
	cnt = 0;
	for (i = 0; i < N; ++i)
	{
		cnt += up[i]-down[i];
		ans = max(ans, cnt);
	}
	memset(up, 0, sizeof(up));
	memset(down, 0, sizeof(down));
	for (i = 0; i < N; ++i)
		for (j = 0; j < i; ++j)
			up[i] += g[i][j];
	for (j = 0; j < N; ++j)
		for (i = j+1; i < N; ++i)
			down[j] += g[i][j];
	cnt = 0;
	for (i = N-1; i >= 0; --i)
	{
		cnt += up[i]-down[i];
		ans = max(ans, cnt);
	}
	printf("%d\n", ans%36?ans/36+1:ans/36);
	return 0;
}
