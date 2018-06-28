/*
 for every suffix calculate the time to watch all the photos so for every prefix we have 2 cases

 1 - watch the prefix then watch the suffix.
 2 - watch the suffix then watch the prefix.

 given the time available to the suffix using binary search the best suffix that fit in time
 can be found.
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long cost[N];
char str[N];
long long n, a, b, t;
int bs(int s, int e, long long v) {
	if (v <= 0 || s > e)
		return 0;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (cost[mid] > v)
			s = mid + 1;
		else
			e = mid;
	}
	return n - s;
}

int bs2(int s, int e, long long v) {
	if (v <= 0 || s > e)
		return 0;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (cost[mid] + ((n - mid) * a) > v)
			s = mid + 1;
		else
			e = mid;
	}
	return n - s;
}

int main() {

	scanf("%lld %lld %lld %lld", &n, &a, &b, &t);
	scanf(" %s", str);
	int v;
	for (int i = n - 1; i >= 0; --i) {
		v = a + 1;
		if (str[i] == 'w')
			v += b;
		cost[i] = (v + cost[i + 1]);
	}

	int ans = 0;
	v = -a;
	for (int i = 0; i < n; ++i) {
		v += a;
		if (str[i] == 'w')
			v += b;
		v++;
		if (v > t)
			break;

		ans = max(ans, (i + 1) + bs(i + 1, n, 0ll + t - (0ll + v + (i * a))));
		ans = max(ans, (i + 1) + bs2(i + 1, n, t - v));

	}
	printf("%d", ans);
}
