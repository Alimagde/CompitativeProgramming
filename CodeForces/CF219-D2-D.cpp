/*
 first using dfs count the number of roads that must be inverted for every sub-tree then with another dfs keep track with
 the roads that is not in the sub-tree and must be inverted so the answer for every node is the roads in the sub-tree and
 the roads in the upper sub-tree
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int head[N], nxt[N * 2], to[N * 2], cost[N * 2], no = 0;

void addedge(int a, int b, int c) {
	nxt[no] = head[a];
	to[no] = b;
	cost[no] = c;
	head[a] = no++;
}

void addbiedge(int a, int b) {
	addedge(a, b, 0);
	addedge(b, a, 1);
}

int sz[N];

void getsz(int idx, int p) {
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;

		getsz(to[i], idx);
		sz[idx] += (cost[i] + sz[to[i]]);
	}

}
int n;
int ans[N];

void dfs(int idx, int p, int c) {
	int t = sz[idx];
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		dfs(to[i], idx, c + (t - sz[to[i]] - cost[i]) + (!cost[i]));
	}
	ans[idx] = (sz[idx] + c);

}

int main() {

	memset(head, -1, sizeof head);
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &x, &y);
		addbiedge(x, y);
	}
	getsz(1, -1);
	dfs(1, -1, 0);
	int mx = 1e9;
	for (int i = 1; i <= n; ++i) {
		mx = min(mx, ans[i]);
	}
	printf("%d\n", mx);
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == mx)
			printf("%d ", i);
	}
}
