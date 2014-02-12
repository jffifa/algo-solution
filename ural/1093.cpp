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

struct spoint
{
	double x, y, z;
	spoint() {}
	spoint(double xx, double yy, double zz): x(xx), y(yy), z(zz) {}
	void read()
	{scanf("%lf%lf%lf", &x, &y, &z);}
};

spoint operator - (const spoint &v1, const spoint &v2)
{return spoint(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);}

double dot(const spoint &v1, const spoint &v2)
{return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;}

double norm(const spoint &v)
{return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);}

double dis(const spoint &p1, const spoint &p2)
{return norm(p2-p1);}

spoint c, n, s, v, p;
double r, t1, t2, i, j, k;

//ax+b=0
//0 for no solution, 1 for one solution, 2 for infinitive solution
char lneq(double a, double b, double &x)
{
	if (DBLCMP(a) == 0)
	{
		if (DBLCMP(b) == 0) return 2;
		return 0;
	}
	x = -b/a;
	return 1;
}

//ax^2+bx+c=0, a!=0
//0 for no solution, 1 for one solution, 2 for 2 solutions
//x1 <= x2
char qdeq(double a, double b, double c, double &x1, double &x2)
{
	double delta = b*b-4*a*c;
	if (delta < 0) return 0;
	x1 = (-b+sqrt(delta))/(2*a);
	x2 = (-b-sqrt(delta))/(2*a);
	if (x1 > x2) swap(x1, x2);
	return DBLCMP(delta) ? 2 : 1;
}

int main()
{
	c.read();
	n.read();
	scanf("%lf", &r);
	//printf("##%f\n", dis(spoint(0,0,0), spoint(1,1,1)));
	s.read();
	v.read();
	i = -5.0*n.z; j = dot(n, v); k = dot(n, s-c);
	if (DBLCMP(i)==0)
	{
		char sta = lneq(j, k, t1);
		if (sta==0 || sta==2 || DBLCMP(t1) <= 0)
		{
			puts("MISSED");
			return 0;
		}
		p.x = s.x+v.x*t1;
		p.y = s.y+v.y*t1;
		p.z = s.z+v.z*t1-5.0*t1*t1;
		if (DBLCMP(dis(p, c)-r) < 0)
		{
			puts("HIT");
			return 0;
		}
		puts("MISSED");
		return 0;
	}
	if (!qdeq(i, j, k, t1, t2))
	{
		puts("MISSED");
		return 0;
	}
	if (DBLCMP(t1) > 0)
	{
		p.x = s.x+v.x*t1;
		p.y = s.y+v.y*t1;
		p.z = s.z+v.z*t1-5.0*t1*t1;
		if (DBLCMP(dis(p, c)-r) < 0)
		{
			puts("HIT");
			return 0;
		}
	}
	if (DBLCMP(t2) > 0)
	{
		p.x = s.x+v.x*t2;
		p.y = s.y+v.y*t2;
		p.z = s.z+v.z*t2-5.0*t2*t2;
		if (DBLCMP(dis(p, c)-r) < 0)
		{
			puts("HIT");
			return 0;
		}
	}
	puts("MISSED");
	return 0;
}
