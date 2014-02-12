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

bool cmp(const sp &p1, const sp &p2)
{
	if (DBLCMP(p1.y-p2.y)==0) return DBLCMP(p1.x-p2.x)>0;
	return DBLCMP(p1.y-p2.y)>0;
}

int graham(int N, sp p[], sp ch[], bool in = 0)
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
	for (i = j = 2; i < N; ch[j++] = p[i++])
		while (j>1 && dir(ch[j-1], ch[j-2], p[i])>e) --j;
	ch[k=j++] = p[N-2];
	for (i = N-3; i > 0; ch[j++] = p[i--])
		while (j>k && dir(ch[j-1], ch[j-2], p[i])>e) --j;
	while (j>k && dir(ch[j-1], ch[j-2], ch[0])>e) --j;
	return j;
}

int N, M;
double L, x, y, ans;
sp p[1010];
sp ch[1010];

int main()
{
	scanf("%d%lf", &N, &L);
	for (int i = 0; i < N; ++i)
		p[i].read();
	M = graham(N, p, ch);
	for (int i = 0; i < M; ++i)
		ans += dis(ch[i], ch[(i+1)%M]);
	ans += 2*PI*L;
	printf("%.0f\n", ans);
	return 0;
}

