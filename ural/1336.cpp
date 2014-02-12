#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int PSIZE = 100000;

typedef long long LL;

int p[PSIZE], pcnt=0;

bool prime(int n)
{
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (int i = 0; p[i]*p[i]<=n; ++i)
		if (n%p[i]==0) return 0;
	return n>1;
}

void initprime()
{
	p[pcnt++] = 2;
	for (int i = 3; i <= 100000; ++i)
		if (prime(i)) p[pcnt++] = i;
}

int pf(int n, int *f, int *nf)
{
	int cnt = 0;
	int n2 = (int)sqrt((double)n);
	for (int i = 0; n>1 && p[i]<=n2; ++i)
		if (n%p[i]==0)
		{
			for (nf[cnt]=0; n%p[i]==0; n/=p[i]) ++nf[cnt];
			f[cnt++] = p[i];
		}
	if (n > 1)
	{
		nf[cnt] = 1;
		f[cnt++] = n;
	}
	return cnt;
}

int N;
LL K, M;
int f[20], nf[20], cnt;

int main()
{
	int i, j, k;
	initprime();
	scanf("%d", &N);
	cnt = pf(N, f, nf);
	//printf("%d %d %d\n", cnt, f[0], nf[0]);
	K = M = 1;
	for (i = 0; i < cnt; ++i)
		if (nf[i] & 1)
		{
			K *= f[i];
			for (j = 0; j < (nf[i]+3)/2; ++j)
				M *= f[i];
		}
		else
			for (j = 0; j < nf[i]/2; ++j)
				M *= f[i];
	printf("%lld\n%lld\n", M, K);
	return 0;
}
