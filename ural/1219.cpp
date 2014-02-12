#include <cstdio>
#include <cstring>

char ch[3];
char str[1000006];

int main()
{
	for (int i = 0; i < 333334; ++i)
	{
		ch[2] = i%26;
		ch[1] = (i/26)%26;
		ch[0] = (i/26/26)%26;
		for (int j = 0; j < 3; ++j)
			str[i*3+j] = ch[j]+'a';
	}
	for (int i = 0; i < 1000000; ++i)
		putchar(str[i]);
	puts("");
	return 0;
}
