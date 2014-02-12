#include <cstdio>
#include <cstring>

int T;
int cnt[10];
char s[25];
char ans[7][5] = {"3241", "1324", "1234", "2341", "1243", "1342", "2134"};

int main()
{
	int i, j, k;
	scanf("%d", &T);
	while (T--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", s);
		for (i = 0; i < strlen(s); ++i)
			cnt[s[i]-'0']++;
		for (i = 1; i <= 4; ++i)
			cnt[i]--;
		bool zero = 1;
		for (i = 1; i <= 9; ++i)
			if (cnt[i]) zero = 0;
		if (zero)
		{
			printf("3241");
			for (i = 0; i < cnt[0]; ++i)
				putchar('0');
			puts("");
		}
		else
		{
			int r = 0;
			for (i = 9; i >= 0; --i)
				for (j = 0; j < cnt[i]; ++j)
				{
					printf("%d", i);
					r = (r*10+i)%7;
				}
			r = (r*10000)%7;
			puts(ans[(7-r)%7]);
		}
	}
	return 0;
}
