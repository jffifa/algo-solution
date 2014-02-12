#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll mod;

ll pow(ll x, int p) {
	ll res = 1;
	for (; p; p>>=1) {
		if (p&1) res = res*x%mod;
		x = x*x%mod;
	}
	return res;
}

int main() {
	cin>>n>>mod;
	ll ans = ((pow(3, n)-1)%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}
