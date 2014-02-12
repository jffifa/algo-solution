#include <cstdio>
#include <cstring>

int b, r, y, k;
int ans;
char str[10];

int main()
{
	scanf("%d%d%d", &b, &r, &y);
	ans = 1;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%s", str);
		if (str[0]=='R') ans *= r;
		if (str[0]=='Y') ans *= y;
		if (str[0]=='B') ans *= b;
	}
	printf("%d\n", ans);
	return 0;
}
