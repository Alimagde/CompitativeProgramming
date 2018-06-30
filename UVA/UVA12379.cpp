/*
 for every subtree find the shortest distance that go in and out in every child
 except one that go in and end in a leaf if that child subtree
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 10005;

vector<int> sz[N], memo[N], adj[N];

int getidx(vector<int> &vec, int v) {
	return lower_bound(vec.begin(), vec.end(), v) - vec.begin();
}

int getsz(int idx, int p) {
	if (~sz[idx][p])
		return sz[idx][p];

	int &res = sz[idx][p];
	res = 0;
	for (int i = 1; i < (int) adj[idx].size(); i++) {
		if (i == p)
			continue;
		int v = adj[idx][i];
		res += (1 + getsz(v, getidx(adj[v], idx)));
	}
	return res;
}

int solve(int idx, int p) {
	if (~memo[idx][p])
		return memo[idx][p];

	int &res = memo[idx][p], sub;
	res = 2 * getsz(idx, p);
	sub = res;

	for (int i = 1; i < (int) adj[idx].size(); i++) {
		if (i == p)
			continue;
		int v = adj[idx][i];
		res = min(res,
				sub - (2 * (getsz(v, getidx(adj[v], idx)) + 1))
						+ solve(v, getidx(adj[v], idx)) + 1);

	}

	return res;
}

int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);

		int m;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			sz[i].resize(m + 1);
			memo[i].resize(m + 1);
			adj[i].resize(m + 1);
			adj[i][0] = 0;
			sz[i][0] = -1;
			memo[i][0] = -1;
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &adj[i][j]);
				sz[i][j] = -1;
				memo[i][j] = -1;
			}
			sort(adj[i].begin(), adj[i].end());
		}
		int ans = 1e9;

		for (int i = 1; i <= n; ++i) {
			ans = min(ans, solve(i, 0));
		}
		printf("%d\n", ans);
	}
}
