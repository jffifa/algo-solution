#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int f[60];

int main()
{
	int i, j;
	f[1] = f[2] = 1;
	f[3] = 2;
	scanf("%d", &N);
	for (i = 4; i <= N; ++i)
		f[i] = f[i-1]+f[i-3]+1;
	printf("%d\n", f[N]);
	return 0;
}
