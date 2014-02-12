#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, now;
int x[55], y[55];

int main()
{
	int i, j, k;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i)
	{
		x[i] = i+1;
		if (i) putchar(' ');
		printf("%d", x[i]);
	}
	puts("");
	for (i = 0; i < M; ++i)
	{
		y[i] = N*(i+1)+1;
		if (i) putchar(' ');
		printf("%d", y[i]);
	}
	return 0;
}
