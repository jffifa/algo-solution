/*
	Problem: Ural1083
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;


int N, K, Ans;
char P[100];

int main()
{
	scanf("%d", &N);
	scanf("%s", P);
	K = strlen(P);
	Ans = 1;
	for (int i = N; i > 0; i -= K)
		Ans *= i;
	printf("%d\n", Ans);
	return 0;
}
