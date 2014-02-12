#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int base[] = {0, 0, 65536, 59049, 65536, 15625, 46656, 16807, 32768, 59049, 10000};

int d[2][10000];
int mdk[12][70000];

int K, N;
int len[2];
int sum[50005];
int ans[50005];

inline bool cmp(int x, int y)
{
	if (sum[x]==sum[y]) return x<y;
	return sum[x]<sum[y];
}

int main()
{
	int i, j, s, t, hmr;
	scanf("%d%d", &K, &N);
	int b = base[K];
	for (i = 0; i < b; ++i)
	{
		int x = i;
		while (x)
		{
			mdk[K][i] += x%K;
			x /= K;
		}
	}
	/*
	for (i = 0; i < 20; ++i)
		printf("??%d ", mdk[10][i]);
	*/
	d[0][0] = d[1][0] = 1;
	len[0] = len[1] = 1;
	sum[0] = sum[1] = 1;
	for (i = 2; i < N; ++i)
	{
		t = i&1; s = t^1;
		hmr = 0;
		for (j = 0; j <= len[s]; ++j)
		{
			d[t][j] += d[s][j]+hmr;
			if (d[t][j] >= b)
			{
				d[t][j] -= b;
				hmr = 1;
			}
			else
				hmr = 0;
			sum[i] += mdk[K][d[t][j]];
		}
		if (d[t][len[t]]) len[t]++;
	}
	/*
	for (i = 0; i < N; ++i)
		printf("%d ", sum[i]);
	puts("");
	*/
	for (i = 0; i < N; ++i)
		ans[i] = i;
	sort(ans, ans+N, cmp);
	for (i = 0; i < N; ++i)
		printf("%d ", ans[i]+1);
	return 0;
}
