#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int w, b;
bool vis[1111][1111][2];
double f[1111][1111][2];

double dfs(int w, int b, bool p) {
	if (vis[w][b][p]) return f[w][b][p];
	vis[w][b][p] = 1;
	int s = w+b;
	f[w][b][p] = (double)w/s;
	double t = (double)b/s;
	if (p) {
		if (b) {
			f[w][b][p] += t*w/(s-1)*(1-dfs(w-1, b-1, !p)); 
			if (b>1) f[w][b][p] += t*(b-1)/(s-1)*(1-dfs(w, b-2, !p));
		}
	}
	else {
		if (b) f[w][b][p] += t*(1-dfs(w, b-1, !p));
	}
	return f[w][b][p];
}

int main() {
	int i, j, k;
	while (cin>>w>>b) {
		memset(vis, 0, sizeof vis);
		for (i = 0; i <= b; ++i) {
			vis[0][i][0] =  vis[0][i][1] = 1;
			f[0][i][0] = 0, f[0][i][1] = 1;
		}
		printf("%.10f\n", dfs(w, b, 0));
	}
	return 0;
}
