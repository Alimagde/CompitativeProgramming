#include <bits/stdc++.h>
using namespace std;
int n, l, k;

int pr[205];
int p[205];

double memo[205][205][405];
bool vis[205][205][405];

double solve(int idx, int w, int k) {

	if (idx == n) {
		if (w >= l && k >= 200)
			return 1;
		return 0;
	}

	double &res = memo[idx][w][k];
	if (vis[idx][w][k])
		return res;
	vis[idx][w][k] = 1;

	res = 0;

	if (p[idx] == -1) {
		res += (solve(idx + 1, w + 1, k - 1) * (pr[idx] / 100.0));
		res += (solve(idx + 1, w, k) * ((100 - pr[idx]) / 100.0));
	} else {
		res +=
				(solve(idx + 1, w + 1, min(400, k + p[idx])) * (pr[idx] / 100.0));
		res += (solve(idx + 1, w, k) * ((100 - pr[idx]) / 100.0));
	}
	return res;
}

int main() {
	

	scanf("%d %d %d", &n, &l, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", pr + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);

	printf("%.15lf", solve(0, 0, k + 200));

}
