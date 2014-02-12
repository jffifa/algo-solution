#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double x) {
	if (fabs(x)<EPS) return 0;
	return x>0?1:-1;
}

struct sp {
	double x, y;
	double pa;
	int cnt;
	sp() {}
	sp(double a, double b): x(a), y(b) {}
	sp(double a, double b, double c, int d): x(a), y(b), pa(c), cnt(d) {}
	bool operator<(const sp &rhs) const {
		if (sgn(pa-rhs.pa)==0) return cnt>rhs.cnt;
		return pa<rhs.pa;
	}
	void read() {scanf("%lf%lf", &x, &y);}
	void write() {printf("%.10f %.10f\n", x, y);}
}t, s1, s2, p[5], e[20];
double r, rad[5];
int cover[5];

sp operator*(double d, const sp &v) {
	return sp(d*v.x, d*v.y);
}

sp operator-(const sp &u, const sp &v) {
	return sp(u.x-v.x, u.y-v.y);
}

sp operator+(const sp &u, const sp &v) {
	return sp(u.x+v.x, u.y+v.y);
}

double dot(const sp &u, const sp &v) {
	return u.x*v.x+u.y*v.y;
}

double det(const sp &u, const sp &v) {
	return u.x*v.y-u.y*v.x;
}

double dis(const sp &u, const sp &v) {
	double dx = u.x-v.x;
	double dy = u.y-v.y;
	return sqrt(dx*dx+dy*dy);
}

double dissqr(const sp &u, const sp &v) {
	double dx = u.x-v.x;
	double dy = u.y-v.y;
	return dx*dx+dy*dy;
}

void write(sp u, sp v) {
	puts("Now we have enough power");
	u.write(); v.write();
}

bool cirint(const sp &u, double ru, const sp &v, double rv, sp &a, sp &b) {
	double d = dis(u, v);
	if (sgn(d-(ru+rv))>0 || sgn(d-fabs(ru-rv))<=0) return 0;
	sp c = u-v;
	double ca, sa, cb, sb, csum, ssum;

	ca = c.x/d, sa = c.y/d;
	cb = (rv*rv+d*d-ru*ru)/(2*rv*d), sb = sqrt(1-cb*cb);
	csum = ca*cb-sa*sb;
	ssum = sa*cb+sb*ca;
	a = sp(rv*csum, rv*ssum);
	a = a+v;

	sb = -sb;
	csum = ca*cb-sa*sb;
	ssum = sa*cb+sb*ca;
	b = sp(rv*csum, rv*ssum);
	b = b+v;

	return 1;
}

bool cu(int N, sp p[], double r[], sp &res) {
	int i, j, k;
	memset(cover, 0, sizeof cover);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			double rd = r[i]-r[j];
			if (i!=j && sgn(rd)>0 && sgn(dis(p[i], p[j])-rd)<=0)
				cover[j]++;
		}
	sp a, b;
	for (i = 0; i < N; ++i) {
		int ecnt = 0;
		e[ecnt++] = sp(p[i].x-r[i], p[i].y, -PI, 1);
		e[ecnt++] = sp(p[i].x-r[i], p[i].y, PI, -1);
		for (j = 0; j < N; ++j) {
			if (j==i) continue;
			if (cirint(p[i], r[i], p[j], r[j], a, b)) {
				e[ecnt++] = sp(a.x, a.y, atan2(a.y-p[i].y, a.x-p[i].x), 1);
				e[ecnt++] = sp(b.x, b.y, atan2(b.y-p[i].y, b.x-p[i].x), -1);
				if (sgn(e[ecnt-2].pa-e[ecnt-1].pa)>0) {
					e[0].cnt++;
					e[1].cnt--;
				}
			}
		}
		sort(e, e+ecnt);
		int cnt = e[0].cnt;
		for (j = 1; j < ecnt; ++j) {
			if (cover[i]+cnt==N) {
				double a = (e[j].pa+e[j-1].pa)/2;
				res = p[i]+sp(r[i]*cos(a), r[i]*sin(a));
				return 1;
			}
			cnt += e[j].cnt;
		}
	}
	return 0;
}

bool solve(const sp &o, const sp &u, const sp &v, double r) {
	p[0] = o, rad[0] = r+r;
	p[1] = u; p[2] = v; rad[1] = rad[2] = r;
	sp a, b;
	if (cu(3, p, rad, a)) {
		b = 0.5*(a-o);
		b = o+b;
		write(a, b);
		return 1;
	}
	else return 0;
}

int main() {
	cin>>r;
	t.read(); s1.read(); s2.read();
	sp a, b, c, d;
	if (cirint(s1, r, s2, r, a, b)) {
		if (solve(t, s1, s2, r)) return 0;
	}
	else {
		if (cirint(s1, r, t, r, a, b) && cirint(s2, r, t, r, c, d)) {
			write(a, c);
			return 0;
		}
		else {
			if (solve(s1, t, s2, r)) return 0;
			if (solve(s2, t, s1, r)) return 0;
		}
	}
	puts("Death");
	return 0;
}
