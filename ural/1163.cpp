#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-6;
const double PI = acos(-1.0);
const double R = 0.4;

inline int dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp
{
	double x, y;
	sp() {}
	sp(double a, double b): x(a), y(b) 
	void read() {scanf("%lf%lf", &x, &y);}
}p[20];

inline sp operator-(const sp &u, const sp &v)
{return sp(u.x-v.x, u.y-v.y);}

inline double dis(const sp &u, const sp &v)
{
	double dx = u.x-v.x;
	double dy = u.y-v.y;
	return sqrt(dx*dx+dy*dy);
}

double pa(const sp &o, const sp &p)
{return atan2(p.y-o.y, p.x-o.x);}

struct snode
{
	double a;
	int s;
	snode() {}
	snode(double x, int y): a(x), s(y) {}
};
bool operator<(const snode &u, const snode &v)
{
	if (dcmp(u.a-v.a)==0) return u.s>v.s;
	return u.a>v.a;
}

inline bool between(double a, double s, double t)
{return dcmp(a-s)>0&&dcmp(a-t)<0;}

inline bool inside(double a, double s, double t)
{return between(a, s, t)||between(a+2*PI, s, t)||between(a-2*PI, s, t);}

double rgl(double a)
{
	if (a<-PI) return a+PI;
	if (a>PI) return a-PI;
	return a;
}

double as[20], at[20];
vector<int> hit[20];
vector<snode> node;

int main()
{
	int i, j, k;
	for (i = 0; i < 8; ++i)
		p[i].read();
	for (i = 8; i < 16; ++i)
		p[i].read();
	for (i = 0; i < 16; ++i)
	{
		node.clear();
		for (j = 0; j < 16; ++j)
		{
			if (i==j) continue;
			double a = pa(p[i], p[j]);
			double da = asin(R/(dis(p[i], p[j])/2));
			as[j] = a-da; at[j] = a+da;
			node.push_back(snode(rgl(as), 1<<j));
			node.push_back(snode(rgl(at), -(1<<j)));
		}
		int s = 0;
		for (j = 0; j < 16; ++j)
		{
			if (i==j) continue;
			if (inside(-PI, as[j], at[j])) s += 1<<j;
		}
		if (s)
		{
			node.push_back(snode(-PI-EPS), s);
			node.push_back(snode(PI+EPS), -s);
		}
		sort(node.begin(), node.end());
		s = 0;
		for (j = 0; j < node.size(); ++j)
		{
			s += node[j].s;
			assert(s>=0);
			hit[i].push_back(s);
		}
	}
	return 0;
}
