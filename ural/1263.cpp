#include <cstdio>
#include <cstring>
#include <cmath>

int N, M, x;
int cnt[10001];

int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		++cnt[x];
	}
	for (int i = 1; i <= M; ++i)
	{
		printf("%.2f", 100.0*cnt[i]/N);
		puts("%");
	}
}
