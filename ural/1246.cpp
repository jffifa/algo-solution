#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

inline char DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct sp
{
	double x, y;
	sp () {}
	sp (double xx, double yy): x(xx), y(yy) {}
	void read() {scanf("%lf%lf", &x, &y);}
};

sp operator - (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y);}

double det(const sp &v1, const sp &v2)
{return v1.x*v2.y-v2.x*v1.y;}

double dir(const sp &p0, const sp &p1, const sp &p2)
{return det(p1-p0, p2-p0);}

const sp ORIGIN = sp(0, 0);

bool cntclkwise(int N, sp p[])
{
	double cnt = 0;
	for (int i = 0; i < N; ++i)
		cnt += dir(p[i], p[i+1], ORIGIN);
	return DBLCMP(cnt) > 0;
}

int N;
sp p[200002];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		p[i].read();
	p[N] = p[0];
	if (cntclkwise(N, p))
		puts("ccw");
	else
		puts("cw");
	return 0;
}
