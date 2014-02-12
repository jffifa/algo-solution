/*
	Problem: Ural1285
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

inline char dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp
{
	double c[8];
	void read() {for (int i = 0; i < 8; ++i) scanf("%lf", &c[i]);}
};

sp operator- (const sp &v1, const sp &v2)
{
	sp res;
	for (int i = 0; i < 8; ++i)
		res.c[i] = v1.c[i]-v2.c[i];
	return res;
}

sp operator+ (const sp &v1, const sp &v2)
{
	sp res;
	for (int i = 0; i < 8; ++i)
		res.c[i] = v1.c[i]+v2.c[i];
	return res;
}

sp operator* (double d, const sp &v)
{
	sp res;
	for (int i = 0; i < 8; ++i)
		res.c[i] = d*v.c[i];
	return res;
}

double dot(const sp &v1, const sp &v2)
{
	double res = 0;
	for (int i = 0; i < 8; ++i)
		res += v1.c[i]*v2.c[i];
	return res;
}

double dis(const sp &p1, const sp &p2)
{
	double res = 0, d;
	for (int i = 0; i < 8; ++i)
	{
		d = p1.c[i]-p2.c[i];
		res += d*d;
	}
	return sqrt(res);
}

sp a, b, o, v, p;
double r, t, d, hmr, mdk, syk, av, bv, vv;
double theta;

double solve()
{
	v = b-a;
	t = (dot(o, v)-dot(a, v))/dot(v, v);
	if (dcmp(t)>=0 && dcmp(t-1)<=0)
	{
		p = a+(t*v);
		d = dis(o, p);
		if (dcmp(d-r)>=0) return dis(a, b);
		hmr = dis(a, o);
		mdk = dis(b, o);
		syk = dis(a, b);
		av = sqrt(hmr*hmr-r*r);
		bv = sqrt(mdk*mdk-r*r);
		theta = acos((hmr*hmr+mdk*mdk-syk*syk)/(2*hmr*mdk))-acos(r/hmr)-acos(r/mdk);
		vv = r*theta;
		return av+bv+vv;
	}
	else
		return dis(a, b);
}

int main()
{
	a.read();
	b.read();
	o.read();
	scanf("%lf", &r);
	printf("%.2f\n", solve());
	return 0;
}
