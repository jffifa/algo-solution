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

multiset<int> S;
int n,m;
int a[120000];
int b[120000];
bool bi[120000];

int main(){
    while (~scanf("%d%d",&n,&m)){
        S.clear();
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            S.insert(a[i]);
        }
        if (n==1){
            printf("1\n%d\n",a[1]);
            continue;
        }
        if (n==2){
            if (a[1]+a[2]>m)
                printf("2\n%d %d\n",a[1],a[2]);
            else
                printf("1\n%d %d\n",a[1],a[2]);
            continue;
        }
        memset(bi,true,sizeof(bi));
        sort(a+1,a+n+1);
        b[2]=a[n];
        multiset<int>::iterator it;
        /*
        it=S.lower_bound(b[2]);
        S.erase(it);

        it=S.upper_bound(m-b[2]);
        if (it==S.end()) --it;
        b[1]=(*it);
        S.erase(it);

        for (int i=2;i<n;++i){
            it=S.upper_bound(m-b[i]);
            if (it==S.end()) --it;
            b[i+1]=(*it);
            S.erase(it);
        }
        */
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            if (flag)
            {
                if (i<n)
                {
                    it=S.end();it--;
                    b[i+1]=(*it);
                    S.erase(it);
                    it=S.upper_bound(m-b[i+1]);
                    if (it==S.end()) it=S.begin();
                    b[i]=(*it);
                    S.erase(it);
                    i++;
                    if (b[i-1]+b[i]<=m)
                        flag=true;
                    else flag=false;
                }
                else
                {
                    it=S.begin();
                    b[i]=(*it);
                    S.erase(it);
                }
            }
            else
            {
                it=S.upper_bound(m-b[i-1]);
                if (it==S.end())
                {
                    it=S.begin();
                    flag=true;
                }
                else flag=false;
                b[i]=(*it);
                S.erase(it);
            }
        }
        int ans=0;
        b[n+1]=0;
        for (int i=1;i<=n;++i){
            if (b[i]+b[i+1]<=m) i++;
            ans++;
        }
        printf("%d\n",ans);
        for (int i=1;i<=n;++i) printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}
