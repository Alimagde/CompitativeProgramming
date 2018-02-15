/*

 */

#include <bits/stdc++.h>
using namespace std;

long long r[1003], c[1003];
long long bestr[1000006], bestc[1000006];
int main() {

	int n, m, k, v;
	scanf("%d %d %d %d", &n, &m, &k, &v);
	int x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &x);
			r[i] += x;
			c[j] += x;
		}
	}

	priority_queue<long long> rr, cc;
	for (int i = 0; i < n; ++i) {
		rr.push(r[i]);
	}
	for (int i = 0; i < m; ++i) {
		cc.push(c[i]);
	}
	for (int i = 1; i <= k; ++i) {
		bestc[i] = cc.top() + bestc[i - 1];
		bestr[i] = rr.top() + bestr[i - 1];
		long long x = cc.top();
		cc.pop();
		cc.push(x - (n * v));
		x = rr.top();
		rr.pop();
		rr.push(x - (m * v));
	}
	long long ans = -1e18;
	for (int i = 0; i <= k; ++i) {
		ans = max(ans,
				bestr[i] + bestc[k - i]
						- (min(i, k - i) * 1ll * v * max(i, k - i)));

	}
	printf("%lld", ans);
}
