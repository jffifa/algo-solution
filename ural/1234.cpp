/*
	Problem: Ural1234
	Algorithm: Geometry, Enum
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

inline char dblcmp(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 :-1;
}

bool flag;
int N, M;
double s[5];
double d, e;

bool judge(double a, double b)
{
	if (a < b) swap(a, b);
	double dgin = sqrt(a*a+b*b);
	double dgout = sqrt(d*d+e*e);
	if (dblcmp(dgin-e) <= 0) return 1;
	if (dblcmp(dgin-dgout) > 0) return 0;
	//puts("orz");
	double alpha, beta, gamma, theta;
	if (dblcmp(dgin-d) > 0)
	{
		alpha = acos(e/dgin);
		beta = acos(d/dgin);
		gamma = PI/2-alpha-beta;
		theta = PI-2*atan(a/b);
		//printf("%f %f %f %f\n", alpha, beta, gamma, theta);
		if (dblcmp(theta-gamma)<=0 || (dblcmp(theta-gamma-2*beta)>=0&&dblcmp(theta-2*gamma-2*beta)<=0)) return 1;
		theta = PI-theta;
		if (dblcmp(theta-gamma)<=0 || (dblcmp(theta-gamma-2*beta)>=0&&dblcmp(theta-2*gamma-2*beta)<=0)) return 1;
		theta = PI-theta;
		if ((dblcmp(theta-2*beta)>=0&&dblcmp(theta-2*beta-gamma)<=0) || dblcmp(theta-2*beta-2*alpha-gamma)>=0) return 1;
		theta = PI-theta;
		if ((dblcmp(theta-2*beta)>=0&&dblcmp(theta-2*beta-gamma)<=0) || dblcmp(theta-2*beta-2*alpha-gamma)>=0) return 1;
		return 0;
	}
	else
	{
		alpha = acos(e/dgin);
		gamma = PI-2*alpha;
		theta = PI-2*atan(a/b);
		if (dblcmp(theta-gamma)<=0) return 1;
		theta = PI-theta;
		if (dblcmp(theta-gamma)<=0) return 1;
		return 0;
	}
}

int main()
{
	while (~scanf("%lf", &s[0]))
	{
		for (int i = 1; i < 3; ++i) scanf("%lf", s+i); s[3] = s[0];
		scanf("%lf%lf", &d, &e);
		//for (int i = 0; i < 3; ++i) printf("%f ", s[i]);
		//printf("%f %f\n", d, e);
		if (d < e) swap(d, e);
		flag = 1;
		for (int i = 0; i < 3; ++i)
			if (judge(s[i], s[i+1]))
			{
				puts("YES");
				flag = 0;
				break;
			}
		if (flag) puts("NO");
	}
	return 0;
}

