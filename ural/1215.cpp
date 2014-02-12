/*
	Problem: Ural1215
	Algorithm: Geometry
	Time: O()
	Memory: O()
	Detail: simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-8;
const double INF = 1e9;

inline char DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

inline double min(double a, double b)
{return a<b ? a : b;}

struct sp
{
	double x, y;
	sp () {}
	sp (double xx, double yy): x(xx), y(yy) {}
	void read() {scanf("%lf%lf", &x, &y);}
};

sp operator - (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y);}

double norm(const sp &v)
{return sqrt(v.x*v.x+v.y*v.y);}

double dis(const sp &p1, const sp &p2)
{return norm(p2-p1);}

double det(const sp &v1, const sp &v2)
{return v1.x*v2.y-v2.x*v1.y;}

double dir(const sp &p0, const sp &p1, const sp &p2)
{return det(p1-p0, p2-p0);}

struct ss
{
	sp p1, p2;
	ss() {}
	ss(sp p, sp q): p1(p), p2(q) {}
};

double distoline(const sp &p, const ss &s)
{return fabs(det(p-s.p1, s.p2-s.p1))/norm(s.p2-s.p1);}

double distoseg(const sp &p, const ss &s)
{
	sp t = p;
	t.x += s.p1.y-s.p2.y;
	t.y += s.p2.x-s.p1.x;
	if (DBLCMP(dir(p, s.p1, t)*dir(p, s.p2, t)) > 0)
		return dis(p, s.p1)<dis(p, s.p2) ? dis(p, s.p1) : dis(p, s.p2);
	else
		return distoline(p, s);
}

int N;
sp hmr, p[101];
double ans;

bool inside(sp hmr, sp p[])
{
	//p[N] = p[0];
	for (int i = 0; i < N; ++i)
		if (DBLCMP(dir(p[i], p[i+1], hmr)) <= 0) return 0;
	return 1;
}

int main()
{
	hmr.read();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		p[i].read();
	p[N] = p[0];
	if (inside(hmr, p))
	{
		puts("0.000");
		return 0;
	}
	ans = INF;
	for (int i = 0; i < N; ++i)
		ans = min(ans, distoseg(hmr, ss(p[i], p[i+1])));
	printf("%.3f\n", 2*ans);
	return 0;
}
