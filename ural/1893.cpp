#include <cstdio>
#include <cstring>

int r;
char c;

int main()
{
	scanf("%d", &r);
	scanf("%c", &c);
	if (r<=2)
	{
		if (c=='A'||c=='D') puts("window");
		else puts("aisle");
	}
	else if (r<=20)
	{
		if (c=='A'||c=='F') puts("window");
		else puts("aisle");
	}
	else
	{
		if (c=='A'||c=='K') puts("window");
		else if (c=='C'||c=='D'||c=='G'||c=='H') puts("aisle");
		else puts("neither");
	}
	return 0;
}
