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

const int N = 600;
int a[N][N],sum[N][N],Ans[N];
int f[N][N],g[N][N],cost[N][N];
int n,m,d;

int main(){
    while (scanf("%d%d",&n,&m)==2){
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j){
                scanf("%d",&a[i][j]);
                sum[j][i]=a[i][j];
            }
        for (int i=1;i<=n;++i)
            for (int j=1;j<=i;++j)
                sum[i][j]+=sum[i][j-1];
        memset(cost,0,sizeof(cost));
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
                cost[i][j]=cost[i][j-1]+sum[j][j]-sum[j][i-1];
		/*
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j)
                printf("%d ",cost[i][j]);
            puts("");
        }
        */
        memset(f,0,sizeof(f));
        memset(g,-1,sizeof(g));
        for (int k=1;k<=m;++k)
            for (int i=n;i>=1;--i)
                for (int j=i+1;j<=n;++j)
                    if (f[i][k]<f[j][k-1]+cost[1][j]-cost[1][i]-cost[i+1][j]){
                        f[i][k]=f[j][k-1]+cost[1][j]-cost[1][i]-cost[i+1][j];
                        g[i][k]=j;
                    }
        int ans=0;
        for (int i=1;i<=n;++i)
            if (f[ans][m]<f[i][m]) ans=i;
        printf("%d\n",f[ans][m]);
        for (int i=m;i>=1;--i){
            Ans[i]=ans;
            ans=g[ans][i];
        }
        sort(Ans+1,Ans+m+1);
        for (int i=1;i<=m;++i)
            printf("%d%c",Ans[i],i==m?'\n':' ');
    }
    return 0;
}
