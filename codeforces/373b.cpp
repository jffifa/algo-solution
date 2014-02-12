#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll W, M, K;
ll ans = 0;
ll pw[111];

int getlen(ll x) {
    int res = 0;
    for (; x; res++, x/=10ll);
    return res;
}

int main() {
    int i, j, k;
    pw[0] = 1ll;
    for (i = 1; i <= 17; ++i)
        pw[i] = pw[i-1]*10ll;
    while (cin>>W>>M>>K) {
        ans = 0ll;
        int b = getlen(M);
        while (W/K >= b) {
            if (W/K >= b*(pw[b]-M)) {
                ans += pw[b]-M;
                W -= b*(pw[b]-M)*K;
                M = pw[b];
            } else {
                ll cnt = W/(K*b);
                W -= cnt*b*K;
                ans += cnt;
            }
            b++;
        }
        //printf("%lld %lld %lld %lld\n", W, M, K, ans);
        cout<<ans<<endl;
    }
    return 0;
}
