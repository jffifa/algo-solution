#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int m;
int f[333333];
vector<int> g[111111];

int find(int u) {
	return f[u]==u ? u : f[u]=find(f[u]);
}

bool join(int u, int v) {
	int ru = find(u), rv = find(v);
	if (ru==rv) return 0;
	f[rv] = ru;
	return 1;
}

int main() {
	int i, j, k;
	cin>>m;
	for (i = 0; i < m; ++i) {
		int now = (m-(ll)i*i%m)%m;
		g[i].push_back(now);
		g[now].push_back(i);
	}
	for (i = 0; i < m; ++i) {
		sort(g[i].begin(), g[i].end());
		g[i].resize(unique(g[i].begin(), g[i].end())-g[i].begin());
	}
	for (i = 1; i <= 3*m; ++i) {
		int r = i%m;
		f[i] = i;
		for (j = 0; j < g[r].size(); ++j)
			for (k = g[r][j]?g[r][j]:m; k < i; k += m)
				if (!join(k, i)) {
					printf("%d\n", i);
					return 0;
				}
	}
	puts("-1");
	return 0;
}
