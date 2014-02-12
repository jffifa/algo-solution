/*
	Problem: Ural1243
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100;

char s[100];
int res;

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		res = (res*10+s[i]-'0')%7;
	printf("%d\n", res);
	return 0;
}
