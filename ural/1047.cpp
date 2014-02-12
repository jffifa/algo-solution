/*
	Problem: Ural1047
	Algorithm: Maths, Matrix
	Time: O()
	Memory: O()
	Detail: Tridiagonal matrix
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 3001;

int N;
double a[MaxN+2], c[MaxN+2], s;

int main()
{
	scanf("%d", &N);
	scanf("%lf%lf", &a[0], &a[N+1]);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%lf", &c[i]);
		s += (N+1-i)*c[i];
	}
	a[1] = (N*a[0]+a[N+1]-2*s)/(N+1);
	printf("%.2lf\n", a[1]);
	return 0;
}
