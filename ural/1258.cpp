#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const double INF = 1e10;

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

struct ss
{
	sp p1, p2;
	ss() {}
	ss(sp p, sp q): p1(p), p2(q) {}
};

int N;
char str[1111];
double u, r, ans;
sp st, ed;

int main()
{
	scanf("%lf%lf", &r, &u);
	st.read(); st.y = u-st.y;
	ed.read(); ed.y = u-ed.y;
	scanf("%s", str);
	N = strlen(str);
	for (int i = 0; i < N; ++i)
	{
		if (str[i] == 'F') st.y = u*2-st.y;
		if (str[i] == 'B') st.y = -st.y;
		if (str[i] == 'R') st.x = r*2-st.x;
		if (str[i] == 'L') st.x = -st.x;
	}
	printf("%.4f\n", dis(st, ed));
	return 0;
}
