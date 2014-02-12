#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1234567890ll;

struct sm {
	ll m[4][4];
	void init() {memset(m, 0, sizeof m);}
	sm() {init();}
	void eye() {for (int i = 0; i < 4; ++i) m[i][i] = 1;}
	void write() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j)
				printf("%lld ", m[i][j]);
			puts("");
		}
	}
};

sm operator*(const sm &a, const sm &b) {
	sm res;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				if (a.m[i][k] && b.m[k][j])
					res.m[i][j] = (res.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
	return res;
}

sm operator^(sm x, ll p) {
	sm res;
	res.eye();
	for (; p; p>>=1) {
		if (p&1) res = res*x;
		x = x*x;
	}
	return res;
}

struct snode {
	ll x, u, v;
	void read() {cin>>x>>u>>v; x--; u--; v--;}
	bool operator<(const snode &rhs) const {
		return x < rhs.x;
	}
}node[10];

ll N, p, q;

ll solve() {
	int i, j, k;
	ll res = 1;
	sort(node, node+8);
	node[8] = node[0];
	node[8].x += N;
	sm m;
	m.m[0][0]=m.m[0][1]=m.m[0][2]=m.m[1][3]=m.m[2][3] = 1;
	m.m[1][0]=m.m[1][1]=m.m[3][2] = (q-1)%mod;
	m.m[2][0]=m.m[2][2]=m.m[3][1] = (p-1)%mod;
	m.m[3][3] = p>1&&q>1?(p+q-3)%mod:0;
	//m.write();
	//(m^3).write();
	//from i to i+1
	for (i = 0; i < 8; ++i) {
		if (node[i].x==node[i+1].x) {
			if (node[i].u^node[i+1].u || node[i].v^node[i+1].v) return 0;
			else continue;
		}
		sm now = m^(node[i+1].x-node[i].x);
		j = ((node[i].u!=node[i+1].u)<<1)|(node[i].v!=node[i+1].v);
		//printf("%d %lld\n", j, now.m[0][j]);
		res = (res*now.m[0][j])%mod;
	}
	res %= mod;
	if (res<0) res += mod;
	return res;
}

int main() {
	int i, j, k;
	while (cin>>N>>p>>q) {
		for (i = 0; i < 8; ++i)
			node[i].read();
		cout<<solve()<<endl;
	}
	return 0;
}
