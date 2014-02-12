#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K, ans;
int g[111], b[111];

int main()
{
	int i, j, k;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i)
		scanf("%d", g+i);
	for (i = 0; i < M; ++i)
		scanf("%d", b+i);
	sort(g, g+N);
	sort(b, b+M);
	if (N < M)
	{
		reverse(g, g+N);
		reverse(b, b+M);
		int sumg = 0;
		for (i = 0; i < N; ++i)
			sumg += g[i];
		int sumb = 0;
		for (i = 0; i < M; ++i)
			sumb += b[i];
		ans = 0x3fffffff;
		for (k = 0; k <= N; ++k)
		{
			ans = min(ans, sumg+k*sumb);
			sumg -= g[k];
			sumb -= b[k];
		}
	}
	else
	{
		for (i = 0; i < N-M; ++i)
			ans += g[i];
	}
	printf("%d\n", ans);
	return 0;
}
