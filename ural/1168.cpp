#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const double INF = 1e9;

inline char DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct sp
{
	double x, y, z;
	double r;
	sp() {}
	sp(double xx, double yy, double zz): x(xx), y(yy), z(zz) {}
};

sp operator - (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);}

double norm(const sp &v)
{return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);}

double dis(const sp &p1, const sp &p2)
{return norm(p2-p1);}

int R, C, K, r, c, ans;
char rs[55][55];
double h[55][55], rad;
sp p[1001], rcv;

int hmr(int r, int c)
{
	rcv.x = r+.5; rcv.y = c+.5;
	double d, hmin = h[r][c], hmax = INF, mdk, syk;
	double rad;
	for (int i = 0; i < K; ++i)
	{
		rcv.z = p[i].z;
		rad = p[i].r;
		d = dis(p[i], rcv);
		if (DBLCMP(d-rad) > 0) return 0;
		mdk = rcv.z+sqrt(rad*rad-d*d+EPS);
		syk = rcv.z-sqrt(rad*rad-d*d+EPS);
		if (DBLCMP(mdk-hmin)<0 || DBLCMP(syk-hmax)>0) return 0;
		hmin = max(hmin, syk);
		hmax = min(hmax, mdk);
	}
	int res = (int)floor(hmax+EPS)-(int)ceil(hmin-EPS)+1;
	return res;
}

int main()
{
	scanf("%d%d%d", &R, &C, &K);
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			scanf("%lf", &h[r][c]);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d%d%lf", &r, &c, &rad);
		--r; --c;
		rs[r][c] = 1;
		p[i].x = r+.5; p[i].y = c+.5; p[i].z = h[r][c]; p[i].r = rad;
	}
	for (int r = 0; r < R; ++r)
		for (int c = 0; c < C; ++c)
		{
			if (rs[r][c]) continue;
			//printf("##%d %d\n", r, c);
			ans += hmr(r, c);
		}
	printf("%d\n", ans);
	return 0;
}
