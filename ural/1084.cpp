/*
	Problem: Ural1084
	Algorithm: Geometry
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-6;

double s, r, th, b;

int main()
{
	scanf("%lf%lf", &s, &r);
	s = s/2;
	if (r < s+EPS)
	{
		printf("%.3f\n", PI*r*r);
		return 0;
	}
	if (r > s*sqrt(2.0)-EPS)
	{
		printf("%.3f\n", s*s*4);
		return 0;
	}
	th = 2*acos(s/r);
	b = sqrt(r*r-s*s);
	printf("%.3f\n", r*r*(2*PI-4*th)/2+b*s*4);
	return 0;
}
