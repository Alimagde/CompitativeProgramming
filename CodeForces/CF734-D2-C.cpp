/*
	try to take 0 or 1 from first type and then binary search for the best of the second type and minimize
	overall time
 */
#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
long long x, s;
long long mm[200005], kk[200005], mmc[200005], kkc[200005];
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	scanf("%lld %lld", &x, &s);
	for (int i = 0; i < m; ++i) {
		scanf("%lld", mm + i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%lld", mmc + i);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%lld", kk + i);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%lld", kkc + i);
	}

	long long ans = (x * n);
	int id = upper_bound(kkc, kkc + k, s) - kkc;
	--id;
	if(id>-1){
		ans=min(ans,x*(n-min(n,kk[id])));
	}
	for (int i = 0; i < m; ++i) {
		if (mmc[i] > s)
			continue;
		long long nn = n, ss = s - mmc[i];
		long long t = mm[i];
		int idx = upper_bound(kkc, kkc + k, ss) - kkc;
		--idx;
		if (idx >= 0) {

			nn -= min(nn, kk[idx]);
			ans = min(ans, nn * t);
		} else {
			ans = min(ans, n * t);
		}
	}
	printf("%lld", ans);
}
