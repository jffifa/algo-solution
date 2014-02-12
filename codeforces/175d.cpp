#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double EPS = 1e-7;

int hp[2], dt[2], l[2], r[2], pi[2];
double p[2], a[2];
double f[2][222];
int t[2];

void update(int i) {
	int j, k;
	f[i][0] = 0;
	for (j = 1; j <= hp[i]; ++j) {
		double h = f[i][j]*(1-p[!i])/(r[!i]-l[!i]+1);
		f[i][j] *= p[!i];
		for (k = l[!i]; k <= r[!i]; ++k)
			f[i][max(0, j-k)] += h;
	}
	for (a[i]=0, j=1; j <= hp[i]; ++j)
		a[i] += f[i][j];
}

int main() {
	int i, j, k, d;
	for (i = 0; i < 2; ++i) {
		cin>>hp[i]>>dt[i]>>l[i]>>r[i]>>pi[i];
		p[i] = pi[i]/100.0;
	}
	if (pi[0]==100) return puts("0"), 0;
	else if (pi[1]==100) return puts("1"), 0;
	a[0] = a[1] = f[0][hp[0]] = f[1][hp[1]] = 1;
	double ans = 0;
	for (; a[0]>EPS && a[1]>EPS; ) {
		i = t[0]<=t[1]?0:1;
		t[i] += dt[i];
		update(!i);
		if (i==0) ans += a[0]*f[1][0];
	}
	printf("%.6f\n", ans);
	return 0;
}
