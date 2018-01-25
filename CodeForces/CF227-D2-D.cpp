#include <bits/stdc++.h>
using namespace std;

long long arr[100005];
int n;
long long ans[100005];

long long solve(long long x) {
	long long xx = x;
	long long v = 0;
	long long c = 1;
	long long e = n - 1;
	while (e > 0ll) {
		v += (arr[e] - arr[max(e - x, 0ll)]) * c;
		++c;
		e -= x;
		x = (x * xx);
	}
	return v;
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", arr + i);
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; ++i)
		arr[i] += arr[i - 1];

	int q;
	long long x;
	scanf("%d", &q);
	memset(ans, -1, sizeof ans);
	while (q--) {
		scanf("%lld", &x);
		if (ans[x] == -1)
			ans[x] = solve(x);

		printf("%lld ", ans[x]);
	}
}

