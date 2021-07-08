#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Segment;

int N;
Segment segs[111];
bool rem[111] = { false };

bool cover(Segment a, Segment b) {
	return a.first <= b.first && a.second >= b.second;
}

bool intersect(Segment a, Segment b) {
	return a.second > b.first;
}

bool cmp(Segment a, Segment b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main()
{
	while (~scanf("%d", &N)) {
		for (int i = 0; i < N; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x > y) swap(x, y);
			segs[i].first = x; segs[i].second = y;
		}

		sort(segs, segs + N, cmp);
		for (int i = 0; i < N - 1; ++i) {
			bool flag = false;
			for (int j = i + 1; j < N; ++j) {
				if (cover(segs[i], segs[j])) {
					flag = true;
					break;
				}
			}
			if (flag) {
				rem[i] = true;
			}
		}

		int M = 0;
		for (int i = 0; i < N; ++i) {
			if (!rem[i])
				segs[M++] = segs[i];
		}

		vector<Segment> ans;
		ans.push_back(segs[0]);
		for (int j = 1; j < M; ++j) {
			if (!intersect(ans.back(), segs[j])) {
				ans.push_back(segs[j]);
			}
		}

		printf("%d\n", ans.size());
		for (auto it = ans.begin(); it != ans.end(); ++it) {
			printf("%d %d\n", it->first, it->second);
		}
	}
}
