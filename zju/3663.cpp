#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double d) {
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp {
	double x, y, z;
	sp() {}
	sp(double a, double b, double c): x(a), y(b), z(c) {}
	void write() {
		printf("%f %f %f\n", x, y, z);
	}
};

sp operator-(const sp &u, const sp &v) {
	return sp(u.x-v.x, u.y-v.y, u.z-v.z);
}

double dot(const sp &u, const sp &v) {
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

sp det(const sp &u, const sp &v) {
	return sp(u.y*v.z-v.y*u.z,
			u.z*v.x-u.x*v.z,
			u.x*v.y-u.y*v.x);
}

double nrm(const sp &u) {
	return sqrt(u.x*u.x+u.y*u.y+u.z*u.z);
}

double dis(const sp &u, const sp &v) {
	double dx = u.x-v.x;
	double dy = u.y-v.y;
	double dz = u.z-v.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
}

double ang(const sp &u, const sp &v) {
	double d = dot(u, v);
	return acos(d/(nrm(u)*nrm(v)));
}

double r, h, as, ns, at, nt, R;
sp s, t, hmr, mdk;
double a, b, c, tmp;

bool quad(double a, double b, double c, double &x1, double &x2) {
	double delta = b*b-4*a*c;
	if (sgn(delta)<=0) return 0;
	x1 = (-b+sqrt(delta))/(2*a);
	x2 = (-b-sqrt(delta))/(2*a);
	return 1;
}

bool coplane(const sp &a, const sp &b, const sp &c, const sp &d) {
	return sgn(dot(det(c-a, b-a), d-a))==0;
}

bool inside(const sp &s, const sp &p, const sp &t) {
	return sgn(dot(det(s,p),det(s,t)))>=0 && sgn(dot(det(p,t),det(s,t)))>=0;
}

int main() {
	while (cin>>r>>h>>as>>ns>>at>>nt) {
		if (sgn(as)==0 && sgn(at)==0) {
			puts("100.000");
			continue;
		}
		as += PI/2; at += PI/2;
		ns += PI; nt += PI;
		//h /= r; r = 1;
		R = r+h;
		s = sp(R*sin(as)*cos(ns), R*sin(as)*sin(ns), R*cos(as));
		t = sp(R*sin(at)*cos(nt), R*sin(at)*sin(nt), R*cos(at));
		a = s.y*t.z-s.z*t.y; b = s.z*t.x-s.x*t.z; c = s.x*t.y-s.y*t.x;
		tmp = -sqrt(R*R-r*r);
		hmr.z = mdk.z = tmp;
		assert(sgn(a)!=0 || sgn(b)!=0);
		if (sgn(b)) {
			if (quad(a*a+b*b, 2*a*c*tmp, c*c*(R*R-r*r)-b*b*r*r, hmr.x, mdk.x)) {
				hmr.y = (-c*tmp-a*hmr.x)/b;
				mdk.y = (-c*tmp-a*mdk.x)/b;
			}
			else {
				puts("100.000");
				continue;
			}
		}
		else {
			if (quad(a*a+b*b, 2*b*c*tmp, c*c*(R*R-r*r)-a*a*r*r, hmr.y, mdk.y)) {
				hmr.x = (-c*tmp-b*hmr.y)/a;
				mdk.x = (-c*tmp-b*mdk.y)/a;
			}
			else {
				puts("100.000");
				continue;
			}
		}
		//assert(coplane(s, t, hmr, mdk));
		int cnt = 0;
		if (inside(s, hmr, t)) ++cnt;
		if (inside(s, mdk, t)) ++cnt;
		double tot=ang(s, t), dark;
		if (cnt==0) {
			if (inside(hmr, s, mdk) && inside(hmr, t, mdk)) dark = tot;
			else dark = 0;
		}
		else if (cnt==1) {
			if (inside(s, mdk, t)) swap(hmr, mdk);
			assert(inside(s, hmr, t)&&!inside(s, mdk, t));
			if (inside(hmr, s, mdk)) dark = ang(hmr, s);
			else dark = ang(hmr, t);
		}
		else dark = ang(hmr, mdk);
		double ans = (1-dark/tot)*100;
		printf("%.3f\n", ans);
		//cout<<fixed<<setprecision(3)<<ans<<endl;
	}
	return 0;
}
