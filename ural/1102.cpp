#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char word[6][10] = {"out", "output", "puton", "in", "input", "one"};
int len[6] = {3, 6, 5, 2, 5, 3};

int T, N;
char s[10001000];
bool f[10001000];

inline bool check(int i, int j) {
	for (int k = 0; k < len[j]; ++i, ++k)
		if (s[i]!=word[j][k]) return 0;
	return 1;
}

bool solve() {
	int i, j;
	N = strlen(s);
	for (i = 0; i <= N; ++i)
		f[i] = 0;
	f[0] = 1;
	for (i = 0; i < N; ++i) {
		if (!f[i]) continue;
		for (j = 0; j < 6; ++j)
			if (check(i, j)) f[i+len[j]] = 1;
	}
	return f[N];
}

int main() {
	cin>>T;
	int i, j, k;
	while (T--) {
		scanf("%s", s);
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}
