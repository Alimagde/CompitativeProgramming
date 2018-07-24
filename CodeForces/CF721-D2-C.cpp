#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, t;
vector<pair<int, int> > adj[N];
int memo[N][N];

int solve(int idx, int v) {
	if (v < 0)
		return 1e-9;

	if (idx == 1) {
		if (v == 1)
			return memo[idx][v] = 0;;
		return memo[idx][v] = 1e9 + 5;
	}
	if (v < 2)
		return memo[idx][v] = 1e9 + 5;

	int &res = memo[idx][v];
	if (~res)
		return res;
	res = 1e9 + 5;

	for (auto x : adj[idx]) {
		res = min(res, solve(x.first, v - 1) + x.second);
	}
	return res;
}

vector<int> ans;

void build(int idx, int v) {
	if (idx == 1) {
		ans.push_back(idx);
		reverse(ans.begin(), ans.end());
		return;
	}
	int res = memo[idx][v];

	for (auto x : adj[idx]) {
		if ((res - x.second) == memo[x.first][v - 1]) {
			ans.push_back(idx);
			build(x.first, v - 1);
			return;
		}
	}
}

int main() {

	scanf("%d %d %d", &n, &m, &t);
	int x, y, v;

	while (m--) {
		scanf("%d %d %d", &x, &y, &v);
		adj[y].push_back(make_pair(x, v));
	}
	memset(memo, -1, sizeof memo);
	int mx = 0;
	for (int i = 2; i <= n; ++i) {
		int v = solve(n, i);
		if (v <= t)
			mx = i;
	}
	printf("%d\n", mx);
	build(n, mx);
	for (auto x : ans) {
		printf("%d ", x);
	}
}
