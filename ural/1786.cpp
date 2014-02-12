#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans = 0x3fffffff;
char s[300], pattern[7] = "Sandro";

inline int dis(char a, char b)
{
	if (a==b) return 0;
	if (a+32==b||b+32==a) return 1;
	if (a>='A'&&a<='Z'&&b>='A'&&b<='Z') return 1;
	if (a>='a'&&a<='z'&&b>='a'&&b<='z') return 1;
	return 2;
}

int diff(int st)
{
	int res = 0;
	for (int j = 0; j < 6; ++j)
		res += dis(s[st+j], pattern[j]);
	return res;
}

int main()
{
	scanf("%s", s);
	for (int i = 0; i <= strlen(s)-6; ++i)
	{
		//printf("%d\n", diff(i));
		ans = min(diff(i), ans);
	}
	printf("%d\n", ans*5);
	return 0;
}
