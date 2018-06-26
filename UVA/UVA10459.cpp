/*
 for every node i find the depth of the tree and memorize the depth given node and parent
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int head[N], nxt[N * 2], to[N * 2], no = 0;

int d[N][N];
int vis[N][N], vid = 0;

void addedge(int a, int b) {
	nxt[no] = head[a];
	to[no] = b;
	head[a] = no++;
}

void init(int n) {
	no = 0;
	++vid;
}

int dfs(int idx, int p) {
	if (vis[idx][p] == vid)
		return d[idx][p];
	vis[idx][p] = vid;
	int &v = d[idx][p];
	v = 0;
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		v = max(v, 1 + dfs(to[i], idx));
	}
	return v;
}

int main() {

	int n;
	while (~scanf("%d", &n)) {
		init(n);
		for (int i = 1; i <= n; ++i) {
			head[i] = -1;
			int m, x;
			scanf("%d", &m);
			while (m--) {
				scanf("%d", &x);
				addedge(i, x);
			}
		}
		int mn = 1e9, mx = 0;
		for (int i = 1; i <= n; ++i) {
			int v = dfs(i, 0);
			mx = max(mx, v);
			mn = min(mn, v);
		}
		printf("Best Roots  :");
		for (int i = 1; i <= n; ++i) {
			if (d[i][0] == mn)
				printf(" %d", i);
		}
		puts("");
		printf("Worst Roots :");
		for (int i = 1; i <= n; ++i) {
			if (d[i][0] == mx)
				printf(" %d", i);
		}
		puts("");
	}
}
