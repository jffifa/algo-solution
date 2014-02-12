/*
	Problem: Ural1087
	Algorithm: Game
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 10001;
const int MaxM = 50;

int N, M;
int St[MaxM+1];
char F[MaxN+1], Ans;

char MemSch(int x)
{
	if (F[x] >= 0) return F[x];
	F[x] = 0;
	for (int i = 0; i < M; ++i)
		if (x-St[i]>=0) F[x] |= !(MemSch(x-St[i]));
	//printf("%d %d\n", x, F[x]);
	return F[x];
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
		scanf("%d", &St[i]);
	memset(F, 255, sizeof(F));
	F[0] = 1;
	Ans = MemSch(N);
	/*
	for (int i = 0; i <= N; ++i)
		printf("%d ", F[i]);
	printf("\n");
	*/
	if (Ans) printf("1\n");
	else printf("2\n");
	return 0;
}
