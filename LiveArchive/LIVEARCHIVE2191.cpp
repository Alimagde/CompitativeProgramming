/*

 */

#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int seg[4 * N];
int arr[N];
int n;

char str[5];

int build(int id, int s, int e) {
	if (s == e)
		return seg[id] = arr[s];
	int mid = s + (e - s) / 2;
	return seg[id] = build(id * 2, s, mid) + build(id * 2 + 1, mid + 1, e);
}

int update(int id, int s, int e, int idx, int v) {
	if (idx < s || idx > e)
		return seg[id];
	if (s == e) {
		return seg[id] = v;
	}
	int mid = s + (e - s) / 2;
	return seg[id] = update(id * 2, s, mid, idx, v)
			+ update(id * 2 + 1, mid + 1, e, idx, v);
}

int query(int id, int s, int e, int f, int t) {
	if (f > e || t < s)
		return 0;
	if (s >= f && e <= t)
		return seg[id];
	int mid = (s + (e - s) / 2);
	return query(id * 2, s, mid, f, t) + query(id * 2 + 1, mid + 1, e, f, t);
}

int main() {

	int tc = 1;
	while (scanf("%d", &n), n) {

		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}
		if (tc > 1)
			puts("");
		printf("Case %d:\n", tc++);
		build(1, 0, n - 1);

		while (scanf(" %s", str), str[0] != 'E') {
			int x, y;
			scanf("%d %d", &x, &y);
			if (str[0] == 'M') {
				printf("%d\n", query(1, 0, n - 1, --x, --y));
			} else {
				update(1, 0, n - 1, --x, y);
			}

		}
	}
}
