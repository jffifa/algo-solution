/*
	Problem: Ural1044
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by Biribiri
*/

#include <cstdio>
using namespace std;

int Ans[10];
int N;

int main()
{
	Ans[2] = 10;
	Ans[4] = 670;
	Ans[6] = 55252;
	Ans[8] = 4816030;
	scanf("%d", &N);
	printf("%d\n", Ans[N]);
	return 0;
}
