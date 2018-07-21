#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b, c;
		int n;
		scanf("%d %d %d %d", &a, &b, &c, &n);
		long long ans = 1;

		priority_queue<int> s1, s2;
		s1.push(1);
		for (int i = 2; i <= n; ++i) {
			int m = s1.top();
			int cur = (1ll * a * m) % mod;
			cur = (cur + 1ll * b * i) % mod;
			cur = (cur + c) % mod;
			ans += cur;

			if (cur > m)
				s2.push(-cur);
			else
				s1.push(cur);

			while (s1.size() > s2.size()) {
				m = s1.top();

				s2.push(-m);
				s1.pop();
			}

			while (s1.size() < s2.size()) {
				m = -s2.top();
				s1.push(m);
				s2.pop();
			}
		}
		printf("%lld\n", ans);
	}
}
