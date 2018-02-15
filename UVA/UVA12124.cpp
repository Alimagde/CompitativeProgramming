/*
 binary search over the maximum valid quality
 */

#include <bits/stdc++.h>
using namespace std;

map<string, vector<pair<int, int> > > mp;
int n;
long long b;

bool valid(int mx) {
	long long c = 0;
	for (auto v : mp) {
		long long p = 1e9;
		for (auto x : v.second) {
			if (x.second >= mx) {
				p = min(p, 1ll * x.first);
			}
		}
		c += p;
	}
	return c <= b;
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {

		cin >> n >> b;
		int p, q;
		string t, na;
		mp.clear();
		for (int i = 0; i < n; ++i) {
			cin >> t >> na >> p >> q;
			mp[t].push_back(make_pair(p, q));
		}
		int s = 0, e = 1000000000;

		while (s < e) {
			int mid = s + (e - s + 1) / 2;
			if (valid(mid))
				s = mid;
			else
				e = mid - 1;

		}
		cout << s << "\n";
	}
}
