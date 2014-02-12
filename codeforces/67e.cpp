/*
	Problem: E
	Algorithm: Geometry
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

const int MaxN = 1002;
const double EPS = 1e-8;
const double INF = 1e8;

inline int DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct SPoint
{
	double x, y;
	SPoint() {}
	SPoint(double X, double Y): x(X), y(Y) {}
};

int N;
SPoint P[MaxN+1];
double L, R;

int Solve()
{
	L = -1;
	R = INF;
	double dx, dy, px, a, b;
	for (int i = 1; i < N; ++i)
	{
		dx = P[i+1].x-P[i].x;
		dy = P[i+1].y-P[i].y;
		if (DBLCMP(dy)==0)
		{
			if (DBLCMP((P[1].x-P[0].x)*(P[i+1].x-P[i].x))>0) return 0;
			else continue;
		}
		px = P[i].x+(P[0].y-P[i].y)/dy*dx;
		if (dy > 0)
			L = max(L, px);
		else
			R = min(R, px);
	}
	L = ceil(L-EPS);
	R = floor(R+EPS);
	if (R < L) return 0;
	return (int)(R-L+1);
}

int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%lf%lf", &P[i].x, &P[i].y);
	P[N] = P[0];
	printf("%d\n", Solve());
	return 0;
}
