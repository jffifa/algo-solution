//ural1122
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

char g[6][6];
char mdf[6][6];
int cnt=0, ans=9999;

void modify(int r, int c)
{
	int nr, nc;
	for (int i = 0; i < 9; ++i)
	{
		nr = r+dr[i];
		nc = c+dc[i];
		if (nr<0||nr>=4||nc<0||nc>=4) continue;
		g[nr][nc] ^= mdf[dr[i]+1][dc[i]+1];
	}
}

void dfs(int r, int c)
{
	if (r==4)
	{
		bool f = g[0][0];
		for (r = 0; r < 4; ++r)
			for (c = 0; c < 4; ++c)
				if (g[r][c]^f) return;
		ans = min(ans, cnt);
		return;
	}
	int nr = c==3?r+1:r;
	int nc = c==3?0:c+1;
	dfs(nr, nc);
	cnt++;
	modify(r, c);
	dfs(nr, nc);
	cnt--;
	modify(r, c);
}

int main()
{
	int r, c;
	for (r = 0; r < 4; ++r)
		scanf("%s", g[r]);
	for (r = 0; r < 4; ++r)
		for (c = 0; c < 4; ++c)
			if (g[r][c] == 'W') g[r][c] = 0;
			else g[r][c] = 1;
	for (r = 0; r < 3; ++r)
		scanf("%s", mdf[r]);
	for (r = 0; r < 3; ++r)
		for (c = 0; c < 3; ++c)
			if (mdf[r][c] == '1') mdf[r][c] = 1;
			else mdf[r][c] = 0;
	/*
	for (r = 0; r < 4; ++r)
	{
		for (c = 0; c < 4; ++c)
			printf("%d ", g[r][c]);
		puts("");
	}
	*/
	dfs(0, 0);
	if (ans == 9999) puts("Impossible");
	else printf("%d\n", ans);
	return 0;
}
