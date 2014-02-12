/*
	Problem: Ural1710
	Algorithm: Geometry
	Time: O()
	Memory: O()
	Detail: you should be careful
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0?1:-1;
}

struct spoint
{
	double x, y;
	spoint () {}
	spoint (double xx, double yy): x(xx), y(yy) {}
};

spoint operator - (const spoint &v1, const spoint &v2)
{return spoint(v1.x-v2.x, v1.y-v2.y);}

spoint operator + (const spoint &v1, const spoint &v2)
{return spoint(v1.x+v2.x, v1.y+v2.y);}

spoint operator * (double d, const spoint &v)
{return spoint(v.x*d, v.y*d);}

double dot(const spoint &v1, const spoint &v2)
{return v1.x*v2.x+v1.y*v2.y;}

spoint pa, pb, pc, pcc;

bool judge()
{
	double dx, dy;
	dx = pb.x-pc.x;
	dy = pb.y-pc.y;
	double a = sqrt(dx*dx+dy*dy);
	dx = pc.x-pa.x;
	dy = pc.y-pa.y;
	double b = sqrt(dx*dx+dy*dy);
	dx = pa.x-pb.x;
	dy = pa.y-pb.y;
	double c = sqrt(dx*dx+dy*dy);
	if (DBLCMP(a*a+b*b-c*c)==0) return 1;
	return 0;
}

bool kuroko()
{
	if (DBLCMP(dot(pc-pa, pcc-pa))<=0) return 1;
	return 0;
}

int main()
{
	scanf("%lf%lf", &pa.x, &pa.y);
	scanf("%lf%lf", &pb.x, &pb.y);
	scanf("%lf%lf", &pc.x, &pc.y);
	if (judge())
	{
		puts("YES");
		return 0;
	}
	spoint h;
	spoint v = pc-pa;
	double k = dot(v, pb-pa)/(v.x*v.x+v.y*v.y);
	h = pa+(k*v);
	pcc.x = 2*h.x-pc.x;
	pcc.y = 2*h.y-pc.y;
	if (kuroko())
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	printf("%.9f %.9f\n", pa.x, pa.y);
	printf("%.9f %.9f\n", pb.x, pb.y);
	printf("%.9f %.9f\n", pcc.x, pcc.y);
	return 0;
}
