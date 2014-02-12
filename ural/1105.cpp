#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;

inline char dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sseg
{
	double l, r;
	int id;
	bool vis;
}seg[10010];
bool operator<(const sseg &s1, const sseg &s2)
{
	if (dcmp(s1.l-s2.l)==0) return s1.r>s2.r;
	return s1.l<s2.l;
}

double t0, t1, t;
vector<int> ans;
int N;

int main()
{
	int i, j, k;
	scanf("%lf%lf", &t0, &t1);
	t = t1-t0;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%lf%lf", &seg[i].l, &seg[i].r);
		seg[i].id = i+1;
	}
	sort(seg, seg+N);
	/*
	for (i = 0; i < N; ++i)
		printf("%d\n", seg[i].id);
	*/
	int maxi; double nowr, maxr;
	i = 0;
	while (1)
	{
		//printf("%d\n", seg[i].id);
		seg[i].vis = 1;
		nowr = seg[i++].r;
		if (dcmp(nowr-t1)==0) break;
		maxr = t0;
		while (i<N && dcmp(seg[i].l-nowr)<=0)
		{
			if (seg[i].r > maxr)
			{
				maxr = seg[i].r;
				maxi = i;
			}
			i++;
		}
		swap(seg[--i], seg[maxi]);
	}
	for (i = 0; i < N; ++i)
		if (seg[i].vis) ans.push_back(i);
	double o=0, e=0, len;
	for (i = 0; i < ans.size(); ++i)
	{
		len = seg[ans[i]].r-seg[ans[i]].l;
		if (i&1) o += len;
		else e += len;
	}
	//printf("%f %f\n", o, e);
	if (dcmp(o-2.0/3*t)>=0)
	{
		printf("%d\n", ans.size()/2);
		for (i = 0; i < ans.size(); ++i)
			if (i&1) printf("%d\n", seg[ans[i]].id);
	}
	else if (dcmp(e-2.0/3*t)>=0)
	{
		printf("%d\n", (ans.size()+1)/2);
		for (i = 0; i < ans.size(); ++i)
			if (!(i&1)) printf("%d\n", seg[ans[i]].id);
	}
	else
	{
		printf("%d\n", ans.size());
		for (i = 0; i < ans.size(); ++i)
			printf("%d\n", seg[ans[i]].id);
	}
	return 0;
}
