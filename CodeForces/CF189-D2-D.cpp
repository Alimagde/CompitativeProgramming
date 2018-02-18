/*
 first calculate the shortest distance for every pair using every car and get the save the shortest between cars
 the using dp get the best minimum distance to finish the race
 note:
 In the dp state any car can be chosen as in the dp there is a loop on the next node to change car in
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int dist[66][66][66];
int best[66][66];
void floyed(int c) {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[c][i][j] = min(dist[c][i][j],
						dist[c][i][k] + dist[c][k][j]);
			}
		}
	}
}

void getbest(int i, int j) {
	best[i][j] = 1e9;
	for (int c = 0; c < m; ++c) {
		best[i][j] = min(best[i][j], dist[c][i][j]);
	}
}

int memo[61][61][61];
bool vis[61][61][61];

int solve(int f, int t, int ch) {

	if (ch == 0) {
		return best[f][t];
	}
	if (f == t)
		return 0;
	if (vis[f][t][ch]) {
		return memo[f][t][ch];
	}
	vis[f][t][ch] = 1;
	int &r = memo[f][t][ch];
	r = 1e9;
	for (int i = 0; i < n; ++i) {
		r = min(r, solve(i, t, ch - 1) + best[f][i]);
	}
	return r;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int c = 0; c < m; ++c) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &dist[c][i][j]);
			}
		}
	}
	for (int i = 0; i < m; ++i)
		floyed(i);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			getbest(i, j);
		}
	}
	int x, y, v;

	while (q--) {
		scanf("%d %d %d", &x, &y, &v);
		printf("%d\n", solve(--x, --y, min(n, v)));
	}
}
