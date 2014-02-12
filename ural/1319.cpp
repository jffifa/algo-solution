/*
	Problem: Ural1319
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100;

int m[101][101], cnt;
int N;

void solve(int r, int c)
{
	m[r][c] = ++cnt;
	if (cnt == N*N) return;
	if (r == N) {solve(N+2-c, 1); return;}
	if (c == N) {solve(1, N-r); return;}
	solve(r+1, c+1);
}

int main()
{
	scanf("%d", &N);
	solve(1, N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j < N; ++j)
			printf("%d ", m[i][j]);
		printf("%d", m[i][N]);
		puts("");
	}
	return 0;
}
