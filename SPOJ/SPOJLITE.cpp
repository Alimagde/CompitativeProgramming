/*

 */
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int seg[N * 4], lazy[N * 4];

int update(int id, int s, int e, int f, int t) {
	if (t < s || e < f) {
		if (lazy[id]) {
			seg[id] = (e - s + 1) - seg[id];
			lazy[id * 2] ^= 1;
			lazy[id * 2 + 1] ^= 1;
			lazy[id] = 0;
		}
		return seg[id];
	}
	if (s == e) {
		lazy[id] ^= 1;
		if (lazy[id]) {
			seg[id] ^= 1;
			lazy[id] = 0;
		}
		return seg[id];
	}
	if (s >= f && e <= t) {
		lazy[id] ^= 1;
		if (lazy[id]) {
			lazy[id] = 0;
			lazy[id * 2] ^= 1;
			lazy[id * 2 + 1] ^= 1;
			seg[id] = (e - s + 1) - seg[id];
		}
		return seg[id];
	}
	if (lazy[id]) {
		lazy[id * 2] ^= 1;
		lazy[id * 2 + 1] ^= 1;
		lazy[id] = 0;
	}
	int mid = s + (e - s) / 2;
	return seg[id] = update(id * 2, s, mid, f, t)
			+ update(id * 2 + 1, mid + 1, e, f, t);
}

int query(int id, int s, int e, int f, int t) {
	if (t < s || f > e) {
		if (lazy[id]) {
			seg[id] = (e - s + 1) - seg[id];
			lazy[id * 2] ^= 1;
			lazy[id * 2 + 1] ^= 1;
			lazy[id] = 0;
		}
		return 0;
	}
	if (s == e) {
		if (lazy[id]) {
			seg[id] ^= 1;
			lazy[id] = 0;
		}
		return seg[id];
	}

	if (s >= f && e <= t) {
		if (lazy[id]) {
			lazy[id] = 0;
			lazy[id * 2] ^= 1;
			lazy[id * 2 + 1] ^= 1;
			seg[id] = (e - s + 1) - seg[id];
		}
		return seg[id];
	}

	if (lazy[id]) {
		lazy[id] = 0;
		lazy[id * 2] ^= 1;
		lazy[id * 2 + 1] ^= 1;
		seg[id] = (e - s + 1) - seg[id];
	}
	int mid = s + (e - s) / 2;

	return query(id * 2, s, mid, f, t) + query(id * 2 + 1, mid + 1, e, f, t);

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	int t, x, y;
	while (m--) {
		scanf("%d %d %d", &t, &x, &y);
		--x;
		--y;
		if (t) {
			printf("%d\n", query(1, 0, n - 1, x, y));

		} else {
			update(1, 0, n - 1, x, y);
		}
	}
}
