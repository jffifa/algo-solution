#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<int> house[4];
char name[1111][222];
char h[20];

int main()
{
	int i, j, k;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; ++i)
	{
		gets(name[i]);
		gets(h);
		if (h[0] == 'S') house[0].push_back(i);
		else if (h[0] == 'H') house[1].push_back(i);
		else if (h[0] == 'G') house[2].push_back(i);
		else if (h[0] == 'R') house[3].push_back(i);
		else while(1) puts("orz");
	}
	puts("Slytherin:");
	for (i = 0; i < house[0].size(); ++i)
		puts(name[house[0][i]]);
	puts("");
	puts("Hufflepuff:");
	for (i = 0; i < house[1].size(); ++i)
		puts(name[house[1][i]]);
	puts("");
	puts("Gryffindor:");
	for (i = 0; i < house[2].size(); ++i)
		puts(name[house[2][i]]);
	puts("");
	puts("Ravenclaw:");
	for (i = 0; i < house[3].size(); ++i)
		puts(name[house[3][i]]);
	puts("");
	return 0;
}
