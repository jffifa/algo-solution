#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool num[1000000];
char s[100010], n[7];

int main()
{
	int i, j, k, len;
	scanf("%s", s);
	len = strlen(s);
	int now = 1;
	for (i = 1; i <= 6; ++i)
	{
		for (j = 0; j <= len-i; ++j)
		{
			strncpy(n, s+j, i);
			num[atoi(n)] = 1;
		}
		for (j = now; j < now*10; ++j)
			if (!num[j])
			{
				printf("%d\n", j);
				return 0;
			}
		now *= 10;
	}
	puts("1000000");
	return 0;
}
