#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

int N, x;
int a[2000];
int ans;
bool has=0;

int main()
{
	int i, j=0, k=0;
	cin>>N>>x;
	for (i = 0; i < N; ++i)
	{
		cin>>a[i];
		if (a[i]==x) has = 1;
	}
	//puts("here");
	if (!has)
	{
		a[N++] = x;
		ans++;
	}
	sort(a, a+N);
	deque<int> p, q, r;
	for (i = 0; i < N; ++i)
		p.push_back(a[i]);
	q = r = p;
	while (q[(q.size()-1)/2]!=x && q.size()<2000)
	{
		j++;
		q.push_front(1);
	}
	while (r[(r.size()-1)/2]!=x && r.size()<2000)
	{
		k++;
		r.push_back(100000);
	}
	cout << ans+min(j,k) << endl;
	return 0;
}

