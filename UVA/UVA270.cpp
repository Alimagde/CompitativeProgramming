/*
 	 many TLE because of the input structure
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

	int tc;
	scanf("%d", &tc);

	string line;
	getline(cin, line);
	getline(cin, line);

	while (tc--) {

		vector<pair<int, int>> vec;
		int x, y;
		while (getline(cin, line)) {
			if (line == "")
				break;
			sscanf(line.c_str(), "%d %d", &x, &y);
			vec.push_back(make_pair(x,y));
		}
		int n = vec.size();

		int ans = 2;

		for (int i = 0; i < n; ++i) {
			map<pair<int, int>, int> mp;
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				int a = vec[j].first - vec[i].first, b = vec[j].second
						- vec[i].second;
				int g = __gcd(abs(a), abs(b));

				if (g != 0) {
					a /= g;
					b /= g;
				} else {
					if (a == 0)
						b = 1;
					else
						a = 1;
				}
				mp[make_pair(a, b)]++;
				mp[make_pair(-a, -b)]++;
			}
			int c = 1;
			for (auto z : mp) {
				c = max(c, 1 + z.second);
			}
			ans = max(ans, c);
		}

		printf("%d\n", ans);
		if (tc)
			puts("");
	}

}
