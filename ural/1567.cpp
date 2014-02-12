#include <iostream>
#include <cstdio>
#include <cstring>

int ans;
char str[1111];

int hmr[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2};

int calc(char ch)
{
	//putchar(ch); putchar('#');
	if (ch>='a' && ch<='z') return hmr[ch-'a'];
	if (ch=='.'||ch==' ') return 1;
	if (ch==',') return 2;
	if (ch=='!') return 3;
}

int main()
{
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
		ans += calc(str[i]);
	printf("%d\n", ans);
	return 0;
}
