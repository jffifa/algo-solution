#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

ll m1=214748LL, s1=100007LL, m2=201263LL, s2=123123LL;

ll g(ll x) {
    return x^(x/2);
}

ll h1(ll x) {
    return x/m1*m1+(x+s1)%m1;
}

ll h2(ll x) {
    return x/m2*m2+(x+s2)%m2;
}

ll f(ll x) {
    return g(h2(g(h1(g(x)))));
}

int main() {
    ll x;
    while (cin>>x) {
        cout<<f(x)<<'\n';
    }
    return 0;
}
