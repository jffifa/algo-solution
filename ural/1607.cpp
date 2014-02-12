#include <cstdio>
#include <cstring>

int a, b, c, d, ans;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	ans = a;
	while (a < c)
	{
		if (a+b>=c) {ans = c; break;}
		a += b;
		if (c-d<=a) {ans = a; break;}
		c -= d;
	}
	printf("%d\n", ans);
	return 0;
}
