/*
	Problem: Ural1397
	Algorithm: Greedy, TRICKY!!!
	Time: O()
	Memory: O()
	Detail: PRETTY TRICKY!!!
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 555;

int N;
double x[MaxN<<1], y[MaxN<<1];
double w[MaxN<<1];
double p[2];

int main()
{
	while (~scanf("%d", &N))
	{
		N <<= 1;
		memset(w, 0, sizeof(w));
		p[0] = p[1] = 0;
		for (int i = 0; i < N; ++i)
			scanf("%lf%lf", &x[i], &y[i]);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				double dx = x[i]-x[j];
				double dy = y[i]-y[j];
				w[i] += sqrt(dx*dx+dy*dy);
			}
			w[i] /= 2;
		}
		sort(w, w+N);
		for (int i = 0; i < N; ++i)
			p[i&1] += w[i];
		printf("%.3f\n", fabs(p[0]-p[1]));
	}
	return 0;
}
