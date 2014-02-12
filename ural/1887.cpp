#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, a[33], b[33], c[33];
bool isc[1<<10];
double e[1<<10], p[10];
double f[33][15];

double calce(int sta)
{
	if (isc[sta]) return e[sta];
	double a=1, b=0;
	for (int i = 0; i < 10; ++i)
		if ((sta|(1<<i))==sta) a -= p[i];
		else b += p[i]*calce(sta|(1<<i));
	b += 1;
	isc[sta] = 1;
	return e[sta]=b/a;
}



int main()
{
	int i, j, k, x, y;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		scanf("%d", a+i);
	for (i = 1; i <= N; ++i)
		scanf("%d", b+i);
	for (i = 1; i <= N; ++i)
		scanf("%d", c+i);
	memset(f, 0, sizeof(f));
	/*
	for (j = 0; j < 11; ++j)
		f[0][j] = 1.0/11;
	*/
	for (x = 0; x < 10; ++x)
		f[1][(a[1]*x*x+b[1]*x+c[1])%11] += 1.0/10;
	double pnow[22];
	for (i = 2; i <= N; ++i)
	{
		memset(pnow, 0, sizeof(pnow));
		for (x = 0; x < 10; ++x)
			pnow[(a[i]*x*x+b[i]*x+c[i])%11] += 1.0/10;
		for (x = 0; x < 11; ++x)
			for (y = 0; y < 11; ++y)
				f[i][(x*y)%11] += f[i-1][y]*pnow[x];
	}
	/*
	for (i = 1; i <= 10; ++i)
		printf("##%f\n", f[1][i]);
	*/
	for (i = 0; i < 10; ++i)
		p[i] = f[N][i];
	p[0] += f[N][10];
	/*
	for (i = 0; i < 10; ++i)
		printf("%f\n", p[i]);
	*/
	for (i = 0; i < 10; ++i)
		if (p[i]<1e-6)
		{
			puts("-1");
			return 0;
		}
	e[1023] = 0;
	isc[1023] = 1;
	double ans = calce(0);
	printf("%.7f\n", ans);
	return 0;
}
