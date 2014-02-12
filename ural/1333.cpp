//ural1333
//stO Monte Carlo Orz
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct sp
{double x, y, r;};

double dis(const sp &p1, const sp &p2)
{
	double dx = p1.x-p2.x;
	double dy = p1.y-p2.y;
	return sqrt(dx*dx+dy*dy);
}

int N;
sp p[11], hmr;

int main()
{
	srand(time(NULL));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].r);
	int rndtime = 1000000;
	int cnt = 0;
	for (int t = 0; t < rndtime; ++t)
	{
		hmr.x = (double)(((rand()%1000)*1000+rand()%1000)%100000);
		hmr.x /= 100000;
		hmr.y = (double)(((rand()%1000)*1000+rand()%1000)%100000);
		hmr.y /= 100000;
		for (int i = 0; i < N; ++i)
			if (dis(hmr, p[i])<=p[i].r) {++cnt; break;}
	}
	printf("%.2f\n", 100.0*(double)cnt/(double)rndtime);
	return 0;
}
