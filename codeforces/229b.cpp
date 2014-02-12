#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
struct Node
{
    map<int,int> hash;
    vector<int> rel,dis;
}P[111111];

int N, M;
int dis[111111];
queue<int> q;
bool inq[111111];

void spfa() {
	int i, j, k, u, v;
	for (u = 1; u <= N; ++u)
		dis[u] = 0x3fffffff;
	memset(inq, 0, sizeof inq);
	dis[1] = 0;
	q.push(1);
	inq[1] = 1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		inq[u] = 0;
		for (i = 0; i < P[u].rel.size(); ++i) {
			v = P[u].rel[i];
			int d = P[u].hash.find(dis[u])==P[u].hash.end()?dis[u]:P[u].hash[dis[u]];
			if (dis[v]>d+P[u].dis[i]) {
				dis[v] = d+P[u].dis[i];
				if (!inq[v]) {
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
}
int V[111111];
int main()
{
    int x, y, i, j, c;
    while (~scanf("%d%d",&N,&M))
    {
        for (i=1;i<=N;i++)
        {
            P[i].hash.clear();
            P[i].rel.clear();
            P[i].dis.clear();
        }
        for (i=0;i<M;i++)
        {
            scanf("%d%d%d",&x,&y,&c);
            P[x].rel.push_back(y);
            P[y].rel.push_back(x);
            P[x].dis.push_back(c);
            P[y].dis.push_back(c);
        }
        for (i=1;i<=N;i++)
        {
            scanf("%d",&x);
            for (j=0;j<x;j++)
                scanf("%d",&V[j]);
            if (x>0)
            {
                P[i].hash[V[x-1]]=V[x-1]+1;
                for (j=x-2;j>=0;j--)
                {
                    if (V[j]+1==V[j+1])
                        P[i].hash[V[j]]=P[i].hash[V[j+1]];
                    else P[i].hash[V[j]]=V[j]+1;
                }
            }
        }
        spfa();
		printf("%d\n", dis[N]<0x3fffffff?dis[N]:-1);
    }
}
