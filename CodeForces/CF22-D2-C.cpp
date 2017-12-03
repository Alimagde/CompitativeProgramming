/*
	try to make node v as articulation point and loop over size of left and right components and check if node
	v will still articulation point

 */
#include <bits/stdc++.h>
using namespace std;
int pos[100005];
void pri(int a, int b, long long &k) {
	if (!k)
		return;
	for (int i = a; i < b; ++i) {
		for (int j = i + 2; j <= b; ++j) {
			printf("%d %d\n", pos[i], pos[j]);
			--k;
			if (!k)
				return;
		}
	}
}

int main() {

	long long n, m, v;
	scanf("%lld %lld %lld", &n, &m, &v);
	int ans = -1;
	for (long long i = 1; i <= (n - 1) / 2; ++i) {
		long long mx = (i * (i + 1)) / 2;
		mx += ((n - i) * (n - i - 1)) / 2;
		if (m >= n - 1 && m <= mx) {
			ans = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i)
		pos[i] = i;

	if (ans == -1)
		puts("-1");
	else {
	//	cout << ans << " <<\n";
		m = m - n + 1;
		swap(pos[v], pos[ans + 1]);

		for (int i = 1; i < n; ++i)
			printf("%d %d\n", pos[i], pos[i + 1]);
		pri(1, 1 + ans, m);
		pri(1 + ans, n, m);
	}
}
