#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, cnt;
int s[50];
char g[50][50];

void modify(int r1, int c1, int r2, int c2)//upleft(r1,c1),downright(r2,c2)
{
	int i;
	for (i = 0; i < 2*N+1; ++i) s[i] = i;
	swap(s[r1], s[c1]);
	if (r1!=c2||r2!=c1) swap(s[r2], s[c2]);
	for (i = 0; i < 2*N+1; ++i)
	{
		if (i) putchar(' ');
		printf("%d", s[i]+1);
		g[i][s[i]] ^= 1;
	}
	puts("");
	for (i = 0; i < 2*N+1; ++i) s[i] = i;
	swap(s[r1], s[c2]);
	if (r1!=c1||r2!=c2) swap(s[r2], s[c1]);
	for (i = 0; i < 2*N+1; ++i)
	{
		if (i) putchar(' ');
		printf("%d", s[i]+1);
		g[i][s[i]] ^= 1;
	}
	puts("");
}

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < 2*N+1; ++i)
		scanf("%s", g[i]);
	for (i = 0; i < 2*N+1; ++i)
		for (j = 0; j < 2*N+1; ++j)
			g[i][j] = g[i][j]=='+'?++cnt,1:0;
	puts("There is solution:");
	if (cnt&1)
	{
		for (i = 0; i < 2*N+1; ++i)
		{
			if (i) putchar(' ');
			printf("%d", i+1);
			g[i][i] ^= 1;
		}
		puts("");
	}
	for (i = 0; i < 2*N; ++i)
		for (j = 0; j < 2*N; ++j)
			if (g[i][j]) modify(i, j, 2*N, 2*N);
	i = j = 0;
	while ((i<2*N)&&(j<2*N))
	{
		if (!g[i][2*N]&&!g[2*N][j]) {++i; ++j; continue;}
		if (!g[i][2*N]) {++i; continue;}
		if (!g[2*N][j]) {++j; continue;}
		modify(i, j, 2*N, 2*N);
	}
	return 0;
}
