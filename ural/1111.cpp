#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1e10;
const double EPS = 1e-8;
const double PI = acos(-1.0);

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

sp operator + (const sp &v1, const sp &v2)
{return sp(v1.x+v2.x, v1.y+v2.y);}

sp rotate(const sp &v, double a = 0)
{return sp(v.x*cos(a)-v.y*sin(a), v.x*sin(a)+v.y*cos(a));}

bool operator == (const sp &v1, const sp &v2)
{return DBLCMP(v1.x-v2.x)==0&&DBLCMP(v1.y-v2.y==0);}

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

struct ssqr
{
	sp p[4];
	int id;
	double dis;
};

bool operator < (const ssqr &s1, const ssqr &s2)
{
	if (DBLCMP(s1.dis-s2.dis)==0) return s1.id < s2.id;
	return s1.dis < s2.dis;
}

bool inside(const sp &p, const ssqr &sqr)
{
	for (int i = 0; i < 4; ++i)
		if (DBLCMP(dir(sqr.p[i], sqr.p[(i+1)%4], p))<=0) return 0;
	return 1;
}

double distoline(const sp &p, const ss &s)
{return fabs(det(p-s.p1, s.p2-s.p1))/norm(s.p2-s.p1);}

double distoseq(const sp &p, const ss &s)
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
sp p;
ssqr sqr[55];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		sqr[i].p[0].read();
		sqr[i].p[2].read();
		sqr[i].id = i+1;
	}
	p.read();
	for (int i = 0; i < N; ++i)
	{
		if (sqr[i].p[0]==sqr[i].p[2])
		{
			sqr[i].dis = dis(sqr[i].p[0], p);
			continue;
		}
		sp mid = sp((sqr[i].p[0].x+sqr[i].p[2].x)/2, (sqr[i].p[0].y+sqr[i].p[2].y)/2);
		sp v = sqr[i].p[2]-mid;
		sqr[i].p[1] = mid+rotate(v, -PI/2);
		sqr[i].p[3] = mid+rotate(v, PI/2);
		if (inside(p, sqr[i])) sqr[i].dis = 0;
		else
		{
			double mind = INF;
			for (int j = 0; j < 4; ++j)
				mind = min(mind, distoseq(p, ss(sqr[i].p[j], sqr[i].p[(j+1)%4])));
			sqr[i].dis = mind;
		}
	}
	//for (int i = 0; i < N; ++i)
		//printf("##%d: %.9f\n", i, sqr[i].dis);
	sort(sqr, sqr+N);
	for (int i = 0; i < N; ++i)
		printf("%d ", sqr[i].id);
	puts("");
}
