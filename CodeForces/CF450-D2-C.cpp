/*

 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	if (n < m)
		swap(n, m);
	if (n + m - 2 < k)
		puts("-1");
	else {
		long long ans = 1;
		if (k < n) {
			ans = max(ans, (n / (k + 1)) * m);
			ans = max(ans, (m / (k + 1)) * n);
		} else if (k < m) {
			ans = max(ans, (m / (k + 1)) * n);
		} else {
			ans = max(ans, (m / (k + 2 - n)));
			ans = max(ans, (n / (k + 2 - m)));
		}
		printf("%lld", ans);
	}

}
