#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int d[1024];

int main()
{
	int i, j, k;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i)
		scanf("%d", d+i);
	for (i = 0; i < 10; ++i)
		printf("%d", d[(M+i)%N]);
	puts("");
	return 0;
}
