#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

inline int major(char *s) {
	if (s[1]=='h') return 0;
	if (s[1]=='o') return 1;
	if (s[1]=='a') return 2;
}

struct snode {
	int s, t;
	double gpa;
	void read() {
		char str[20];
		scanf("%s", str); s = major(str);
		scanf("%s", str); t = major(str);
		scanf("%lf", &gpa);
	}
	bool operator<(const snode &rhs) const {
		return gpa<rhs.gpa;
	}
}node[22];

int N;
ll f[22];

ll dfs(int i, int s, int t) {
	if (i==N) return 0;
	if (~s && ~t) return !s||!t?f[N-i]:f[N-i]<<1;
	int ss = (~s?s:node[i].s);
	int tt = (~t?t:node[i].t);
	if (ss==tt) return dfs(i+1, s, t);
	if (ss && tt)
		return dfs(i+1, s, tt)+1+dfs(i+1, ss, tt)+1+dfs(i+1, ss, t);
	else
		return dfs(i+1, s, 3-ss-tt)+1+dfs(i+1, 3-ss-tt, t);
}

int main() {
	int i, j, k;
	f[0] = 0;
	for (i = 1; i < 22; ++i)
		f[i] = f[i-1]*3+1;
	while (cin>>N) {
		for (i = 0; i < N; ++i)
			node[i].read();
		sort(node, node+N);
		cout<<dfs(0, -1, -1)<<'\n';
	}
	return 0;
}
