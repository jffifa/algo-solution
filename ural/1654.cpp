/*
	Problem: 1654
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100;

struct snode
{
	char c;
	snode *prev, *next;
	snode() {c = 0; prev = next = NULL;}
	void erase()
	{
		c = 0;
		if (prev) prev->next = next;
		if (next) next->prev = prev;
	}
}node[200002];

int N, M;
char s[200002];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		node[i].c = s[i];
		if (i) node[i].prev = &node[i-1];
		if (i<len-1) node[i].next = &node[i+1];
	}
	snode *it;
	for (it = node[0].next; it; )
	{
		if (it->prev && it->c==it->prev->c)
		{
			it->prev->erase();
			it->erase();
		}
		else
			it = it->next;
	}
	for (int i = 0; i < len; ++i)
		if (node[i].c) putchar(node[i].c);
	puts("");
	return 0;
}
