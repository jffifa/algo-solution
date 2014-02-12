#include <cassert>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double EPS = 1e-6;
const double INF = 1e8;

double da, w;
int N;
bool vis[555][555][2];
double f[555][555][2];
int path[555][555][2];

struct snode {
	int id;
	double a, t;
	void read(int i) {
		id = i;
		double d, v;
		cin>>a>>d>>v;
		a -= da;
		if (a<-EPS) a += 360;
		t = (d-1)/v*60;
	}
	bool operator<(const snode &rhs) const {
		return a<rhs.a;
	}
}node[555];

inline double cost(int i, int j) {
	return min(360-fabs(node[i].a-node[j].a),
			fabs(node[i].a-node[j].a))/w;
}

double dfs(int i, int j, int d) {
	if (vis[i][j][d]) return f[i][j][d];
	f[i][j][d] = INF;
	vis[i][j][d] = 1;
	if (i==0&&d==0 || j==N+1&&d==1) return f[i][j][d];
	if (d==0) {
		double t = dfs(i-1, j, 0)+cost(i-1, i);
		if (t<node[i].t+EPS && t<f[i][j][d]-EPS) {
			f[i][j][d] = t;
			path[i][j][d] = 0;
		}
		t = dfs(i-1, j, 1)+cost(j, i);
		if (t<node[i].t+EPS && t<f[i][j][d]-EPS) {
			f[i][j][d] = t;
			path[i][j][d] = 1;
		}
	}
	else {
		double t = dfs(i, j+1, 1)+cost(j, j+1);
		if (t<node[j].t+EPS && t<f[i][j][d]-EPS) {
			f[i][j][d] = t;
			path[i][j][d] = 1;
		}
		t = dfs(i, j+1, 0)+cost(i, j);
		if (t<node[j].t+EPS && t<f[i][j][d]-EPS) {
			f[i][j][d] = t;
			path[i][j][d] = 0;
		}
	}
	return f[i][j][d];
}

void write(int i, int j, int d, int dep) {
	if (dep==N) return;
	if (d) write(i, j+1, path[i][j][d], dep+1);
	else write(i-1, j, path[i][j][d], dep+1);
	printf("%d\n", d?node[j].id:node[i].id);
}

int main() {
	int i, j, k;
	while (cin>>da>>w>>N) {
		w *= 360; //degree per minute
		for (i = 1; i <= N; ++i)
			node[i].read(i);
		sort(node+1, node+N+1);
		node[0].a = 0, node[N+1].a = 360;
		memset(vis, 0, sizeof vis);
		f[0][N+1][0] = f[0][N+1][1] = 0;
		vis[0][N+1][0] = vis[0][N+1][1] = 1;
		int ansi, ansd;
		double ans = INF;
		for (i = 0; i <= N; ++i)
			for (k = 0; k < 2; ++k) {
				if (dfs(i, i+1, k)<ans-EPS) {
					ans = dfs(i, i+1, k);
					ansi = i;
					ansd = k;
				}
			}
		if (ans < 1e6) {
			printf("%f\n", ans);
			write(ansi, ansi+1, ansd, 0);
		}
		else puts("Impossible");
	}
	return 0;
}
