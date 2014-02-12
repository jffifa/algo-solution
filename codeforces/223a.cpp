#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 111111;

int N;
char s[MAX];
int f[MAX];
int sum[MAX];

bool match(int i, int j) {
	if (i<1 || j<1) return 0;
	if (s[i-1]==')') return s[j-1]=='(';
	else return s[j-1]=='[';
}

int get(int i) {
	return f[i-1]<N?f[i-1]:i;
}

int main() {
	int i, j, k;
	while (cin>>s) {
		N = strlen(s);
		sum[0] = 0;
		for (i = 1; i <= N; ++i)
			sum[i] = sum[i-1]+(s[i-1]==']');
		memset(f, 127, sizeof f);
		for (i = 2; i <= N; ++i) {
			if (s[i-1]=='(' || s[i-1]=='[') continue;
			if (match(i, i-1)) f[i] = get(i-1);
			if (f[i-1]<N && match(i, f[i-1]-1)) f[i] = min(f[i], get(f[i-1]-1));
		}
		int ans=0, ansi;
		for (i = 1; i <= N; ++i)
			if (f[i]<N && sum[i]-sum[f[i]-1]>ans) {
				ans = sum[i]-sum[f[i]-1];
				ansi = i;
			}
		printf("%d\n", ans, ansi);
		if (ans>0) {
			for (i = f[ansi]-1; i < ansi; ++i)
				putchar(s[i]);
		}
		puts("");
	}
	return 0;
}
