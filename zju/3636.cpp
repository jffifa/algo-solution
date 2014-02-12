#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K;
pair<int, int> ans;
int ctrl[33];
int code[22222];
int query;
char str[33];

int gauss(int N, int M, int a[]) {
	int i, j, r, c, pvt;
	for (r=0, c=0; r<N && c<M; ++r, ++c) {
		for (pvt = r; pvt < N; ++pvt)
			if (a[pvt]&1<<c) break;
		if (pvt == N) {
			r--;
			continue;
		}
		ctrl[c] = r;
		if (pvt != r) swap(a[r], a[pvt]);
		for (i = r+1; i < N; ++i)
			if (a[i]&1<<c) a[i] ^= a[r];
	}
	return r;
}

bool solve(int s) {
	int now = 0;
	int i, j;
	for (i = 0; i < M; ++i) if ((now^s)&1<<i) {
		if (ctrl[i]==-1) return 0;
		now ^= code[ctrl[i]];
	}
	return 1;
}

void dfs(int i, int err) {
	if (i==M) {
		if (make_pair(err, query)<ans && solve(query))
			ans = make_pair(err, query);
		return;
	}
	dfs(i+1, err);
	if (err < 3) {
		query ^= 1<<i;
		dfs(i+1, err+1);
		query ^= 1<<i;
	}
}

inline int encode(char *s) {
	int res = 0;
	reverse(str, str+M);
	for (int j = 0; j < M; ++j)
		res |= str[j]-48<<j;
	return res;
}

inline void decode(int x, char *s) {
	for (int i = 0; i < M; ++i) {
		s[i] = (x&1)+48;
		x >>= 1;
	}
	reverse(s, s+M);
	s[M] = 0;
}

int main() {
	int i, j, k;
	while (cin>>M>>N>>K) {
		for (i = 0; i < N; ++i) {
			scanf("%s", str);
			code[i] = encode(str);;
		}
		memset(ctrl, -1, sizeof ctrl);
		gauss(N, M, code);
		while (K--) {
			scanf("%s", str);
			query = encode(str);
			ans = make_pair(10, 0x7fffffff);
			dfs(0, 0);
			if (ans.first==10) puts("NA");
			else {
				decode(ans.second, str);
				puts(str);
			}
		}
	}
	return 0;
}
