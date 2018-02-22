/*
 */
#include <bits/stdc++.h>
using namespace std;

long long arr[55][5005];
long long pp[55], ps[55];
long long sum[55];

bool vis[55];
long long ans = -1e15;
void cnt(int i) {

	if (vis[i])
		return;
	vis[i] = 1;
	pp[i] = -1e9;
	long long v = 0;
	for (int j = 1; j <= arr[i][0]; ++j) {
		v += arr[i][j];
		pp[i] = max(pp[i], v);
	}
	v = 0;
	ps[i] = -1e9;
	for (int j = arr[i][0]; j > 0; --j) {
		v += arr[i][j];
		ps[i] = max(ps[i], v);
	}
	sum[i] = v;
	long long last = 0;

	for (int j = 1; j <= arr[i][0]; ++j) {
		ans = max(ans, last + arr[i][j]);
		last += arr[i][j];
		last = max(last, 0ll);
	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &arr[i][0]);
		for (int j = 1; j <= arr[i][0]; ++j) {
			scanf("%lld", &arr[i][j]);
		}
	}
	long long best = 0;
	int x;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &x);
		cnt(x);

		ans = max(ans, best + pp[x]);
		ans = max(ans, ps[x]);
		best = max(best + sum[x], ps[x]);
		best = max(best, 0ll);
	}
	printf("%lld", ans);
}
