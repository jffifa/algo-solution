#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int obs[105];
int N, ex;

int main()
{
	int i, j, k, l, r;
	scanf("%d%d", &N, &ex);
	for (i = 0; i < N; ++i)
		scanf("%d", obs+i);
	obs[N++] = -99999;
	obs[N++] = 99999;
	sort(obs, obs+N);
	for (i = 0; i < N; ++i)
	{
		if (obs[i]>0) break;
		l = obs[i];
	}
	for (i = N-1; i >= 0; --i)
	{
		if (obs[i]<0) break;
		r = obs[i];
	}
	if (ex<l || ex>r) puts("Impossible");
	else if (ex < 0) printf("%d %d\n", 2*r-ex, -ex);
	else if (ex > 0) printf("%d %d\n", ex, -2*l+ex);
	else /*printf("%d %d\n", 2*r, -2*l);*/puts("0 0");
}
