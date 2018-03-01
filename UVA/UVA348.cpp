#include <bits/stdc++.h>
using namespace std;

long long memo[15][15];
int vis[15][15], vid = 0;
int best[15][15];
long long r[15];
long long c[15];

long long solve(int s, int e) {
	if (s == e)
		return 0;

	long long &res = memo[s][e];
	if (vis[s][e] == vid)
		return res;
	res = 1e18;

	for (int i = s; i < e; ++i) {
		long long v = solve(s, i) + solve(i + 1, e) + (r[s] * c[e] * c[i]);
		if (v < res) {
			res = v;
			best[s][e] = i;
		}
	}
	return res;
}

void print(int s, int e) {
	if (s == e) {
		printf("A%d", s);
		return;
	}
	int b = best[s][e];
	printf("(");
	print(s, b);
	printf(" x ");
	print(b + 1, e);
	printf(")");

}

int main() {
//	freopen("in.txt", "rt", stdin);
	int n;
	int tc = 1;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; ++i) {
			scanf("%lld %lld", r + i, c + i);
		}
		++vid;
		solve(1, n);
		printf("Case %d: ", tc++);
		print(1, n);
		puts("");
	}
}

