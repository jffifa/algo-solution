#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, M;
ll cnt[111][111];

ll solve(int i, int j) {
	ll res = 0;
	int p, q, l = 0, r = j;
	for (p = 1; p <= i; ++p) {
		while (l<j && l<=r && p*i>l*(j-l)) ++l;
		while (r>0 && l<=r && p*i>r*(j-r)) --r;
		q = p*(i-p)/j;
		if (q >= r) res += max(0, j-q-1);
		else if (q >= l) res += max(0, j-r-1);
		else res += max(0, j-r-1)+max(0, l-q-1);
	}
	return res;
}

int main() {
	int i, j, p, q, l, r;
	for (i = 1; i <= 100; ++i)
		for (j = 1; j <= 100; ++j)
			cnt[i][j] = solve(i, j)+solve(j, i)<<1;
	while (cin>>N>>M) {
		ll ans = 0;
		for (i = 1; i <= N; ++i)
			for (j = 1; j <= M; ++j)
				ans += cnt[i][j]*(N-i+1)*(M-j+1);
		cout<<ans<<'\n';
	}
	return 0;
}
