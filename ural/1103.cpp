/*
	Problem: Ural1103
	Algorithm: Geometry
	Time: O()
	Memory: O()
	Detail: Tricky, angle of circumference
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const double INF = 1e9;
const double EPS = 1e-8;
const double PI = acos(-1.0);

inline char DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct sp
{
	double x, y;
	double ang;
	sp () {}
	sp (double xx, double yy): x(xx), y(yy) {}
	void read() {scanf("%lf%lf", &x, &y);}
	void write() {printf("%.0f %.0f\n", x, y);}
};

bool operator == (const sp &p1, const sp &p2)
{return (DBLCMP(p1.x-p2.x)==0 && DBLCMP(p1.y-p2.y)==0);}

sp operator - (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y);}

double dot(const sp &v1, const sp &v2)
{return v1.x*v2.x+v1.y*v2.y;}

double det(const sp &v1, const sp &v2)
{return v1.x*v2.y-v2.x*v1.y;}

double dir(const sp &p0, const sp &p1, const sp &p2)
{return det(p1-p0, p2-p0);}

double norm(const sp &v)
{return sqrt(v.x*v.x+v.y*v.y);}

double dis(const sp &p1, const sp &p2)
{return norm(p2-p1);}

bool cmp(const sp &p1, const sp &p2)
{
	if (DBLCMP(p1.y-p2.y)==0) return DBLCMP(p1.x-p2.x)>0;
	return DBLCMP(p1.y-p2.y)>0;
}

int grahamscan(int N, sp p[], sp ch[], bool in = 0)
{
	const double e = in ? EPS : -EPS;
	int i, j, k;
	if (N < 3)
	{
		for (int i = 0; i < N; ++i)
			ch[i] = p[i];
		return N;
	}

	sort(p, p+N, cmp);
	ch[0] = p[0];
	ch[1] = p[1];
	for (i = j = 2; i < N; ch[j++]=p[i++])
		while (j>1 && dir(ch[j-1], ch[j-2], p[i])>e) --j;
	ch[k=j++] = p[N-2];
	for (i = N-3; i > 0; ch[j++]=p[i--])
		while (j>k && dir(ch[j-1], ch[j-2], p[i])>e) --j;
	while (j>k && dir(ch[j-1], ch[j-2], ch[0])>e) --j;
	return j;
}

bool cmpang(const sp &p1, const sp &p2)
{return p1.ang < p2.ang;}

int N, M;
sp p[10005], ch[10005];
sp hmr, mdk;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) p[i].read();
	M = grahamscan(N, p, ch);
	hmr = ch[0]; mdk = ch[1];
	for (int i = 0; i < N; ++i)
	{
		if (p[i]==hmr || p[i]==mdk)
		{
			p[i].ang = -999;
			continue;
		}
		p[i].ang = acos(dot(hmr-p[i], mdk-p[i])/(dis(p[i], hmr)*dis(p[i], mdk)));
	}
	sort(p, p+N, cmpang);
	hmr.write();
	mdk.write();
	p[2+(N-3)/2].write();
	return 0;
}
