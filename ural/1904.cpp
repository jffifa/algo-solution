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
vector<int> Ans;
int V[20];
void DFS(int Now,int n)
{
    if (n==1)
    {
        Ans.push_back(Now+V[1]);
        Ans.push_back(V[1]-Now);
    }
    else
    {
        if (V[n]-Now>=0)
            DFS(V[n]-Now,n-1);
        if (Now+V[n]>=0)
            DFS(Now+V[n],n-1);
    }
}
int Lft[2020],Rgt[2020];
int main()
{
    int N,i,M,L;
    while (~scanf("%d",&N))
    {
        for (i=1;i<=N;i++)
            scanf("%d",&V[i]);
        Ans.clear();
        DFS(0,N);
        DFS(1,N);
        sort(Ans.begin(),Ans.end());
        L=Ans.size();
        if (L==0)
        {
            puts("0");
            continue;
        }
        M=1;
        for (i=1;i<L;i++)
        {
            if (Ans[M-1]!=Ans[i])
                Ans[M++]=Ans[i];
        }
        N=1;
        Lft[0]=Rgt[0]=Ans[0];
        for (i=1;i<M;i++)
        {
            if (Rgt[N-1]==Ans[i]-1)
                Rgt[N-1]=Ans[i];
            else
            {
                Lft[N]=Rgt[N]=Ans[i];
                N++;
            }
        }
        printf("%d\n",N);
        for (i=0;i<N;i++)
            printf("%d %d\n",Lft[i],Rgt[i]);
    }
}
