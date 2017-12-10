/*

 */
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> seg[4 * N];

vector<int> em(0);

vector<int> query(int id, int s, int e, int f, int t) {
	if (f > e || t < s) {
		return em;
	}
	if (s == e) {
		return seg[id];
	}
	if (s >= f && e <= t) {
		return seg[id];
	}
	int mid = s + (e - s) / 2;
	vector<int> l = query(id * 2, s, mid, f, t);
	vector<int> r = query(id * 2 + 1, mid + 1, e, f, t);

	if (l.empty())
		return r;
	if (r.empty())
		return l;

	vector<int> all;
	for (auto x : r)
		all.push_back(x);
	for (auto x : l)
		all.push_back(x);
	sort(all.rbegin(), all.rend());
	vector<int> ans;
	for (int i = 0; i < 2 && i < (int) all.size(); ++i)
		ans.push_back(all[i]);
	return ans;
}

vector<int> update(int id, int s, int e, int idx, int v) {
	if (idx < s || idx > e) {
		return seg[id];
	}
	if (s == e) {
		seg[id].resize(0);
		seg[id].push_back(v);
		return seg[id];
	}

	int mid = s + (e - s) / 2;
	vector<int> l = update(id * 2, s, mid, idx, v);
	vector<int> r = update(id * 2 + 1, mid + 1, e, idx, v);

	vector<int> all;
	for (auto x : r)
		all.push_back(x);
	for (auto x : l)
		all.push_back(x);
	sort(all.rbegin(), all.rend());
	vector<int> ans;
	for (int i = 0; i < 2 && i < (int) all.size(); ++i)
		ans.push_back(all[i]);
	seg[id]=ans;
	return seg[id];
}

int main() {
	int n;
	scanf("%d", &n);
	int x, y;
	char t;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		update(1, 0, n - 1, i, x);
	}
	int m;
	scanf("%d", &m);

	while (m--) {
		scanf(" %c %d %d", &t, &x, &y);
		if (t == 'Q') {
			vector<int> ans = query(1, 0, n - 1, --x, --y);
			printf("%d\n", ans[0] + ans[1]);
		} else {
			update(1, 0, n - 1, --x, y);
		}
	}
}
