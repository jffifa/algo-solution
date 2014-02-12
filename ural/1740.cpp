#include <cstdio>
#include <cstring>
using namespace std;

int l, k, h;
double ansmin, ansmax;

int main()
{
	scanf("%d%d%d", &l, &k, &h);
	if (l%k==0)
		ansmin=ansmax=l/k*h;
	else
	{
		ansmin=l/k*h;
		ansmax=ansmin+h;
	}
	printf("%.6f %.6f\n", ansmin, ansmax);
	return 0;
}