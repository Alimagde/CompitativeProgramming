/*
 for every target find the first hit that in the x segment of the target
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<pair<int, int> > arr[N * 3];
pair<int, int> target[N];
int n, m;
int ans[N];
int main() {
	memset(ans, 0x3f3f3f, sizeof ans);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &target[i].first, &target[i].second);
	}
	scanf("%d", &m);
	int x, y;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &x, &y);
		arr[x + N].push_back(make_pair(y, i));
	}

	for (int i = 0; i < n; ++i) {
		int s = target[i].first - target[i].second, e = target[i].first
				+ target[i].second;
		for (int j = s; j <= e; ++j) {
			for (auto p : arr[j + N]) {
				int x1 = target[i].first, y1 = 0, x2 = j, y2 = p.first;
				if (hypot(abs(x1 - x2), abs(y1 - y2))
						<= target[i].second * 1.0) {
					ans[i] = min(ans[i], p.second);
				}
			}
		}
	}
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (ans[i] <= m)
			++c;
		else
			ans[i] = -1;
	}
	printf("%d\n", c);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
}
