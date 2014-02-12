#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

typedef long long ll;

const ll INF = 1ll<<62;
int N, M, d;
ll ans=0;
ll f[2][150003];
int a[303], b[303], t[303];

deque<int> q;

int main() {
    int i, j, k;
    cin>>N>>M>>d;
    for (i = 1; i <= M; ++i) {
        cin>>a[i]>>b[i]>>t[i];
        ans += b[i];
    }

    t[0] = t[1];
    int cur = 0;
    for (i = 1; i <= M; ++i) {
        cur ^= 1;
        for (j = 1; j <= N; ++j)
            f[cur][j] = INF;
        ll maxd = (ll)(t[i]-t[i-1])*d;
        q.clear();
        for (j = 1; j <= N; ++j) {
            while (!q.empty() && f[cur^1][j]<=f[cur^1][q.back()]) q.pop_back();
            q.push_back(j);
            while (!q.empty() && abs(j-q.front())>maxd) q.pop_front();
            f[cur][j] = min(f[cur][j], f[cur^1][q.front()]+abs(a[i]-j));
        }
        q.clear();
        for (j = N; j >= 1; --j) {
            while (!q.empty() && f[cur^1][j]<=f[cur^1][q.back()]) q.pop_back();
            q.push_back(j);
            while (!q.empty() && abs(j-q.front())>maxd) q.pop_front();
            f[cur][j] = min(f[cur][j], f[cur^1][q.front()]+abs(a[i]-j));
        }
    }
    ll mincost = INF;
    for (j = 1; j <= N; ++j)
        mincost = min(mincost, f[cur][j]);
    cout<<ans-mincost<<endl;
    return 0;
}
