#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int H, W, N;
int line, page;
char str[0xff];

int main()
{
	int i, j, k, now, len;
	scanf("%d%d%d", &H, &W, &N);
	line = 1;
	while (N--)
	{
		scanf("%s", str);
		len = strlen(str);
		//printf("%d\n", len);
		if (now+len > W)
		{
			++line;
			now = len+1;
		}
		else
			now += len+1;
	}
	//printf("%d\n", line);
	//page = (int)ceil(line*1.0/H);
	page = line/H;
	if (line-page*H) page++;
	printf("%d\n", page);
	return 0;
}
