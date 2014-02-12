/*
	Problem: Ural1068
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 100;

int N, M;

int main()
{
	scanf("%d", &N);
	M = abs(N-1)+1;
	printf("%d\n", (1+N)*M/2);
	return 0;
}
