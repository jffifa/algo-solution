#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const double EPS = 1e-8;

struct ss
{
	int t, s;
	void read() {cin>>t>>s;}
};
ss x, y;
int N, ans;

bool fit(ss x, ss y)
{
	switch(x.t)
	{
	case 1:
		switch (y.t)
		{
			case 1: return y.s<=x.s; break;
			case 2: return y.s<=x.s*2; break;
			case 3: return y.s<=x.s*2; break;
		}
		break;
	case 2:
		switch (y.t)
		{
			case 1: return sqrt(2.0)*y.s<x.s+EPS; break;
			case 2: return y.s<x.s*sqrt(2.0)+EPS; break;
			case 3: return sqrt(3.0)*y.s<2*sqrt(2.0)*x.s+EPS; break;
		}
		break;
	case 3:
		switch(y.t)
		{
			case 1: return y.s*2<=x.s; break;
			case 2: return y.s<=x.s; break;
			case 3: return sqrt(3.0)*y.s<2*x.s+EPS; break;
		}
		break;
	}
}

int main()
{
	x.read();
	cin>>N;
	while (N--)
	{
		y.read();
		ans += fit(x, y);
	}
	cout<<ans<<endl;
	return 0;
}
