#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct snode
{
	char name[30];
	char orz;
	double t, f;
	void read()
	{
		int x;
		scanf("%s%d", name, &x); t += x*60; scanf("%c", &orz);
		scanf("%d", &x); t += x; scanf("%c", &orz);
		scanf("%d", &x); t += x/100.0;
	}
}node[200];
bool operator<(snode n1, snode n2)
{return n1.f<n2.f;}
int N;
vector<string> ans;

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		node[i].read();
		node[i].f = node[i].t+30*i;
	}
	/*
	for (i = 0; i < N; ++i)
		printf("%f\n", node[i].t);
	*/
	sort(node, node+N);
	double m = 999999;
	for (i = 0; i < N; ++i)
		if (node[i].t < m)
		{
			m = node[i].t;
			ans.push_back(string(node[i].name));
		}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
	return 0;
}