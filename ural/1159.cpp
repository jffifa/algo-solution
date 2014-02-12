#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);

inline char DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

int N;
char type;
double hmr[101], sum, mdk, ans;

inline double angcalc(double r, double c)
{return asin(c/r/2)*2;}

double area(double a, double b, double c)
{
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool judge()
{
	if (type == 1)
		if (sum+mdk > 2*PI) return 1;
		else return 0;
	else
		if (sum < mdk) return 1;
		else return 0;
}

void solve()
{
	double low=hmr[N-1]/2, high=INF, mid;
	sum = 0;
	for (int i = 0; i < N-1; ++i)
		sum += angcalc(low, hmr[i]);
	if (sum < PI) type = 2;
	else type = 1;
	int bt = 100;
	while (bt--)
	{
		mid = (low+high)/2;
		sum = 0;
		for (int i = 0; i < N-1; ++i)
			sum += angcalc(mid, hmr[i]);
		mdk = angcalc(mid, hmr[N-1]);
		if (judge())
			low = mid;
		else
			high = mid;
	}
	sum = 0;
	for (int i = 0; i < N-1; ++i)
		sum += area(mid, mid, hmr[i]);
	mdk = area(mid, mid, hmr[N-1]);
	if (type == 1) ans = sum+mdk;
	else ans = sum-mdk;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%lf", hmr+i);
	sort(hmr, hmr+N);
	sum = 0;
	for (int i = 0; i < N-1; ++i)
		sum += hmr[i];
	if (DBLCMP(hmr[N-1]-sum) >= 0)
	{
		puts("0.00");
		return 0;
	}
	solve();
	printf("%.2f\n", ans);
	return 0;
}
