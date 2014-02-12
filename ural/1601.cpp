#include <cstdio>
#include <cstring>

bool st;
char ch;

void solve(char &ch)
{
	if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
		if (st)
		{
			if (ch>='a'&&ch<='z') ch -= 32;
			st = 0;
		}
		else
		{
			if (ch>='A'&&ch<='Z') ch += 32;
		}
	}
	else
	{
		if (ch=='.'||ch=='!'||ch=='?') st = 1;
	}
	putchar(ch);
}

int main()
{
	st = 1;
	while (~scanf("%c", &ch)) solve(ch);
	return 0;
}
