/*

 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1000004;
bool notp[N];

int seg[N];
int lazy[N];

void sieve() {
	for (int i = 2; i < 1000001; ++i) {
		if (notp[i])
			continue;
		for (int j = i * 2; j < 1000001; j += i)
			notp[j] = 1;
	}
}

int update(int id, int s, int e, int f, int t, int v) {
	if (t < s || f > e) {
		if (lazy[id] != -1) {
			seg[id] = (lazy[id] * (e - s + 1));
			lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
			lazy[id] = -1;
		}
		return seg[id];
	}
	if (s == e) {
		seg[id] = v;
		lazy[id] = -1;
		return seg[id];
	}
	if (s >= f && e <= t) {
		seg[id] = (v * (e - s + 1));
		lazy[id * 2] = lazy[id * 2 + 1] = v;
		lazy[id] = -1;
		return seg[id];
	}

	if (lazy[id] != -1) {
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
		lazy[id] = -1;
	}

	int mid = s + (e - s) / 2;

	return seg[id] = update(id * 2, s, mid, f, t, v)
			+ update(id * 2 + 1, mid + 1, e, f, t, v);
}

int query(int id, int s, int e, int f, int t) {
	if (f > e || t < s) {
		if (lazy[id] != -1) {
			lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
			seg[id] = (lazy[id] * (e - s + 1));
			lazy[id] = -1;
		}
		return 0;
	}

	if (s == e) {
		if (lazy[id] != -1) {
			seg[id] = lazy[id];
			lazy[id] = -1;
		}
		return seg[id];
	}

	if (s >= f && e <= t) {
		if (lazy[id] != -1) {
			lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
			seg[id] = (lazy[id] * (e - s + 1));
			lazy[id] = -1;
		}
		return seg[id];
	}

	if (lazy[id] != -1) {
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
		seg[id] = (lazy[id] * (e - s + 1));
		lazy[id] = -1;
	}
	int mid = s + (e - s) / 2;
	return query(id * 2, s, mid, f, t) + query(id * 2 + 1, mid + 1, e, f, t);
}

int main() {

	sieve();

	int z;
	scanf("%d", &z);

	for (int t = 1; t <= z; ++t) {
		int n, m;
		memset(lazy, -1, sizeof lazy);
		memset(seg, 0, sizeof seg);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			update(1, 0, n - 1, i, i, !notp[x]);
		}
		int x, y, q, v;
		printf("Case %d:\n\n", t);

		while (m--) {
			scanf("%d %d %d", &q, &x, &y);
			--x;
			--y;
			if (q) {
				printf("%d\n\n", query(1, 0, n - 1, x, y));
			} else {
				scanf("%d", &v);
				update(1, 0, n - 1, x, y, !notp[v]);
			}
		}
	}
}
