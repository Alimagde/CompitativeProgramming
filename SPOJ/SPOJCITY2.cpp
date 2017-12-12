/*
 for every height find the last appearance of it and find the minimum height between them if less than the height
 then it can't be the same building and it will be a start of a new building else it will be the same one.
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int arr[N * 4];
int seg[N * 4];

int build(int id, int s, int e) {
	if (s == e) {
		seg[id] = arr[s];
		return seg[id];
	}
	int mid = s + (e - s) / 2;
	return seg[id] = min(build(id * 2, s, mid), build(id * 2 + 1, mid + 1, e));
}

int query(int id, int s, int e, int f, int t) {
	if (f > e || t < s)
		return 1e9 + 5;
	if (s == e) {
		return seg[id];
	}
	if (s >= f && e <= t)
		return seg[id];

	int mid = s + (e - s) / 2;

	return min(query(id * 2, s, mid, f, t), query(id * 2 + 1, mid + 1, e, f, t));

}

int main() {

	int n;
	int tc = 1;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; ++i)
			scanf("%d", arr + i);
		build(1, 1, n);
		map<int, int> mp;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int x = mp[arr[i]];
			if (arr[i] == 0)
				continue;
			if (x == 0) {
				++ans;
			} else {

				if (query(1, 1, n, mp[arr[i]], i) < arr[i]) {
					++ans;
				}
			}
			mp[arr[i]] = i;

		}
		printf("Case %d: %d\n", tc++, ans);
	}
}
