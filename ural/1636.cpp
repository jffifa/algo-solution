#include <cstdio>
#include <cstring>

int t1, t2, p;

int main()
{
	scanf("%d%d", &t1, &t2);
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &p);
		t2 -= p*20;
	}
	if (t1<=t2) puts("No chance.");
	else puts("Dirty debug :(");
	return 0;
}
