#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 60006;

int N, f, x, ans;

int main()
{
	int i, j, k;
	cin>>N;
	ans = f = 0;
	for (i = 0; i < N; ++i)
	{
		cin>>x;
		if (f>0) f += x;
		else f = x;
		ans = max(ans, f);
	}
	cout << ans << endl;
	return 0;
}
