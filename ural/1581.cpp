#include <cstdio>
#include <cstring>

int N, now, x, num;

int main()
{
	scanf("%d", &N);
	N--;
	scanf("%d", &now);
	num = 1;
	while (N--)
	{
		scanf("%d", &x);
		if (x != now)
		{
			printf("%d %d ", num, now);
			now = x;
			num = 1;
		}
		else num++;
	}
	printf("%d %d\n", num, now);
}
