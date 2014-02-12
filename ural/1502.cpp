#include <cstdio>
#include <cstring>

typedef long long LL;

LL N, ans;

int main()
{
	scanf("%lld", &N);
	for (int i = 0; i <= N; ++i)
	{
		ans += (LL)i*(N+1-i);
		ans += (LL)i*(i+1);
	}
	printf("%lld\n", ans);
}
