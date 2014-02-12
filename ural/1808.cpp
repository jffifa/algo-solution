#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp
{
	double x, y;
	sp () {}
	sp (double a, double b): x(a), y(b) {}
	void read() {scanf("%lf%lf", &x, &y);}
	void write() {printf("%f %f\n", x, y);}
};

sp operator-(const sp &u, const sp &v)
{return sp(u.x-v.x, u.y-v.y);}
sp operator+(const sp &u, const sp &v)
{return sp(u.x+v.x, u.y+v.y);}
sp operator*(double d, const sp &v)
{return sp(d*v.x, d*v.y);}

double dot(const sp &u, const sp &v)
{return u.x*v.x+u.y*v.y;}

double det(const sp &u, const sp &v)
{return u.x*v.y-u.y*v.x;}

double dir(const sp &p, const sp &u, const sp &v)
{return det(u-p, v-p);}

const sp ORG = sp(0, 0);

struct ss
{
	sp a, b;
	ss() {}
	ss(sp u, sp v): a(u), b(v) {}
};

double dis(const sp &u, const sp &v)
{
	double dx = u.x-v.x;
	double dy = u.y-v.y;
	return sqrt(dx*dx+dy*dy);
}

double nrmsqr(const sp &v)
{return v.x*v.x+v.y*v.y;}

double nrm(const sp &v)
{return sqrt(nrmsqr(v));}

sp rotate(const sp &p, double a, const sp &p0)
{
	sp res = p0, v = p-p0;
	double c = cos(a), s = sin(a);
	res.x += v.x*c-v.y*s;
	res.y += v.x*s+v.y*c;
	return res;
}

char lineintp(const ss &u, const ss &v, sp &p)
{
	double a1, b1, c1, a2, b2, c2;
	a1 = u.b.y - u.a.y;
	b1 = u.a.x - u.b.x;
	c1 = det(u.b, u.a);
	a2 = v.b.y - v.a.y;
	b2 = v.a.x - v.b.x;
	c2 = det(v.b, v.a);
	if (dcmp(a1*b2-b1*a2)==0)
		if (dcmp(det(u.a-v.a, u.a-v.b))==0) return 0;
		else return 1;
	else
	{
		double t = a2*b1-a1*b2;
		p.x = (b2*c1-b1*c2)/t;
		p.y = (a1*c2-a2*c1)/t;
		return 2;
	}
}

void qrd(double a, double b, double c, double &x1, double &x2)
{
	double d = b*b-4*a*c;
	x1 = (-b-sqrt(d))/(2*a);
	x2 = (-b+sqrt(d))/(2*a);
}

double r, fi;
sp p[2];
sp v[2];

ss calc(sp p, sp v)
{
	double a = nrmsqr(v), b = 2*(p.x*v.x+p.y*v.y), c = nrmsqr(p)-r*r;
	double t1, t2;
	sp hmr, mdk;
	qrd(a, b, c, t1, t2);
	hmr = p+(t1*v);
	mdk = p+(t2*v);
	hmr = dis(p, hmr)<dis(p, mdk)?hmr:mdk;
	//hmr.write();
	sp v1 = hmr-ORG, v2 = p-hmr;
	double kyk = fabs(det(v1, v2))/(fi*nrm(v1)*nrm(v2));
	if (kyk>1) kyk = 1;
	double ar = asin(kyk);
	sp syk = rotate(ORG, dcmp(det(v1, v2))*ar, hmr);
	return ss(hmr, syk);
}

int main()
{
	scanf("%lf%lf", &r, &fi);
	p[0].read(), v[0].read();
	p[1].read(), v[1].read();
	ss s[2];
	s[0] = calc(p[0], v[0]);
	s[1] = calc(p[1], v[1]);
	sp tmp;
	int sta = lineintp(s[0], s[1], tmp);
	if (sta == 0)
		puts("Yes");
	else if (sta==2 && dis(tmp, ORG)<r-EPS)
		puts("Yes");
	else
		puts("No");
	return 0;
}
