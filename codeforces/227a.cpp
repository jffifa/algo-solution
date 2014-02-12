#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

struct sp {
	ll x, y;
	sp() {}
	sp(ll xx, ll yy): x(xx), y(yy) {}
	void read() {cin>>x>>y;}
}a, b, c;

inline sp operator- (const sp &u, const sp &v)
{return sp(u.x-v.x, u.y-v.y);}

inline sp operator+ (const sp &u, const sp &v)
{return sp(u.x+v.x, u.y+v.y);}

inline sp operator* (double d, const sp &v)
{return sp(v.x*d, v.y*d);}

ll det(const sp &u, const sp &v)
{return u.x*v.y - v.x*u.y;}

ll dir(const sp &p, const sp &u, const sp &v)
{return det(u-p, v-p);}

int main() {
	a.read(); b.read(); c.read();
	ll res = det(b-a, c-b);
	if (res>0) puts("LEFT");
	else if (res<0) puts("RIGHT");
	else puts("TOWARDS");
	return 0;
}
