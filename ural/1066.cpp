/*
	Problem: Ural1066
	Algorithm: Geometry, Maths
	Time: O()
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 1001;
const double EPS = 1e-4;
const double INF = 1e9;

int N;
double H[MaxN+1], Low, High, Mid;

bool Check(double m)
{
	H[N] = m;
	double Mami = -1*(N-1)*(N-2)+H[1]*(N-2)+H[N];
	H[2] = Mami/(N-1);
	if (H[2] < 0) return 0;
	for (int i = 3; i <= N-1; ++i)
	{
		H[i] = 2*H[i-1]-H[i-2]+2;
		if (H[i] < 0) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%lf", &N, &H[1]);
	Low = 0; High = INF;
	while (High-Low > EPS)
	{
		//printf("%lf %lf\n", High, Low);
		Mid = (High+Low)/2;
		if (Check(Mid)) High = Mid;
		else Low = Mid;
	}
	printf("%.2lf\n", Mid);
	return 0;
}
