/*
 make leaf nodes with 3 values 0 or -1 or 1 and get segment product
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int seg[4 * N];
int arr[N];
int n, m;

string str = "-0+";

int build(int id, int s, int e) {
	if (s == e) {
		if (arr[s] < 0)
			seg[id] = -1;
		if (arr[s] > 0)
			seg[id] = 1;
		if (arr[s] == 0)
			seg[id] = 0;
		return seg[id];
	}
	int mid = s + (e - s) / 2;
	seg[id] = build(id * 2, s, mid) * build(id * 2 + 1, mid + 1, e);
	return seg[id];

}

int update(int id, int s, int e, int idx, int v) {
	if (idx < s || idx > e)
		return seg[id];
	if (s == e) {
		arr[s] = v;
		if (arr[s] < 0)
			seg[id] = -1;
		if (arr[s] > 0)
			seg[id] = 1;
		if (arr[s] == 0)
			seg[id] = 0;
		return seg[id];
	}
	int mid = s + (e - s) / 2;
	return seg[id] = update(id * 2, s, mid, idx, v)
			* update(id * 2 + 1, mid + 1, e, idx, v);
}

int query(int id, int s, int e, int f, int t) {
	if (s > t || e < f)
		return 1;
	if (s >= f && e <= t)
		return seg[id];
	int mid = s + (e - s) / 2;
	return query(id * 2, s, mid, f, t) * query(id * 2 + 1, mid + 1, e, f, t);
}

int main() {

	while (~scanf("%d %d", &n, &m)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}
		build(1, 0, n - 1);
		while (m--) {
			char t;
			int x, y;
			scanf(" %c %d %d", &t, &x, &y);
			if (t == 'C') {
				update(1, 0, n - 1, --x, y);
			} else
				printf("%c", str[query(1, 0, n - 1, --x, --y) + 1]);
		}
		puts("");
	}
}
