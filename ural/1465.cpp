/*
	Problem: Ural1465
	Algorithm: Seek patterns
	Time: O()
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

int N;

int main()
{
	scanf("%d", &N);
	if (N <= 34)
	{
		if (N==4 || N==8 || N==14 || N==20 || N==24 || N==28 || N==34) printf("Black\n");
		else printf("White\n");
	}
	else
	{
		if (N%34==20 || N%34==24 || N%34==28 || N%34==4 || N%34==8) printf("Black\n");
		else printf("White\n");
	}
	return 0;
}
