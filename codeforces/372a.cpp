#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, ans;
int s[555555];

int main() {
    int i, j, k;
    cin>>N;
    ans = N;
    for (i = 0; i < N; ++i)
        cin>>s[i];
    sort(s, s+N);
    /*
    for (i = 0; i < N; ++i)
        printf("%d ", s[i]);
    puts("");
    */
    for (i = 0, j = (N+1)/2; i < N; ++i) {
        if (s[i] == 0) continue;
        for (; j<N && s[j]<2*s[i]; ++j);
        if (j < N) {
            s[i] = s[j] = 0;
            ans--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
