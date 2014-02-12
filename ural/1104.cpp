/*
	Problem: Ural1104
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxLen = 1000002;

char Str[MaxLen];
int Len, K, R, MinBase;

inline int min(int a, int b)
{return a<b ? a : b;}

inline int max(int a, int b)
{return a>b ? a : b;}

int main()
{
	scanf("%s", Str);
	Len = strlen(Str);
	for (int i = 0; i < Len; ++i)
	{
		if (Str[i]>='0' && Str[i]<='9') Str[i] -= '0';
		else Str[i] -= 'A'-10;
		MinBase = max(MinBase, Str[i]+1);
	}
	for (K = max(2, MinBase); K <= 36; ++K)
	{
		R = 0;
		for (int i = 0; i < Len; ++i)
			R = (R*K+Str[i]) % (K-1);
		if (0 == R)
		{
			printf("%d\n", K);
			return 0;
		}
	}
	printf("No solution.\n");
	return 0;
}
