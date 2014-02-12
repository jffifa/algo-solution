#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

int N, M, K;
int a[2], ans[2];
char map[55][55];
bool vis[55][55];

void dfs(int r, int c, int p) {
	vis[r][c] = 1;
	map[r][c] = '#'+p;
	for (int i = 0; i < 4; ++i) {
		int nr = r+dr[i], nc = c+dc[i];
		if (nr<0||nr>=N||nc<0||nc>=M) continue;
		if (map[nr][nc]==a[p] && !vis[nr][nc]) dfs(nr, nc, p);
	}
}

int main() {
	int i, j, k;
	cin>>N>>M;
	for (i = 0; i < N; ++i)
		cin>>map[i];
	a[0] = map[N-1][0];
	a[1] = map[0][M-1];
	memset(vis, 0, sizeof vis);
	dfs(N-1, 0, 0);
	dfs(0, M-1, 1);
	/*
	for (i = 0; i < N; ++i)
		puts(map[i]);
	*/
	cin>>K;
	for (i = 0; i < K; ++i) {
		int p = i&1;
		cin>>a[p];
		a[p] += '0';
		memset(vis, 0, sizeof vis);
		for (j = 0; j < N; ++j)
			for (k = 0; k < M; ++k)
				if (!vis[j][k] && map[j][k]=='#'+p) dfs(j, k, p);
	}
	for (j = 0; j < N; ++j)
		for (k = 0; k < M; ++k)
			if (map[j][k]=='#') ++ans[0];
			else if (map[j][k]=='#'+1) ++ans[1];
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}
