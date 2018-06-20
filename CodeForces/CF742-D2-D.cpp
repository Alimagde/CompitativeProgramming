/*
 first divide the Hoses to groups let them be A groups for every group save the group
 members ,sum of weights and sum of beauties , then then the problem can be mapped to
 knapsack problem.

 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int par[N];
void init(int n) {
	for (int i = 1; i <= n; ++i)
		par[i] = i;
}

int getpar(int x) {
	if (par[x] == x)
		return x;
	return par[x] = getpar(par[x]);
}

void merge(int a, int b) {
	if (getpar(a) == getpar(b))
		return;

	par[par[a]] = par[b];
}

struct g {
	vector<int> m;
	int sw, sb;
} g[N];

int W[N], B[N];

vector<int> gr;
int memo[N][N];

int solve(int idx, int w) {
	if (w < 0)
		return -1e9;
	if (idx == (int) gr.size())
		return 0;

	int &r = memo[idx][w];
	if (~r)
		return r;
	r = 0;
	int id = gr[idx];
	r = max(r, solve(idx + 1, w - g[id].sw) + g[id].sb);

	for (auto x : g[id].m) {
		r = max(r, solve(idx + 1, w - W[x]) + B[x]);
	}
	r = max(r, solve(idx + 1, w));
	return r;
}

int main() {

	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);
	init(n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", W + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", B + i);
	}

	int a, b;
	while (m--) {
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	set<int> gp;
	for (int i = 1; i <= n; ++i) {
		int id = getpar(i);
		g[id].m.push_back(i);
		g[id].sw += W[i];
		g[id].sb += B[i];
		gp.insert(id);
	}
	for (auto x : gp) {
		gr.push_back(x);
	}
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, w));
}
