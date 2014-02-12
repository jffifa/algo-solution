#include <cstdio>
#include <cstring>

int N;

int main()
{
	scanf("%d", &N);
	if (N>=1 && N<=4)
		puts("few");
	else if (N<=9)
		puts("several");
	else if (N<=19)
		puts("pack");
	else if (N<=49)
		puts("lots");
	else if (N<=99)
		puts("horde");
	else if (N<=249)
		puts("throng");
	else if (N<=499)
		puts("swarm");
	else if (N<=999)
		puts("zounds");
	else puts("legion");
	return 0;
}
