#include <cstdio>
#include <cstring>

int a, b, n;

int main()
{
	scanf("%d%d", &a, &b);
	n = a+b-1;
	printf("%d %d", n-a, n-b);
}
