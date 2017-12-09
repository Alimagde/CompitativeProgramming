/*

 */

#include <bits/stdc++.h>
using namespace std;
char str[22];
const int N = 100005;
long long seg[4 * N];
long long lazy[4 * N];
int n, m;

long long update(int id, int s, int e, int f, int t) {
	if (f > e || s > t) {
		return seg[id] + (lazy[id] * (e - s + 1));
	}
	if (s == e) {
		seg[id] += (lazy[id] + 1);
		lazy[id] = 0;
		return seg[id];
	}
	if (s >= f && e <= t) {
		lazy[id]++;
		return seg[id] + (lazy[id] * (e - s + 1));
	}
	int mid = s + (e - s) / 2;
	lazy[id * 2] += lazy[id];
	lazy[id * 2 + 1] += lazy[id];
	lazy[id] = 0;
	return seg[id] = update(id * 2, s, mid, f, t)
			+ update(id * 2 + 1, mid + 1, e, f, t);
}

long long query(int id, int s, int e, int f, int t) {
	if (s > t || e < f)
		return 0;
	if (s == e) {
		seg[id] += lazy[id];
		lazy[id] = 0;
		return seg[id];
	}

	if (s >= f && e <= t) {
		return seg[id] + (lazy[id] * (e - s + 1));
	}
	int mid = s + (e - s) / 2;
	seg[id] += (lazy[id] * (e - s + 1));
	lazy[id * 2] += lazy[id];
	lazy[id * 2 + 1] += lazy[id];
	lazy[id] = 0;

	return query(id * 2, s, mid, f, t) + query(id * 2 + 1, mid + 1, e, f, t);

}

int main() {

	int z;
	scanf("%d", &z);

	for (int t = 1; t <= z; ++t) {
		scanf("%d %d", &n, &m);
		printf("Scenario #%d:\n", t);
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
		while (m--) {
			int x, y;
			scanf(" %s %d %d", str, &x, &y);
			--x;
			--y;
			if (str[0] == 'a')
				printf("%lld\n", query(1, 0, n - 1, x, y));
			else {
				puts("OK");
				update(1, 0, n - 1, x, y);
			}
		}
	}
}
