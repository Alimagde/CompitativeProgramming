#include <bits/stdc++.h>
using namespace std;
int n, k;
int memo[10005][22][22];
int vis[10005][22][22], vid;
int arr[10005];
int solve(int idx, int b, int a) {
	if (a + b > k)
		return 1e9;

	int v = (n - idx - 1) - b + a;
	if (v <= idx)
		return 0;

	int &res = memo[idx][b][a];
	if (vis[idx][b][a] == vid)
		return res;
	vis[idx][b][a] = vid;
	res = 1e9;

	if (arr[idx] == arr[v])
		res = min(res, solve(idx + 1, b, a));

	res = min(res, 1 + solve(idx, b + 1, a));
	res = min(res, 1 + solve(idx + 1, b, a + 1));
	return res;
}

int main() {

	int z;
	scanf("%d", &z);
	for (int tc = 1; tc <= z; ++tc) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}
		++vid;
		int ans = solve(0, 0, 0);
		printf("Case %d: ", tc);
		if (ans <= k && ans > 0) {
			printf("%d\n", ans);
		} else if (ans == 0) {
			puts("Too easy");
		} else {
			puts("Too difficult");
		}
	}
}
