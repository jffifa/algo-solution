#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int K;
int cnt[11];
char map[11][11];

int main() {
    int i, j, k;
    cin>>K;
    for (i = 0; i < 4; ++i)
        scanf("%s", map[i]);
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            if (map[i][j] != '.')
                cnt[map[i][j]-'0']++;
    for (i = 0; i < 10; ++i)
        if (cnt[i]>K*2) {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}
