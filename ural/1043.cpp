#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

inline int DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct spoint
{
	double x, y;
	spoint () {}
	spoint (double xx, double yy): x(xx), y(yy) {}
};

spoint operator - (const spoint &v1, const spoint &v2)
{return spoint(v1.x-v2.x, v1.y-v2.y);}

double normsqr(const spoint &v)
{return v.x*v.x+v.y*v.y;}

double dis(const spoint &p1, const spoint &p2)
{return sqrt(normsqr(p1-p2));}

void nrmlz(double &ast, double &aed)
{
	if (ast > aed)
		if (aed >= 0) ast -= 2*PI;
		else aed += 2*PI;
}

bool inside (double ast, double a, double aed)
{
	nrmlz(ast, aed);
	if (ast<a && a<aed) return 1;
	if (ast<a-2*PI && a-2*PI<aed) return 1;
	if (ast<a+2*PI && a+2*PI<aed) return 1;
	return 0;
}

spoint p[3], pmid;
double a[3], amid;
spoint o;
double rad;
double u, d, l, r;
int iu, id, il, ir;

int main()
{
	for (int i = 0; i < 3; ++i)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	double a1, a2, b1, b2, c1, c2;
	a1 = p[1].x-p[0].x;
	a2 = p[2].x-p[0].x;
	b1 = p[1].y-p[0].y;
	b2 = p[2].y-p[0].y;
	c1 = (normsqr(p[1])-normsqr(p[0]))/2;
	c2 = (normsqr(p[2])-normsqr(p[0]))/2;
	o.x = (c1*b2-c2*b1)/(a1*b2-a2*b1);
	o.y = (c1*a2-c2*a1)/(b1*a2-b2*a1);
	rad = dis(o, p[0]);
	//printf("%f\n", rad);
	//printf("%f %f %f\n", dis(p[0], o), dis(p[1], o), dis(p[2], o));
	for (int i = 0; i < 3; ++i)
		a[i] = atan2(p[i].y-o.y, p[i].x-o.x);
	if (!inside(a[0], a[2], a[1]))
	{
		swap(a[0], a[1]);
		swap(p[0], p[1]);
	}
	l = min(p[0].x, p[1].x);
	r = max(p[0].x, p[1].x);
	d = min(p[0].y, p[1].y);
	u = max(p[0].y, p[1].y);
	if (inside(a[0], 0, a[1])) r = max(r, o.x+rad);
	if (inside(a[0], PI, a[1])) l = min(l, o.x-rad);
	if (inside(a[0], -PI/2, a[1])) d = min(d, o.y-rad);
	if (inside(a[0], PI/2, a[1])) u = max(u, o.y+rad);
	iu = (int)ceil(u-EPS);
	id = (int)floor(d+EPS);
	il = (int)floor(l+EPS);
	ir = (int)ceil(r-EPS);
	printf("%d\n", (iu-id)*(ir-il));
	return 0;
}
