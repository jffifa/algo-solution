#include <cstdio>
#include <cstring>

int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	if ((N*M)&1) puts("[second]=:]");
	else puts("[:=[first]");
	return 0;
}
