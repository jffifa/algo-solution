#include <cstdio>
#include <cstring>

int N;

int main()
{
	scanf("%d", &N);
	if (N==0 || N>2) puts("-1");
	else if (N==1) puts("1 2 3");
	else if (N==2) puts("3 4 5");
	return 0;
}
