#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);

double v, a, k, vx, vy, t, d, ans;

int main()
{
	scanf("%lf%lf%lf", &v, &a, &k);
	a = a/180*PI;
	vx = v*cos(a);
	vy = v*sin(a);
	t = 2*vy/10;
	d = t*vx;
	//printf("%f\n", a);
	ans = d/(1-1/k);
	printf("%.2f\n", ans);
	return 0;
}
