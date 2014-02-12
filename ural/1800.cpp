#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double g = 9.81;
double l, h, w, t, phi;

int main()
{
	scanf("%lf%lf%lf", &l, &h, &w);
	l /= 100; h /= 100; w /= 60;
	if (l/2 > h)
	{
		puts("butter");
		return 0;
	}
	t = sqrt(2*(h-l/2)/g);
	phi = w*t-floor(w*t);
	if ((phi>=0&&phi<=1.0/4)||(phi>=3.0/4&&phi<=1)) puts("butter");
	else puts("bread");
	return 0;
}	
