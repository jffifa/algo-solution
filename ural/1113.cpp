//ural1113
//tricky
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double d, a;

int main()
{
	scanf("%lf%lf", &d, &a);
	double ans = 0;
	int i = 1;
	while (d-a/(2*i-1)>0)
	{
		ans += a;
		d -= a/(2*i-1);
		i++;
	}
	ans += d*(2*i-1);
	printf("%.0f\n", ceil(ans));
	return 0;
}
