#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL N, M, ans;

int main()
{
	scanf("%lld%lld", &N, &M);
	LL hmr = min(N-1>>1, M-1>>1);
	ans = hmr*4;
	N -= hmr<<1;
	M -= hmr<<1;
	if (N==1) ans += 0;
	else if (M==1) ans += 1;
	else if (N==2) ans += 2;
	else ans += 3;
	printf("%lld\n", ans);
	return 0;
}
