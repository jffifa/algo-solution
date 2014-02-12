#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

int main()
{
	scanf("%d", &N);
	if (N==2)
	{
		puts("2");
		puts("1 1");
	}
	else
	{
		printf("%d\n", 2*N-4);
		for (int i = 2; i < N; ++i)
			printf("%d ", i);
		for (int i = N-1; i >= 2; --i)
			printf("%d ", i);
	}
	return 0;
}
