#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char* tram="tram";
const char* trol="trolleybus";

int cnttram, cnttrol, len;
char c;
char s[10001];

int main()
{
	while (~scanf("%c", &c))
	{
		if (c>'z' || c<'a')
		{
			s[len] = 0;
			cnttram += strcmp(s, tram)==0;
			cnttrol += strcmp(s, trol)==0;
			len = 0;
		}
		else
			s[len++] = c;
	}
	if (cnttram > cnttrol) puts("Tram driver");
	else if (cnttrol > cnttram) puts("Trolleybus driver");
	else puts("Bus driver");
	return 0;
}
