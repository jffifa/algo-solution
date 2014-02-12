//ural1348
//geometry
//simple
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

inline double min(double a, double b)
{return a<b?a:b;}

inline double max(double a, double b)
{return a>b?a:b;}

struct sp
{
	double x, y;
	sp() {}
	sp(double xx, double yy): x(xx), y(yy) {}
	void read() {scanf("%lf%lf", &x, &y);}
};

struct ss
{
	sp p1, p2;
	ss() {}
	ss(sp p, sp q): p1(p), p2(q) {}
};

sp operator- (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y);}

sp operator+ (const sp &v1, const sp &v2)
{return sp(v1.x+v2.x, v1.y+v2.y);}

sp operator* (double d, const sp &v)
{return sp(d*v.x, d*v.y);}

double nrmsqr(const sp &v)
{return v.x*v.x+v.y*v.y;}

double dis(const sp &p1, const sp &p2)
{return sqrt(nrmsqr(p2-p1));}

double dot(const sp &v1, const sp &v2)
{return v1.x*v2.x+v1.y*v2.y;}

sp ptoseg(const sp &p, const ss &s)
{
	sp v = s.p2-s.p1, res;
	double t = (dot(p, v)-dot(s.p1, v))/dot(v, v);
	if (dcmp(t)>=0 && dcmp(t-1)<=0)
		res = s.p1+t*v;
	else
		res = dis(p, s.p1)<dis(p, s.p2) ? s.p1 : s.p2;
	return res;
}

double distoseg(const sp &p, const ss &s)
{return dis(p, ptoseg(p, s));}

sp a, b, c;
double l, d1, d2;

int main()
{
	a.read();
	b.read();
	c.read();
	scanf("%lf", &l);
	d1 = distoseg(c, ss(a, b));
	d2 = max(dis(c, a), dis(c, b));
	if (d1 > l)
		printf("%.2f\n", d1-l);
	else
		puts("0.00");
	if (d2 > l)
		printf("%.2f\n", d2-l);
	else
		puts("0.00");
	return 0;
}
