#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//N+M==sum
int N, M;
int n, m;

int main()
{
	scanf("%d", &N);
	int t = N, p = 1;
	while (t)
	{
		if (t%3==2)
		{
			M += p;
			t++;
		}
		t/=3, p*=3;
	}
	if (!M) M = p;
	printf("%d %d\n", N+M, M);
	return 0;
}
