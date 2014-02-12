#include <cstdio>
#include <cstring>
#include <cmath>

int N, K;
int ans;

int main()
{
	scanf("%d%d", &N, &K);
	if (N==1)
	{
		puts("2");
		return 0;
	}
	ans = (int)ceil(2.0*N/K);
	printf("%d\n", ans);
}
