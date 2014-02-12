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

int n;
double p1,p2,p3;
int main(){
    while (scanf("%d",&n)==1){
        scanf("%lf%lf",&p1,&p2);
        for (int i=1;i<=n;++i){
            scanf("%lf",&p3);
            printf("%.8f\n",(p1+p2+p3)/2);
        }
    }
    return 0;
}
