#include <cstdio>
#include <cstring>

int N;
int m[101][101];

void hmr(int r, int c)
{
	printf("%d ", m[r][c]);
	if (r==N && c==N) return;
	if (c==N) {hmr(N, r+1); return;} 
	if (r==1) {hmr(c+1, 1); return;}
	hmr(r-1, c+1);
}

int main()
{
	scanf("%d", &N);
	for (int r = 1; r <= N; ++r)
		for (int c = 1; c <= N; ++c)
			scanf("%d", &m[r][c]);
	hmr(1, 1);
	puts("");
	return 0;
}
