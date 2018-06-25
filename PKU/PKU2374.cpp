/*
 for every end point on every segment find the first fence that will be hit if we go down from
 this point, that can be done using segment tree.

 finding the shortest path can be done using dynamic programming.
 */
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200005;

int seg[4 * N], lazy[4 * N];

void push_down(int id, int s, int e) {
	if (!lazy[id])
		return;

	seg[id] = lazy[id];
	if (s != e) {
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
	}
	lazy[id] = 0;
}

void update(int id, int s, int e, int f, int t, int v) {
	push_down(id, s, e);
	if (e < f || s > t)
		return;
	if (s >= f && e <= t) {
		lazy[id] = v;
		push_down(id, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(id * 2, s, mid, f, t, v);
	update(id * 2 + 1, mid + 1, e, f, t, v);
}

int query(int id, int s, int e, int idx) {
	push_down(id, s, e);
	if (s == e)
		return seg[id];
	int mid = s + (e - s) / 2;
	if (idx <= mid)
		return query(id * 2, s, mid, idx);

	return query(id * 2 + 1, mid + 1, e, idx);
}
const int M = 50005;
int nxt[M][3];
int s[M][3];
long long memo[M][3];

long long solve(int idx, bool st) {
	long long &res = memo[idx][st];
	if (~res)
		return res;
	res = 1e11;
	int nx = nxt[idx][st];
	if (!nx) {
		res = abs(s[idx][st]);
	} else {
		res = min(res, abs(s[idx][st] - s[nx][0]) + solve(nx, 0));
		res = min(res, abs(s[idx][st] - s[nx][1]) + solve(nx, 1));
	}
	return res;
}
int main() {

	int n, st;
	scanf("%d %d", &n, &st);
	int x, y;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &x, &y);
		nxt[i][0] = query(1, 0, 200000, x + 100000);
		nxt[i][1] = query(1, 0, 200000, y + 100000);
		update(1, 0, 200000, x + 100000, y + 100000, i);
		s[i][0] = x;
		s[i][1] = y;
	}
	memset(memo, -1, sizeof memo);

	printf("%lld",
			min(abs(st - s[n][0]) + solve(n, 0),
					abs(st - s[n][1]) + solve(n, 1)));
}
