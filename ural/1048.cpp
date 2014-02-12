/*
	Problem: Ural1048
	Algorithm: High Precision
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxLen = 1000002;

int Len;
int x[MaxLen], y[MaxLen], Ans[MaxLen];

int main()
{
	scanf("%d", &Len);
	for (int i = Len-1; i >= 0; --i)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 0; i < Len; ++i)
	{
		Ans[i] += x[i]+y[i];
		if (Ans[i] >= 10)
		{
			++Ans[i+1];
			Ans[i] -= 10;
		}
	}
	for (int i = Len-1; i >= 0; --i) printf("%d", Ans[i]);
	printf("\n");
	return 0;
}
