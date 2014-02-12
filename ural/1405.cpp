//Ural1405
//geometry
//simple
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1e9;
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

int N;
double md[1001], ans;
sp p[1001];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		p[i].read();
	for (int i = 0; i < N; ++i)
	{
		md[i] = 50;
		for (int j = 0; j < N; ++j)
		{
			if (i==j) continue;
			md[i] = min(md[i], dis(p[i], p[j]));
		}
	}
	ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
		{
			if (dcmp(md[i]-1)<0 || dcmp(md[j]-1)<0) continue;
			double d = dis(p[i], p[j]);
			if (dcmp(d-2)<0) continue;
			if (dcmp(d-md[i]-md[j])>=0)
				ans = max(ans, PI*(md[i]*md[i]+md[j]*md[j]));
			else
			{
				double m, n;
				m = min(md[i], d-1); n = d-m;
				ans = max(ans, PI*(m*m+n*n));
				m = min(md[j], d-1); n = d-m;
				ans = max(ans, PI*(m*m+n*n));
			}
		}
	printf("%.4f\n", ans);
	return 0;
}
