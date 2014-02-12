#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int a1, b1, c1, a2, b2, c2;
int Sta1, Sta2;

int GetS(int a, int b, int c)
{
	if (a==0 && b==0)
	{
		if (c==0) return 2;
		else return 0;
	}
	return 1;
}

int Judge()
{
	if (a1*b2 == a2*b1)
	{
		if ((a1*c2==a2*c1) && (b1*c2==b2*c1)) return -1;
		return 0;
	}
	return 1;
}

int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("std.out", "w", stdout);
	while(~scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2))
	{
		Sta1 = GetS(a1, b1, c1);
		Sta2 = GetS(a2, b2, c2);
		if (Sta1 == 1 && Sta2 == 1)
		{
			printf("%d\n", Judge());
			continue;
		}
		if (Sta1 == 0 || Sta2 == 0)
		{
			printf("0\n");
			continue;
		}
		printf("-1\n");
	}
	return 0;
}
