#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int x[500005];

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", x+i);
	sort(x, x+N);
	printf("%d\n", x[N/2]); 
	return 0;
}
