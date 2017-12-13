/*
 for every index binary search over the maximum consecutive robots can be destroyed by getting the sum of maximum
 between them in every weapon and compare the sum with k
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct seg_tree {
	int seg[4 * N];

	int update(int id, int s, int e, int idx, int v) {
		if (idx < s || idx > e)
			return seg[id];
		if (s == e) {
			return seg[id] = v;
		}
		int mid = s + (e - s) / 2;
		return seg[id] = max(update(id * 2, s, mid, idx, v),
				update(id * 2 + 1, mid + 1, e, idx, v));
	}

	int query(int id, int s, int e, int f, int t) {
		if (f > e || t < s)
			return -1e9;
		if (s == e || (s >= f && e <= t))
			return seg[id];
		int mid = s + (e - s) / 2;

		return max(query(id * 2, s, mid, f, t),
				query(id * 2 + 1, mid + 1, e, f, t));

	}

} seg[6];

vector<int> ans;
vector<int> cur;

int main() {

	int n, m, k, x;

	scanf("%d %d %d", &n, &m, &k);
	cur.resize(m);
	ans.resize(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &x);
			seg[j].update(1, 0, n - 1, i, x);
		}
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int s = i - 1, e = n - 1;
		while (s < e) {
			int mid = (s + (e - s + 1) / 2);
			int c = 0;
			for (int j = 0; j < m; ++j) {
				cur[j] = seg[j].query(1, 0, n - 1, i, mid);
				c += cur[j];
			}
			if (c <= k)
				s = mid;
			else
				e = mid - 1;
		}
		if (s - i + 1 > mx) {
			mx = s - i + 1;
			for (int j = 0; j < m; ++j) {
				ans[j] = seg[j].query(1, 0, n - 1, i, s);
			}
		}
	}
	for (int i = 0; i < m; ++i)
		printf("%d ", ans[i]);
}
