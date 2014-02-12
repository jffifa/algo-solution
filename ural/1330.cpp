#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int sum[16384];

int main()
{
	int i, l, r;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", sum+i);
		sum[i] += sum[i-1];
	}
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r]-sum[l-1]);
	}
	return 0;
}
