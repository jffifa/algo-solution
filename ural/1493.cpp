/*
	Problem: Ural1493
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

int num, sum1, sum2;

void calc(int num, int &sum1, int &sum2)
{
	char s[8] = {0};
	for (int i = 0; i < 6; ++i)
	{
		s[i] = num%10;
		num /= 10;
	}
	sum1 = sum2 = 0;
	for (int i = 0; i < 3; ++i)
		sum1 += s[i];
	for (int i = 3; i < 6; ++i)
		sum2 += s[i];
}

char solve()
{
	if (num > 0)
	{
		calc(num-1, sum1, sum2);
		if (sum1==sum2) return 1;
	}
	if (num < 999999)
	{
		calc(num+1, sum1, sum2);
		if (sum1==sum2) return 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &num);
	if (solve())
		puts("Yes");
	else
		puts("No");
	return 0;
}
