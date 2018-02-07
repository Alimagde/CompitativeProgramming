/*

 */
#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=1e15;

long long x1, x2, a1, a2;

vector<pair<long long, long long>> vec;

long long ternary(long long v1) {
	long long v2 = 0;
	for (auto x : vec) {
		long long d1 = (x1 - x.first) * (x1 - x.first)
				+ (a1 - x.second) * (a1 - x.second);
		long long d2 = (x2 - x.first) * (x2 - x.first)
				+ (a2 - x.second) * (a2 - x.second);
		if (d1 > v1)
			v2 = max(v2, d2);
	}
	ans = min(ans, v1 + v2);
	return v1 + v2;
}

int main() {

	scanf("%d %lld %lld %lld %lld", &n, &x1, &a1, &x2, &a2);
	vec.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &vec[i].first, &vec[i].second);
	}

	for (auto x : vec) {
		ternary(
				(x1 - x.first) * (x1 - x.first)
						+ (a1 - x.second) * (a1 - x.second));

	}
	ternary(0);
	printf("%lld", ans);
	return 0;
}
