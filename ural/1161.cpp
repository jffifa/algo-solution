/*
	Problem: Ural1161
	Algorithm: Greedy
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N;
double d, p, q;
vector<double> Ans;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &d);
		Ans.push_back(d);
	}
	sort(Ans.begin(), Ans.end());
	while (Ans.size() > 1)
	{
		p = Ans.back();
		Ans.pop_back();
		q = Ans.back();
		Ans.pop_back();
		d = 2*sqrt(p*q);
		Ans.push_back(d);
	}
	printf("%.2lf\n", Ans[0]);
	return 0;
}
