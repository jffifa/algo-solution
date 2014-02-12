#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const short INF = 0x7fff;

int T;
short f[901][8101];
char p[901][8101];
int s1, s2;

void init()
{
	int i, j, k;
	for (i = 0; i <= 900; ++i)
		for (j = 0; j <= 8100; ++j)
			f[i][j] = INF;
	f[0][0] = 0;
	for (i = 1; i <= 900; ++i)
		for (j = 1; j <= 8100; ++j)
		{
			f[i][j] = INF;
			for (k = 1; k <= 9; ++k)
			{
				if (k>i || k*k>j) continue;
				if (f[i][j] > f[i-k][j-k*k]+1)
				{
					f[i][j] = f[i-k][j-k*k]+1;
					p[i][j] = k;
				}
			}
		}
}

void solve(int s1, int s2)
{
	if (s1>900 || s2>8100 || f[s1][s2]>100) {puts("No solution"); return;}
	char s[111] = {0};
	int len = 0, x;
	while (s1)
	{
		x = p[s1][s2];
		s[len++] = x+'0';
		s1 -= x;
		s2 -= x*x;
	}
	/*
	printf("%d\n", len);
	for (int i = 0; i < len; ++i)
		putchar(s[i]);
	puts("");
	*/
	sort(s, s+len);
	puts(s);
}

int main()
{
	init();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &s1, &s2);
		//printf("%d %d\n", f[s1][s2], p[s1][s2]);
		solve(s1, s2);
	}
	return 0;
}
