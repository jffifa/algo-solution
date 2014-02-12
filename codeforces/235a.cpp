#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef long long ll;

ll n;
ll ans=1ll;

ll gcd(ll a, ll b) {
	return b?gcd(b, a%b):a;
}

int main() {
	cin>>n;
	int i, j, k;
	if (n<100) {
		for (i = 1; i <= n; ++i)
			for (j = i; j <= n; ++j)
				for (k = j; k <= n; ++k) {
					ll now = i/gcd(i, j)*j;
					now = k/gcd(k, now)*now;
					ans = max(ans, now);
				}
	}
	else {
		if (n%2==0)
			if (n%3==0) ans = (n-1)*(n-2)*(n-3);
			else ans = n*(n-1)*(n-3);
		else ans = n*(n-1)*(n-2);
	}
	cout<<ans<<endl;
	return 0;
}
