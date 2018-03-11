/*
 since the length of all segments <=1e5 we can give each point an id and BFS from start point to reach end point
 */
#include <bits/stdc++.h>
using namespace std;

int dist[100005];

int dx[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int dy[] = { 0, 0, 1, -1, -1, -1, 1, 1 };

int main() {
	int a, b, x, y;
	scanf("%d %d %d %d", &a, &b, &x, &y);
	int n;
	scanf("%d", &n);
	int r, f, t;
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &r, &f, &t);
		for (int c = f; c <= t; ++c) {
			mp[make_pair(r, c)];
		}
	}
	int id = 1;
	for (auto &x : mp) {
		x.second = id++;
	}
	memset(dist, 0x3f3f, sizeof dist);
	dist[mp[make_pair(a, b)]] = 0;

	deque<pair<int, int> > q;
	q.push_front(make_pair(a, b));
	int ans = -1;
	while (q.size()) {
		int xx = q[0].first, yy = q[0].second;
		q.pop_front();
		if (xx == x && yy == y) {
			ans = dist[mp[make_pair(xx, yy)]];
			break;
		}

		for (int i = 0; i < 8; ++i) {

			int nx = xx + dx[i], ny = yy + dy[i];
			int id = mp[make_pair(nx, ny)];

			if (id && dist[id] > 1 + dist[mp[make_pair(xx, yy)]]) {
				dist[id] = 1 + dist[mp[make_pair(xx, yy)]];
				q.push_back(make_pair(nx, ny));
			}

		}
	}
	printf("%d", ans);
}
