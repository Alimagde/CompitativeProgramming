#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long c;

long long sum(int x) {
	return (1ll * (x) * (x + 1)) / 2;
}

long long del(int a, int b) {
	return sum(a) + sum(b);
}

long long getdif(int r, int y, int x) {
	int v = x - 1;

	return sum(max(0, v - y));
}

bool valid(long long r) {
	long long all = 4ll * (sum(r - 1) + r) + 1;

	long long mxx = min(x + r, n + 0ll), mxy = min(n + 0ll, y + r);
	long long mnx = max(1ll, x - r), mny = max(1ll, y - r);

	int u, d, ll, rr;
	u = (y + r) - mxy;
	d = mny - (y - r);
	rr = (x + r) - mxx;
	ll = mnx - (x - r);

	all += (-(u + 2 * (sum(u - 1))) + getdif(r, mxy - y, ll));
	all += (-(d + 2 * (sum(d - 1))) + getdif(r, y - mny, rr));
	all += (-(ll + 2 * (sum(ll - 1))) + getdif(r, y - mny, ll));
	all += (-(rr + 2 * (sum(rr - 1))) + getdif(r, mxy - y, rr));

	return all >= c;
}

int main() {

	scanf("%d %d %d %lld", &n, &x, &y, &c);
	if (c == 1) {
		puts("0");
		return 0;
	}

	long long s = 1, e = n * 2ll;
	while (s < e) {
		long long mid = s + (e - s) / 2;
		if (valid(mid)) {
			e = mid;
		} else
			s = mid + 1;
	}
	printf("%lld", s);
}
