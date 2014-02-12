#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL N, M, S;

int main()
{
	cin>>N>>M>>S;
	LL x = N/S;
	if (x*S!=N) x++;
	LL y = M/S;
	if (y*S!=M) y++;
	cout << x*y << endl;
}
