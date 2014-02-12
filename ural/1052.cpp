/*
	Problem: Ural1052
	Algorithm: Enumeration
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

const int MaxN = 201;

struct SPoint
{
	int x, y;
	SPoint () {}
	SPoint (int X, int Y): x(X), y(Y) {}
};
SPoint operator - (const SPoint &V1, const SPoint &V2)
{return SPoint(V1.x-V2.x, V1.y-V2.y);}

int Det(const SPoint &V1, const SPoint &V2)
{return V1.x*V2.y-V2.x*V1.y;}

bool OnLine(const SPoint &P, const SPoint &P1, const SPoint &P2)
{return Det(P-P1, P-P2)==0;}

SPoint P[MaxN];
int N, Ans, Tmp;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &P[i].x, &P[i].y);
	Ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
		{
			Tmp = 0;
			for (int k = 0; k < N; ++k)
				if (OnLine(P[k], P[i], P[j])) Tmp++;
			//printf("%d\n", Tmp);
			Ans = max(Ans, Tmp);
		}
	printf("%d\n", Ans);
	return 0;
}
