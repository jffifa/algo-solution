#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

inline char dblcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

double ad, ac, bd, bc, dis;

int main()
{
	scanf("%lf%lf%lf%lf", &ad, &ac, &bd, &bc);
	ad *= 1000; ac *= 1000; bd *= 1000; bc *= 1000;
	if (dblcmp(ac*ad-bc*bd)==0)
	{
		puts("Impossible.");
		return 0;
	}
	dis = ((bc*bc+bd*bd)*ac*ad-(ac*ac+ad*ad)*bc*bd)/(ac*ad-bc*bd);
	dis = sqrt(dis);
	printf("Distance is %.0f km.\n", dis);
	return 0;
}
