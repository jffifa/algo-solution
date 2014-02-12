#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, l, r;

ll solve(ll x) {
	if (a==b) return x/a;
	if (x<a) return 0;
	ll k = a%(b-a)?a/(b-a):a/(b-a)-1;
	k = max(k, 0ll);
	if (x/a>=k+1) return ((b-a)*(k+1)*k/2+k)+(x-(k+1)*a+1);
	ll t = x/b;
	ll res = (b-a)*(t+1)*t/2+t;
	if (x/a>=t+1) res += x-(t+1)*a+1;
	return res;
}

int main() {
	cin>>a>>b>>l>>r;
	cout<<solve(r)-solve(l-1)<<'\n';
	return 0;
}
