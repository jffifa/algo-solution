#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, d1, d2, amt, ans;

int main()
{
	int i, j;
	scanf("%d%d%d", &m, &d1, &d2);
	/*
	if (m*d1<d2)
	{
		for (i = 0; i < m*d1; ++i)
			printf("1 ");
		for (i = m*d1; i < d2; ++i)
			printf("0 ");
	}
	else if (m*d1%d2)
	{
		ans = m*d1/d2+1;
		printf("%d ", m*d1-ans*(d2-1));
		for (i = 1; i < d2; ++i)
			printf("%d ", ans);
	}
	else
	{
		ans = m*d1/d2;
		for (i = 0; i < d2; ++i)
			printf("%d ", ans);
	}
	*/
	amt = m*d1;
	while (amt)
	{
		if (amt%d2) ans = amt/d2+1;
		else ans = amt/d2;
		printf("%d ", ans);
		amt -= ans;
		d2--;
	}
	while (d2--) printf("0 ");
	return 0;
}
