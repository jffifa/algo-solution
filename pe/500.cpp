#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 500500507LL;

const int PSIZE = 500500;
int p[PSIZE], pcnt=0;
int mx;
vector<ll> a;

bool prime(int n) {
    if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return 0;
    for (int i = 0; p[i]*p[i]<=n; ++i)
        if (n%p[i]==0) return 0;
    return n>1;
}

void initprime() {
    p[pcnt++] = 2;
    for (int i = 3; pcnt < PSIZE; i+=2) {
        if (prime(i)) p[pcnt++] = i;
    }
}

void solve(ll x) {
    for (; x < mx; x *= x) {
        a.push_back(x);
    }
}

int main() {
    initprime();
    mx = p[PSIZE-1];
    for (int i = 0; i < PSIZE; ++i)
        solve(p[i]);
    //printf("%d\n", a.size());
    sort(a.begin(), a.end());
    ll res = 1LL;
    for (int i = 0; i < PSIZE; ++i)
        res = res*a[i]%MOD;
    cout<<res<<endl;
    return 0;
}

