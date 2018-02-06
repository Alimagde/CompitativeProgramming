/*
 for every pair of point count the number of points that not collinear with them
 */
#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[2002];
bool mp[505][505];

int main() {
	int n;
	scanf("%d", &n);
	int x, y;
	memset(mp, 0, sizeof mp);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		mp[x + 200][y + 200] = 1;
		arr[i] = make_pair(x, y);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {

			int dx = arr[i].first - arr[j].first;
			int dy = arr[i].second - arr[j].second;
			int v = __gcd(dx, dy);
			dx /= v;
			dy /= v;
			v = n - 1;
			pair<int, int> p = arr[i];
			p.first += dx;
			p.second += dy;
			while (max(abs(p.first), abs(p.second)) < 101) {
				v -= mp[p.first + 200][p.second + 200];
				p.first += dx;
				p.second += dy;
			}
			p = arr[i];
			p.first -= dx;
			p.second -= dy;
			while (abs(max(abs(p.first), abs(p.second))) < 101) {
				v -= mp[p.first + 200][p.second + 200];
				p.first -= dx;
				p.second -= dy;

			}
			ans += (1ll * v);
		}
	}
	printf("%lld", ans / 3);
	return 0;
}
