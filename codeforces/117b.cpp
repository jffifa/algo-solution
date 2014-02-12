#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL a, b, m;

int main()
{
	scanf("%I64d%I64d%I64d", &a, &b, &m);
	if (b >= m) puts("2");
	else
	{
		int i, j, k;
		for (i = 0; i <= min(m, a); ++i)
		{
			//printf("%I64d\n", (m-((LL)a*1000000000LL)%m)%m);
			if ((m-((LL)i*1000000000LL)%m)%m > b)
			{
				printf("1 %09d\n", (int)i);
				return 0;
			}
		}
		puts("2");
	}
	return 0;
}
