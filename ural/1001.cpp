/*
	Problem: Ural1001
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxT = 1000000;

int T;
long long Data[MaxT+1];

int main()
{
	//freopen("1001.in", "r", stdin);
	//freopen("1001.out", "w", stdout);
	while (~scanf("%I64d", &Data[++T]));
	while (--T) printf("%.4lf\n", sqrt((double)Data[T]));
	return 0;
}
