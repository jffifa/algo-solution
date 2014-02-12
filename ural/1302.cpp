#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int si, sj, ti, tj;

void get(int n, int &i, int &j) {
	for (i = 1; i*i<n; ++i);
	j = n-(i-1)*(i-1);
}

int solve(int &i, int &j, int d) {
	int res = 0;
	while (i!=ti) {
		if (j&1) ++i, ++j;
		else j += d;
		++res;
	}
	return res;
}

int main() {
	int i, j, k;
	cin>>N>>M;
	if (N>M) swap(N, M);
	if (N==M) {
		puts("0");
		return 0;
	}
	get(N, si, sj);
	get(M, ti, tj);
	int l, r, ans;
	i = si, l = sj;
	solve(i, l, -1);
	i = si, r = sj;
	ans = solve(i, r, 1);
	if (l<=tj && tj<=r) printf("%d\n", ans+(tj&1));
	else printf("%d\n", ans+min(abs(tj-l), abs(tj-r)));
}
