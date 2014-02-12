#include <cstdio>
#include <cstring>

int N, K, x, sum;

int main()
{
	scanf("%d%d", &K, &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		sum += x;
		if (sum <= K) sum = 0;
		else sum -= K;
	}
	printf("%d\n", sum);
	return 0;
}
