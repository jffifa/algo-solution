//ural1332
//geometry
//arc sweep
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

inline char dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp
{
	double x, y;
	sp() {}
	sp(double xx, double yy): x(xx), y(yy) {}
	void read() {scanf("%lf%lf", &x, &y);}
};

sp operator- (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y);}

double nrmsqr(const sp &v)
{return v.x*v.x+v.y*v.y;}

double dis(const sp &p1, const sp &p2)
{return sqrt(nrmsqr(p2-p1));}

double pa(const sp &p, const sp &p0)
{return atan2(p.y-p0.y, p.x-p0.x);}

struct sarc
{
	double a;
	char cnt;
	sarc() {}
	sarc(double aa, int cc): a(aa), cnt(cc) {}
};
bool operator< (const sarc &a1, const sarc &a2)
{
	if (dcmp(a1.a-a2.a)==0) return a1.cnt>a2.cnt;
	return a1.a<a2.a;
}

int N;
double r, rc;
sp p[101];

int rcc(int N, sp p[], double r)
{
	if (dcmp(r)<0) return 0;
	if (dcmp(r)==0) return N?1:0;
	sarc arc[1000];
	int arccnt, swpcnt, res = 1;
	double d, a, da, as, ae;
	for (int i = 0; i < N; ++i)
	{
		swpcnt = arccnt = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i==j) continue;
			d = dis(p[i], p[j]);
			if (dcmp(d-r-r)>0) continue;
			a = pa(p[j], p[i]);
			da = acos(d/(2*r));
			if (dcmp(da)==0)
			{
				arc[arccnt++] = sarc(a, 1);
				arc[arccnt++] = sarc(a, -1);
				continue;
			}
			as = a-da;
			ae = a+da;
			if (dcmp(as+PI)<0) as += 2*PI;
			if (dcmp(ae-PI)>0) ae += 2*PI;
			if (dcmp(as-ae)>0)
			{
				arc[arccnt++] = sarc(as, 1);
				arc[arccnt++] = sarc(PI, -1);
				arc[arccnt++] = sarc(-PI, 1);
				arc[arccnt++] = sarc(ae, -1);
			}
			else
			{
				arc[arccnt++] = sarc(as, 1);
				arc[arccnt++] = sarc(ae, -1);
			}
		}
		sort(arc, arc+arccnt);
		for (int j = 0; j < arccnt; ++j)
		{
			swpcnt += arc[j].cnt;
			res = max(res, swpcnt+1);
		}
	}
	return res;
}

int solve()
{return rcc(N, p, r-rc);}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		p[i].read();
	scanf("%lf%lf", &r, &rc);
	printf("%d\n", solve());
	return 0;
}

