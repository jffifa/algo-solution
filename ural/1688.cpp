#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL pay, x, sum;
int N;

int main()
{
	scanf("%lld%d", &pay, &N);
	pay *= 3;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%lld", &x);
		sum += x;
		if (sum > pay)
		{
			printf("Free after %d times.\n", i);
			return 0;
		}
	}
	puts("Team.GOV!");
	return 0;
}
