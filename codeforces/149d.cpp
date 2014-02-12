#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000000007ll;

ll f[777][777][3][3];

char s[777];
int match[777];
stack<int> stk;

inline bool ok(int l, int r) {
	return (l>0)^(r>0);
}

inline bool df(int l, int r) {
	return l&&r?l!=r:1;
}

ll dfs(int i, int j, int l, int r) {
	if (~f[i][j][l][r]) return f[i][j][l][r];
	if (j==i+1) return f[i][j][l][r] = ok(l, r);
	ll res = 0;
	if (match[i]==j) {
		if (!ok(l, r)) return f[i][j][l][r] = 0;
		for (int p = 0; p < 3; ++p) {
			if (!df(l, p)) continue;
			for (int q = 0; q < 3; ++q) {
				if (!df(q, r)) continue;
				res += dfs(i+1, j-1, p, q);
			}
		}
	}
	else {
		int k = match[i];
		for (int p = 0; p < 3; ++p) {
			if (!ok(l, p)) continue;
			for (int q = 0; q < 3; ++q) {
				if (!df(p, q)) continue;
				res += dfs(i, k, l, p)*dfs(k+1, j, q, r)%mod;
			}
		}
	}
	return f[i][j][l][r]=res%mod;
}

int main() {
	int i, j, k;
	scanf("%s", s);
	int len = strlen(s);
	for (i = 0; i < len; ++i) {
		if (s[i]=='(') stk.push(i);
		else {
			int t = stk.top();
			stk.pop();
			match[t] = i;
		}
	}
	memset(f, -1, sizeof f);
	ll ans = 0;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			ans += dfs(0, len-1, i, j);
	cout<<ans%mod<<'\n';
	return 0;
}
