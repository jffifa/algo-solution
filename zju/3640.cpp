#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, f;
double t[11111];
int c[11111];
double e[22222];
double sum;

double dfs(int f) {
	if (e[f] > -1) return e[f];
	if (f > c[N-1]) return sum;
	e[f] = 0;
	int i;
	for (i = 0; i < N; ++i) {
		if (c[i] >= f) break;
		e[f] += t[i]/N;
	}
	for (; i < N; ++i)
		e[f] += (1+dfs(f+c[i]))/N;
	return e[f];
}

int main() {
	int i, j, k;
	while (cin>>N>>f) {
		for (i = 0; i < N; ++i)
			scanf("%d", c+i);
		sort(c, c+N);
		sum = 0;
		for (i = 0; i < N; ++i) {
			t[i] = floor((1+sqrt(5.0))/2*c[i]*c[i]+1e-9);
			sum += t[i];
		}
		sum /= N;
		for (i = 0; i <= 20022; ++i)
			e[i] = -10;
		printf("%.3f\n", dfs(f));
	}
	return 0;
}
