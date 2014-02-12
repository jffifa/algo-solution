#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;

LL f[10000010];
int N;

int main()
{
	cin>>N;
	f[1] = 0;
	LL triple = 1;
	for (int i = 2; i <= N; ++i)
	{
		triple = triple*3%MOD;
		f[i] = (triple-f[i-1])%MOD;
	}
	if (f[N]<0) f[N] += MOD;
	cout << f[N] << endl;
}
