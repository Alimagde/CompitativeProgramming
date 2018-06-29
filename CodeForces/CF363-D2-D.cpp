#include <bits/stdc++.h>
using namespace std;
vector<long long> b, c;
long long n, m, t;

bool can(int v) {
	long long i = n - v, j = 0;
	long long cost = 0;
	while (i < n) {
		cost += max(0ll, b[j] - c[i]);
		++i;
		++j;
	}
	
	return cost <= t;
}

int main() {
	
	scanf("%d %d %d", &n, &m, &t);
	c.resize(n);
	b.resize(m);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &c[i]);
	for (int i = 0; i < m; ++i)
		scanf("%lld", &b[i]);

	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int s = 0, e = min(n, m);

	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		if (can(mid)) {
			s = mid;
		} else
			e = mid - 1;
	}

	int i = n - s, j = 0;
	long long cp = 0;

	while (i < n) {
		int p = min(b[j], c[i]);
		cp += p;
		t -= (b[j] - p);
		++j;
		++i;
	}
	printf("%d %d", s, max(0ll, cp - t));

}
