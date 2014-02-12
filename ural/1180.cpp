/*
	Problem: Ural1180
	Algorithm: Game
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

int r;
char str[255];

int main()
{
	scanf("%s", str);
	for (int i = 0; i < strlen(str); ++i)
		r += str[i]-'0';
	if (r%3)
		printf("1\n%d\n", r%3);
	else
		puts("2");
	return 0;
}
