/*
 Try to rotate every point and then check if the result points form a square
 */

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > point(4), re(4);
vector<pair<int, int> > vec(4);
int ans = 1e9;
bool isrec() {
	double d, x;
	double v1 = hypot(vec[0].first - vec[1].first,
			vec[0].second - vec[1].second);
	double v2 = hypot(vec[0].first - vec[2].first,
			vec[0].second - vec[2].second);
	double v3 = hypot(vec[0].first - vec[3].first,
			vec[0].second - vec[3].second);

	x = min(v1, min(v2, v3));
	d = max(v1, max(v2, v3));

	if (x == 0 || d == 0)
		return 0;
	for (int i = 1; i < 4; ++i) {
		vector<double> le;
		le.push_back(
				hypot(vec[i].first - vec[(i + 1) % 4].first,
						vec[i].second - vec[(i + 1) % 4].second));
		le.push_back(
				hypot(vec[i].first - vec[(i + 2) % 4].first,
						vec[i].second - vec[(i + 2) % 4].second));
		le.push_back(
				hypot(vec[i].first - vec[(i + 3) % 4].first,
						vec[i].second - vec[(i + 3) % 4].second));
		sort(le.begin(), le.end());
		if (x != le[0] || x != le[1] || d != le[2])
			return 0;
	}
	return 1;
}

void solve(int idx, int v) {
	if (idx == 4) {
		if (isrec())
			ans = min(ans, v);
		return;
	}
	pair<int, int> p, d;
	p = point[idx];
	d.first = p.first - re[idx].first;
	d.second = p.second - re[idx].second;
	vec[idx] = p;
	solve(idx + 1, v);
	int x = 1;
	while (x < 4) {
		swap(d.first, d.second);
		d.first = -d.first;
		p.first = d.first + re[idx].first;
		p.second = d.second + re[idx].second;
		vec[idx] = p;
		solve(idx + 1, v + x);
		++x;
	}
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < 4; ++j) {
			scanf("%d %d %d %d", &point[j].first, &point[j].second,
					&re[j].first, &re[j].second);
		}
		ans = 1e9;
		solve(0, 0);
		if (ans == 1e9)
			puts("-1");
		else
			printf("%d\n", ans);
	}
}
