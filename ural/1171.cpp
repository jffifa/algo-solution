#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned short U;

char dir[]="NESW";
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, sr, sc;
U w[16][4][4];
char s[16][4][4];
U f[16][4][4][257];
char len[16][4][4][257];
int path[16][4][4][257];

U food; int p, fl;
U fnow[4][4][17]; int pnow[4][4][17];
char t, vis[4][4];

inline bool check(int r, int c)
{
	return r>=0 && r<4 && c>=0 && c<4 && !vis[r][c];
}

void dfs(char r, char c, char d)
{
	food += w[fl][r][c];
	p = p<<2|d;
	vis[r][c] = 1;
	t++;
	if (food > fnow[r][c][t])
	{
		fnow[r][c][t] = food;
		pnow[r][c][t] = p;
	}
	for (int i = 0; i < 4; ++i)
		if (check(r+dr[i], c+dc[i])) dfs(r+dr[i], c+dc[i], i);
	food -= w[fl][r][c];
	p >>= 2;
	vis[r][c] = 0;
	t--;
}

void dp(int sr, int sc)
{
	int t, d, x, a, r, c;
	for (t = fl; t <= fl<<4; ++t)
	{
		x = fl?f[fl-1][sr][sc][t]:0;
		if (fl && !x) continue;
		for (r = 0; r < 4; ++r)
			for (c = 0; c < 4; ++c)
				for (d = 1; d <= 16; ++d)
				{
					a = t+d;
					if (fnow[r][c][d] && x+fnow[r][c][d]>f[fl][r][c][a])
					{
						f[fl][r][c][a] = x+fnow[r][c][d];
						len[fl][r][c][a] = d-1;
						path[fl][r][c][a] = pnow[r][c][d];
					}
				}
	}
}

void output()
{
	double ans=0;
	int r, c, t, i, j, k, l;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			for (k = N; k <= N<<4; ++k)
				if ((double)f[N-1][i][j][k]/k > ans)
				{
					ans = (double)f[N-1][i][j][k]/k;
					r = i; c = j; t = k;
				}
	printf("%.4f\n%d\n", ans, t-1);
	char ps[257]={0};
	for (i = N-1; i >= 0; --i)
	{
		l = len[i][r][c][t];
		k = path[i][r][c][t];
		for (j = 0; j < l; ++j)
		{
			ps[--t] = dir[k&3];
			r -= dr[k&3]; c -= dc[k&3];
			k >>= 2;
		}
		ps[--t] = 'D';
	}
	puts(ps+1);
}

int main()
{
	int i, j, r, c;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		for (r = 0; r < 4; ++r)
			for (c = 0; c < 4; ++c)
				scanf("%hu", &w[i][r][c]);
		for (r = 0; r < 4; ++r)
			for (c = 0; c < 4; ++c)
			{
				scanf("%d", &j);
				if (i < N-1) s[i+1][r][c] = j;
			}
	}
	scanf("%d%d", &sr, &sc);
	s[0][sr-1][sc-1] = 1;
	for (fl = 0; fl < N; ++fl)
		for (r = 0; r < 4; ++r)
			for (c = 0; c < 4; ++c)
				if (s[fl][r][c])
				{
					p = food = t = 0;
					memset(fnow, 0, sizeof(fnow));
					dfs(r, c, 0);
					dp(r, c);
				}
	output();
	return 0;
}
