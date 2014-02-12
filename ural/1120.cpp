/*
	Problem: Ural1120
	Algorithm: Maths
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int N, Bd, A, P;

int main()
{
	scanf("%d", &N);
	N <<= 1;
	Bd = (int)sqrt((double)N);
	for (P = Bd; P >= 1; --P)
	{
		if ((N-P*(P-1))%(2*P) == 0)
		{
			A = (N-P*(P-1))/(2*P);
			if (A >= 1) break;
		}
	}
	printf("%d %d\n", A, P);
	return 0;
}
