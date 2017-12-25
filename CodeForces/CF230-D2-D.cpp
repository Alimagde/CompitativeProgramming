/*
 get the shortest time to get to node n by Dijkstra algorithm ,the time taken to node x is the lowest
 second that no traveler will arrive in it except for node n
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
long long dist[N];

int head[N], nxt[N * 2], to[N * 2], no = 0;
long long cost[N * 2];
void addedge(int a, int b, long long c) {
	nxt[no] = head[a];
	to[no] = b;
	cost[no] = c;
	head[a] = no++;
}

void addbiedge(int a, int b, long long c) {
	addedge(a, b, c);
	addedge(b, a, c);
}

vector<long long> times[N];

void init() {
	for (int i = 0; i < N; ++i)
		dist[i] = 1e16;
	memset(head, -1, sizeof head);
}

long long getdist(int i, long long t) {
	int s = 0, e = times[i].size();
	--e;
	s = lower_bound(times[i].begin(), times[i].end(), t) - times[i].begin();
	if (times[i][s] > t)
		return t;
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		if (times[i][mid] - times[i][s] > mid - s) {
			e = mid - 1;
		} else
			s = mid;
	}
	return times[i][s] + 1;
}

int main() {

	init();
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	long long c;
	while (m--) {
		scanf("%d %d %lld", &a, &b, &c);
		addbiedge(a, b, c);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		times[i].resize(x);
		for (int j = 0; j < x; ++j) {
			scanf("%lld", &times[i][j]);
		}
		times[i].push_back(1000000000000000ll);
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int> >,
			greater<pair<long long, int> > > q;

	q.push(make_pair(getdist(1, 0ll), 1));

	while (q.size()) {
		long long t = q.top().first;
		int idx = q.top().second;
		q.pop();
		if (idx == n) {
			printf("%lld", t);
			return 0;
		}

		if (dist[idx] < t)
			continue;

		for (int i = head[idx]; ~i; i = nxt[i]) {
			int nx = to[i];
			long long nt;
			if (nx == n)
				nt = t + cost[i];
			else
				nt = getdist(nx, t + cost[i]);
			if (nt < dist[nx]) {
				dist[nx] = nt;
				q.push(make_pair(nt, nx));
			}
		}
	}
	puts("-1");
}
