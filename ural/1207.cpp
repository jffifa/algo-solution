/*
	Problem: Ural1207
	Algorithm: Geometry
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 10000;
const double INF = 1e9;
const double EPS = 1e-6;
const double PI = acos((double)-1);

struct SPoint
{
	double x, y, angle;
	int id;
	SPoint() {}
	SPoint(double X, double Y): x(X), y(Y) {}
	friend SPoint operator - (const SPoint &P1, const SPoint &P2)
	{return SPoint(P1.x-P2.x, P1.y-P2.y);}
	friend bool operator < (const SPoint &P1, const SPoint &P2)
	{return P1.angle < P2.angle;}
};

double Angle(const SPoint &P, const SPoint &P0)
{return atan2(P.x-P0.x, P.y-P0.y);}

int N, MinID;
SPoint P[MaxN+1];

int main()
{
	scanf("%d", &N);
	MinID = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf%lf", &P[i].x, &P[i].y);
		P[i].id = i;
		if (P[i].y == P[MinID].y)
			{if (P[i].x < P[MinID].x) MinID = i;}
		else
			{if (P[i].y < P[MinID].y) MinID = i;}
	}
	swap(P[0], P[MinID]);
	for (int i = 1; i < N; ++i)
		P[i].angle = Angle(P[i], P[0]);
	sort(P+1, P+N);
	printf("%d %d\n", P[0].id+1, P[N>>1].id+1);
	return 0;
}
