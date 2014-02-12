/*
	Problem: Ural1038
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxLen = 99999;

char Ch;
char Str[MaxLen], Word[MaxLen];
int Ans, Len, WLen, WCnt;

inline bool ChCheck(char c)
{return (c>=65 && c<=90) || (c>=97 && c<=122);}

inline bool UCase(char c)
{return c>=65 && c<=90;}

inline bool LCase(char c)
{return c>=97 && c<=122;}

int main()
{
	//freopen("spell.in", "r", stdin);
	while (~scanf("%c", &Ch))
	{
		WCnt = Len = 0;
		Str[Len++] = Ch;
		while (!(Ch=='.'||Ch=='?'||Ch=='!')&&(~scanf("%c", &Ch))) Str[Len++] = Ch;
		Str[Len++] = '#';
		int i = 0;
		while (i < Len)
		{
			while (i < Len && !ChCheck(Str[i])) ++i;
			if (i >= Len) break;
			WLen = 0; ++WCnt;
			while (i < Len && ChCheck(Str[i])) Word[WLen++] = Str[i++];
			if (WCnt == 1 && LCase(Word[0])) ++Ans;
			for (int j = 1; j < WLen; ++j)
				if (UCase(Word[j])) ++Ans;
		}
	}
	printf("%d\n", Ans);
	return 0;
}
