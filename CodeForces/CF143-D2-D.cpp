/*
 put a soldiers on every row or column on even positions next one on odd positions put handle special case of one of them is 2
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	if ((n < 3 && m < 3) || (n == 1 || m == 1)) {
		printf("%d", n * m);
		return 0;
	}
	int ans = 0;
	if (n > m)
		swap(n, m);
	if (n == 2) {
		int v = m / 4;
		if (m % 4) {
			ans = (m % 4) * 2;
			ans = min(ans, 4);
		}
		ans += 4 * v;
	}

	int v = m / 2;

	int x = n / 2, y = n - x;
	ans = max(ans, (max(x, y) * max(v, m - v)) + (min(x, y) * min(v, m - v)));
	v = n / 2;
	x = m / 2;
	y = m - x;
	ans = max(ans, (max(x, y) * max(v, n - v)) + (min(x, y) * min(v, n - v)));
	printf("%d", ans);
}
