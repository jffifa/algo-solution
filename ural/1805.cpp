#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
int ans[11][11];
ll K;

void rot(int &r, int &c) {
	swap(r, c);
	c = N-1-c;
}

ll cnt(int r, int c) {
	ans[r][c] = 0;
	ll res = 1;
	bool vis[11][11] = {0};
	int i, j, k;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			if (vis[i][j]) continue;
			int t = 0;
			bool fill = 0;
			for (k = 0; k < 4; ++k) {
				vis[i][j] = 1;
				fill |= ans[i][j]==1;
				t += ans[i][j]==-1;
				rot(i, j);
			}
			res *= fill?1:t;
		}
	ans[r][c] = -1;
	return res;
}

void find(int &i, int &j) {
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			if (ans[i][j]==-1) return;
}

int main() {
	int i, j, k;
	cin>>N>>K;
	memset(ans, -1, sizeof ans);
	int now = N*N/4;
	while (now) {
		find(i, j);
		ll t = cnt(i, j);
		if (K > t) {
			now--;
			ans[i][j] = 1;
			for (rot(i, j), k=0; k < 3; ++k) {
				ans[i][j] = 0;
				rot(i, j);
			}
			K -= t;
		}
		else
			ans[i][j] = 0;
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j)
			printf("%d", ans[i][j]);
		puts("");
	}
	return 0;
}

