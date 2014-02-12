#include <cstdio>
#include <cstring>

int cnt[800], ans;
int N, x;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		++cnt[x];
	}
	for (int i = 600; i <= 700; ++i)
		ans += cnt[i]/4;
	printf("%d\n", ans);
}
