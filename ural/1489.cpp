#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

inline char dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp
{
	double x, y, z;
	sp() {}
	sp(double xx, double yy, double zz): x(xx), y(yy), z(zz) {}
};

sp operator- (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);}

double nrmsqr(const sp &v)
{return v.x*v.x+v.y*v.y+v.z*v.z;}

double dis(const sp &p1, const sp &p2)
{return sqrt(nrmsqr(p2-p1));}

double a, b, c, x, y;
sp m, n;

void trans(double hmr, double mdk, sp &p)
{
	if (dcmp(hmr)>=0 && dcmp(hmr-c)<0)
	{
		p.y = 0;
		p.x = hmr;
		p.z = b+c+b-mdk;
		return;
	}
	if (dcmp(hmr-c-a)>0 && dcmp(hmr-c-a-c)<=0)
	{
		p.y = a;
		p.x = c+a+c-hmr;
		p.z = b+c+b-mdk;
		return;
	}
	p.y = hmr-c;
	if (dcmp(mdk)>=0 && dcmp(mdk-b)<=0)
	{
		p.x = 0;
		p.z = mdk;
		return;
	}
	if (dcmp(mdk-b)>=0 && dcmp(mdk-b-c)<=0)
	{
		p.z = b;
		p.x = mdk-b;
		return;
	}
	if (dcmp(mdk-b-c)>=0 && dcmp(mdk-b-c-b)<=0)
	{
		p.x = c;
		p.z = b+c+b-mdk;
		return;
	}
	if (dcmp(mdk-b-c-b)>=0 && dcmp(mdk-b-c-b-c)<=0)
	{
		p.z = 0;
		p.x = b+c+b+c-mdk;
		return;
	}
	while (1) puts("homura");
}

int main()
{
	scanf("%lf%lf%lf", &a, &b, &c);
	scanf("%lf%lf", &x, &y);
	trans(x, y, m);
	//printf("%f %f %f\n", m.x, m.y, m.z);
	scanf("%lf%lf", &x, &y);
	trans(x, y, n);
	//printf("%f %f %f\n", n.x, n.y, n.z);
	printf("%.8f\n", dis(m, n));
	return 0;
}
