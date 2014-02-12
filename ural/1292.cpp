#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int N, K, L, ans;

int calc(int K)
{
	int res = 0;
	int d;
	while (K)
	{
		d = K%10;
		res += d*d*d;
		K /= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &K, &L);
		ans = K;
		for (int i = 1; i < N; ++i)
		{
			if (ans == 153) break;
			ans = calc(ans);
		}
		printf("%d\n", ans-L);
	}
	return 0;
}
