/*
 for every corner sum all it's neighbor corners , a corner with has exactly one bit different from every neighbor corner
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	while (~scanf("%d", &n)) {

		vector<int> vec(1 << n), ans(1 << n, 0);
		for (int i = 0; i < (1 << n); ++i) {
			scanf("%d", &vec[i]);
		}
		int an = 0;
		for (int i = 0; i < (1 << n); ++i) {

			for (int j = 0; j < n; ++j) {
				ans[i] += vec[i ^ (1 << j)];
			}
		}

		for (int i = 0; i < (1 << n); ++i) {

			for (int j = 0; j < n; ++j) {
				an = max(an, ans[i] + ans[i ^ (1 << j)]);
			}
		}
		printf("%d\n", an);

	}
}
