#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, Q, q;
int a[111111];
ll sum[111111], ans[111111];

ll solve(int q) {
	if (ans[q]>=0) return ans[q];
	ll res = 0;
	ll i, l, r, step;
	for (i=0, l=0, step=1; l < N; ++i, l+=step, step*=q) {
		r = l+step;
		if (r > N) r = N;
		res += (sum[r]-sum[l])*i;
	}
	return ans[q] = res;
}

int main() {
	int i, j, k;
	cin>>N;
	for (i = 0; i < N; ++i)
		cin>>a[i];
	sort(a, a+N);
	reverse(a, a+N);
	sum[0] = 0;
	for (i = 0; i < N; ++i)
		sum[i+1] = sum[i]+a[i];
	memset(ans, -1, sizeof ans);
	cin>>Q;
	bool f = 0;
	while (Q--) {
		cin>>q;
		if (f) putchar(' ');
		f = 1;
		cout<<solve(q);
	}
	return 0;
}
