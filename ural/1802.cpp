#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int dir[6] = {1, 2, 3, 4, 5, 0};
int cube[20][20][20];
int node[6][20][20];

int ord[6], tord[6];
int tmp[20][20];

void rot(int b[20][20]) {
	int i, j;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			tmp[i][j] = b[i][j];
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			b[i][j] = tmp[N-1-j][i];
}

inline void get(int d, int i, int j, int k, int &p, int &q, int &r) {
	switch (d) {
		case 0: p=i; q=j; r=k; break;
		case 1: p=j; q=i; r=N-1-k; break;
		case 2: p=j; q=k; r=i; break;
		case 3: p=i; q=N-1-k; r=j; break;
		case 4: p=k; q=i; r=j; break;
		case 5: p=N-1-k; q=j; r=i; break;
	}
}

bool build(int n, int d) {
	int i, j, k, p, q, r;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < node[n][i][j]; ++k) {
				get(d, i, j, k, p, q, r);
				if (~cube[p][q][r]) return 0;
			}
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < node[n][i][j]; ++k) {
				get(d, i, j, k, p, q, r);
				cube[p][q][r] = n;
			}
	return 1;
}

void clear(int n, int d) {
	int i, j, k, p, q, r;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < node[n][i][j]; ++k) {
				get(d, i, j, k, p, q, r);
				cube[p][q][r] = -1;
			}
}

bool dfs(int i) {
	if (i==5) return 1;
	for (int j = 0; j < 4; rot(node[ord[i]]), ++j) {
		if (!build(ord[i], dir[i])) continue;
		if (dfs(i+1)) return 1;
		clear(ord[i], dir[i]);
	}
	return 0;
}

void write() {
	puts("Yes");
	int i, j, k;
	for (k = 0; k < N; ++k) {
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (j) putchar(' ');
				printf("%d", cube[i][j][k]+1);
			}
			puts("");
		}
	}
}

bool check() {
	int i, j, k, l;
	for (i = 1; i < 5; ++i)
		tord[i] = ord[i];
	sort(ord+1, ord+5);
	do {
		if (dfs(1)) return 1;
	} while (next_permutation(ord+1, ord+5));
	for (i = 1; i < 5; ++i)
		ord[i] = tord[i];
	return 0;
}

int main() {
	int i, j, k;
	cin>>N;
	for (i = 0; i < 6; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < N; ++k)
				scanf("%d", &node[i][j][k]);
	memset(cube, -1, sizeof cube);
	for (i = 0; i < 6; ++i)
		ord[i] = i;
	build(ord[5], dir[5]);
	for (i = 0; i < 5; ++i) {
		for (j = 0; j < 4; rot(node[ord[0]]), ++j) {
			if (!build(ord[0], dir[0])) continue;
			if (check()) {
				write();
				return 0;
			}
			clear(ord[0], dir[0]);
		}
		ord[5] = ord[0];
		for (j = 0; j < 5; ++j)
			ord[j] = ord[j+1];
	}
	puts("No");
	return 0;
}
