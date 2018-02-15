/*

 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[110];
int r[110];

int main() {

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", &arr[i].first, &arr[i].second, r + i);
		}
		printf("Case %d:\n", tc);
		int x, y;
		while (m--) {
			scanf("%d %d", &x, &y);
			bool a = 0;
			for (int i = 0; i < n; ++i) {
				int d = (arr[i].first - x) * (arr[i].first - x)
						+ (arr[i].second - y) * (arr[i].second - y);
				if (r[i] * r[i] >= d) {
					a = 1;
					break;
				}

			}
			if (a)
				puts("Yes");
			else
				puts("No");
		}
	}
}
