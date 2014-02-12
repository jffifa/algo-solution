#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int cnt[3], m;
char s[100];

int main()
{
	scanf("%d", &N);
	getchar();
	while (N--)
	{
		gets(s);
		if (s[0]=='E') ++cnt[0];
		if (s[0]=='L') ++cnt[1];
		if (s[0]=='M') ++cnt[2];
	}
	m = 0; 
	for (int i = 0; i < 3; ++i) m = max(m, cnt[i]);
	if (m==cnt[0]) puts("Emperor Penguin");
	if (m==cnt[1]) puts("Little Penguin");
	if (m==cnt[2]) puts("Macaroni Penguin");
	return 0;
}
