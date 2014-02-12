#include <cstdio>
#include <cstring>

char str[111],ans[111];
int tmp[111];

int main()
{
	int i, j, k;
	scanf("%s", str);
	int len = strlen(str);
	for (i = 0; i < len; ++i)
		tmp[i] = str[i]-'a';
	for (i = 1; i < len; ++i)
		while (tmp[i]<tmp[i-1]) tmp[i]+=26;
	for (i = len-1; i > 0; --i)
		tmp[i] -= tmp[i-1];
	tmp[0] -= 5;
	if (tmp[0]<0) tmp[0]+=26;
	for (int i = 0; i < len; ++i)
		ans[i] = tmp[i]+'a';
	puts(ans);
}
