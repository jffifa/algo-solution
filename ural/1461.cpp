#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
char s[111111];
char t[111111];
int h[111111];

inline int f(char c) {
	if (c=='h') return 0;
	return c=='u'?1:-1;
}

inline char invf(int x) {
	if (x==0) return 'h';
	return x>0?'u':'d';
}

void solve(int i, int now, char c) {
	strncpy(t, s, i-1);
	t[i-1] = c;
	for (int j = i+1; j <= N; ++j) {
		if (now>=2) t[j-1] = 'd';
		else if (now==1)
			if (j==N-1) t[j-1] = 'h';
			else t[j-1] = 'd';
		else t[j-1] = 'u';
		now += f(t[j-1]);
	}
	t[N] = 0;
	puts(t);
}

int main() {
	int i, j, k;
	cin>>N;
	scanf("%s", s);
	h[0] = 0;
	for (i = 1; i <= N; ++i)
		h[i] = h[i-1]+f(s[i-1]);
	for (i = N-1; i >= 2; --i)
		for (j = f(s[i-1])+1; j <= 1; ++j)
			if (h[i]+j-f(s[i-1]) <= N-i) {
				solve(i, h[i]+j-f(s[i-1]), invf(j));
				return 0;
			}
	puts("No solution");
	return 0;
}
