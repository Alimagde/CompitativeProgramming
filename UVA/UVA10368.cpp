/*

 */
#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp, vis;

bool canwin(int x, int y) {
	if (x == 0)
		return 0;
	int v = y / x;
	if (vis[make_pair(x, y)]++)
		return mp[make_pair(x, y)];
	if (v > 1) {
		return mp[make_pair(x, y)] = int(
				(!canwin(y % x, x)) || (!canwin(x, x + (y % x))));
	} else
		return mp[make_pair(x, y)] = int(!canwin(y % x, x));

}

int main() {

	int n, m;
	while (scanf("%d %d", &n, &m), n | m) {
		if (n > m)
			swap(n, m);

		if (canwin(n, m))
			puts("Stan wins");
		else
			puts("Ollie wins");

	}
}
