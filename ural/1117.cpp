/*
	Problem: Ural1171
	Algorithm: DP, Count
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxH = 40;

int F[MaxH], N[MaxH];;
int L, R;
int a, b;

int Calc(int h, int x)
{
	if (h == 0) return 0;
	if (x == N[h]) return F[h-1]+h-1;
	if (x < N[h]) return Calc(h-1, x);
	if (x > N[h]) return F[h-1]+(h-1)*2+Calc(h-1, x-N[h]);
}

int main()
{
	F[0] = 0;
	N[0] = 0;
	for (int i = 1; i <= 30; ++i)
	{
		F[i] = 2*F[i-1]+2*(i-1);
		N[i] = 1<<i;
	}
	scanf("%d%d", &L, &R);
	if (L > R) swap(L, R);
	printf("%d\n", Calc(30, R)-Calc(30, L));
	return 0;
}

