#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	if (N==2) {puts("0"); return 0;}
	if (K>N/2) K = N+1-K;
	printf("%d\n", N-K-2);
	return 0;
}
