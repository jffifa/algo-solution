#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 32000;

int p[MAX], pcnt=0;
int minf[MAX];
void initprime() {
	for (int i = 2; i < MAX; ++i) {
		if (!minf[i]) {
			minf[i] = i;
			p[pcnt++] = i;
		}
		for (int j = 0; j < pcnt && p[j]*i < MAX; ++j) {
			minf[p[j]*i] = p[j];
			if (i%p[j]==0) break;
		}
	}
}

int pf(int n, int *f, int *nf) {
	int cnt = 0;
	int n2 = (int)sqrt((double)n);
	for (int i = 0; n>1 && p[i]<=n2; ++i)
		if (n%p[i]==0) {
			for (nf[cnt]=0; n%p[i]==0; n/=p[i]) ++nf[cnt];
			f[cnt++] = p[i];
		}
	if (n > 1) {
		nf[cnt] = 1;
		f[cnt++] = n;
	}
	return cnt;
}

int N;
int f[20], nf[20];
double lcm[128][MAX];
int path[128][MAX];
vector<int> ans;

int main() {
	int i, j, k, l;
	initprime();
	double t = 1;
	for (i = 0; i < 120; ++i)
		t *= p[i];
	cin>>N;
	pf(N, f, nf);
	int x = f[0], gcd = N/x;
	for (j = 0; j <= x; ++j)
		lcm[0][j] = 1;
	for (i = 1; i<128 && p[i-1]<=x; ++i)
		for (j = 1; j <= x; ++j) {
			lcm[i][j] = lcm[i-1][j];
			path[i][j] = 0;
			for (k = p[i-1]; k <= j; k *= p[i-1])
				if (lcm[i][j]<lcm[i-1][j-k]*k) {
					lcm[i][j] = lcm[i-1][j-k]*k;
					path[i][j] = k;
				}
		}
	if (x==2 || x==3) {
		ans.push_back(1);
		ans.push_back(x-1);
		x = 0;
	}
	else {
		for (i = 127; i && x; --i)
			if (path[i][x]) {
				ans.push_back(path[i][x]);
				x -= path[i][x];
			}
	}
	while (x--) ans.push_back(1);
	for (i = 0; i < ans.size(); ++i)
		printf("%d ", gcd*ans[i]);
	return 0;
}
