#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct sp {
	int x, y;
	void read() {scanf("%d%d", &x, &y);}
}p[333], q[333];

int dir(const sp &p, const sp &u, const sp &v) {
	int x1=u.x-p.x, x2=v.x-p.x, y1=u.y-p.y, y2=v.y-p.y;
	return x1*y2-x2*y1;
}

bool cmp(const sp &u, const sp &v) {
	if (u.y==v.y) return u.x>v.x;
	return u.y>v.y;
}

int graham(int N, sp p[], sp ch[]) {
	int i, j, k;
	sort(p, p+N, cmp);
	ch[0] = p[0];
	ch[1] = p[1];
	for (i = j = 2; i < N; ch[j++]=p[i++])
		while (j>1 && dir(ch[j-1], ch[j-2], p[i])>=0) --j;
	ch[k=j++] = p[N-2];
	for (i = N-3; i > 0; ch[j++]=p[i--])
		while (j>k && dir(ch[j-1], ch[j-2], p[i])>=0) --j;
	while (j>k && dir(ch[j-1], ch[j-2], ch[0])>=0) --j;
	return j;
}

int N, M;
int f[333][333];
int cost[333][333];

int dfs(int i, int j) {
	if (~f[i][j]) return f[i][j];
	if (j < i+3) return f[i][j] = 0;
	int res = 0x3fffffff;
	for (int k = i+1; k < j; ++k) {
		int c = cost[i][k]+cost[k][j]+dfs(i, k)+dfs(k, j);
		if (k==i+1) c -= cost[i][k];
		if (k==j-1) c -= cost[k][j];
		res = min(res, c);
	}
	return f[i][j] = res;
}

int main() {
	int i, j, k;
	while (cin>>N>>M) {
		for (i = 0; i < N; ++i)
			q[i].read();
		j = graham(N, q, p);
		if (j^N) {
			puts("I can't cut.");
			continue;
		}
		for (i = 0; i < N; ++i)
			for (j = 0; j < N; ++j)
				cost[i][j] = abs(p[i].x+p[j].x)*abs(p[i].y+p[j].y)%M;
		memset(f, -1, sizeof f);
		printf("%d\n", dfs(0, N-1));
	}
	return 0;
}
