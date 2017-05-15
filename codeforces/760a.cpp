#include <iostream>
#include <algorithm>
using namespace std;

const int mdays[]= {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    int m, d;
    int ans=0;
    cin>>m>>d;
    ans++;
    int cnt = mdays[m-1];
    cnt -= (7-d+1);
    ans += cnt/7;
    if (cnt % 7 > 0) ans++;
    cout<<ans<<endl;
    return 0;
}
