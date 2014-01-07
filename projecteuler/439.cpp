#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000000ll;

const ll N = 100000000000LL;
const int SQ = 316227;
/*
//linear time sieve
const int PSIZE = 100000;
int p[PSIZE], pcnt=0;
const int MAX = SQ+100;
int minf[MAX];
void initprime() {
	for (int i = 2; i < MAX; ++i) {
		if (!minf[i]) {
			minf[i] = i;
			p[pcnt++] = i;
		}
		for (int j = 0; j < pcnt && p[j]*i < MAX; ++j) {
			minf[p[j]*i] = p[j];
			if (i%p[j]==0) break;
		}
	}
}

//factorization
int pf(ll n, ll *f, int *nf) {
	int cnt = 0;
	int n2 = (int)sqrt((double)n);
	for (int i = 0; n>1 && p[i]<=n2; ++i) {
		if (n%p[i]==0) {
			for (nf[cnt]=0; n%p[i]==0; n/=p[i]) ++nf[cnt];
			f[cnt++] = p[i];
		}
    }
	if (n > 1) {
		nf[cnt] = 1;
		f[cnt++] = n;
	}
	return cnt;
}
//divisor sum
int calc_d(ll x) {
    ll f[20]; int nf[20];
    int cnt = pf(x, f, nf);
    ll res = 1LL;
    int i, j;
    for (i = 0; i < cnt; ++i) {
        ll t = 1LL;
        for (j = 0; j < nf[i]; ++j)
            t = (t*f[i]+1LL)%MOD;
        res = res*t%MOD;
    }
    return (int)res;
}
*/


ll s[333333]/*s(x)*/, s2[333333]/*s(N/x)*/;

ll sum(ll s, ll t) {
    ll p = s+t;
    ll q = t-s+1LL;
    if (p%2LL==0LL)
        p /= 2LL;
    else
        q /= 2LL;
    return (p%MOD)*(q%MOD)%MOD;
}

//sum of d(1), d(2), ..., d(x)
ll calc_d_sum(ll x) {
    ll res = 0LL;
    ll sq = (ll)sqrt((double)x);
    for (ll i = 1LL; x/i >= sq; ++i) {
        res = (res + x/i*i)%MOD;
    }
    for (ll i = 1LL; i < sq; ++i) {
        res = (res + i*sum(x/(i+1LL)+1, x/i))%MOD;
    }
    return res;
}

//s(x)
ll calc_s(ll x) {
    ll homura = calc_d_sum(x);
    homura = homura*homura%MOD;
    //cout<<homura<<endl;
    ll madoka = 0;
    ll sq = (ll)sqrt((double)x);
    for (ll i = 2LL; x/i >= sq; ++i)
        madoka = (madoka + i*s[x/i])%MOD;
    for (ll i = 1LL; i < sq; ++i)
        madoka = (madoka + s[i]*sum(x/(i+1LL)+1, x/i))%MOD;
    //cout<<madoka<<endl;
    return s[x] = (homura-madoka)%MOD;
}

//s(N/x)
ll calc_s2(ll x) {
    ll y = N/x;
    ll homura = calc_d_sum(y);
    homura = homura*homura%MOD;
    //cout<<homura<<endl;
    ll madoka = 0;
    ll sq = (ll)sqrt((double)y);
    for (ll i = 2LL; y/i >= sq; ++i)
        if (y/i<=SQ)
            madoka = (madoka + i*s[y/i])%MOD;
        else
            madoka = (madoka + i*s2[i*x])%MOD;
    for (ll i = 1LL; i < sq; ++i)
        madoka = (madoka + s[i]*sum(y/(i+1LL)+1, y/i))%MOD;
    //cout<<madoka<<endl;
    return s2[x] = (homura-madoka)%MOD;
}

int main() {
    /*
    initprime();
    printf("%d %d\n", pcnt, p[pcnt-1]);
    */
    int i, j, k;
    /*
    for (i = 1; i < 10; ++i) {
        cout<<calc_d_sum(i)<<endl;
    }
    */
    for (i = 1; i <= SQ; ++i) {
        calc_s(i);
    }
    /*
    cout<<s[3]<<endl;
    cout<<MOD+s[1000]<<endl;
    */
    for (i = SQ; i >= 1; --i) {
        calc_s2(i);
    }
    cout<<(s2[1]+MOD)%MOD<<endl;
    return 0;
}
/*
 * [jffifa@jffifa-pc pe]$ time ./439
 * 968697378
 *
 * real    0m30.704s
 * user    0m30.700s
 * sys     0m0.000s
 */
