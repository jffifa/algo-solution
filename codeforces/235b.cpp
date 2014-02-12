#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
double p[111111], ans;

int main() {
	int i, j, k;
	cin>>N;
	for (i = 0; i < N; ++i) {
		scanf("%lf", p+i);
		ans += p[i];
	}
	double now = 0;
	for (i = 1; i < N; ++i) {
		now = (now+p[i-1])*p[i];
		ans += 2*now;
	}
	printf("%.10f\n", ans);
	return 0;
}
