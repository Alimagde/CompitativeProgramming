#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<int> ll, rr;
vector<pair<int, int> > vec;
int memo[2][301][301];
int cnt[305];
int n;
void init() {
	cnt[n + 1] = 1;
	for (int i = n; i >= 1; --i) {
		cnt[i] = (cnt[i + 1] * 2) % mod;
	}
}

class WolfInZooDivTwo {
public:
	int count(int N, vector<string> L, vector<string> R) {
		string l = "", r = "";
		n = N;
		for (auto &x : L)
			l += x;
		for (auto &x : R)
			r += x;

		int x = 0;
		for (auto &c : l) {
			if (c == ' ') {
				ll.push_back(x);
				x = 0;
			} else {
				x *= 10;
				x += (c - '0');
			}
		}
		ll.push_back(x);
		x = 0;
		for (auto &c : r) {
			if (c == ' ') {
				rr.push_back(x);
				x = 0;
			} else {
				x *= 10;
				x += (c - '0');
			}
		}
		rr.push_back(x);
		for (int i = 0; i < (int) ll.size(); ++i) {
			vec.push_back(make_pair(ll[i] + 1, rr[i] + 1));
		}
		sort(vec.begin(), vec.end());
		init();
		int id = (n + 1) % 2;
		int c = vec.size();
		for (int l = 0; l <= n; l++) {
			for (int cr = c; cr >= 0; --cr) {
				if (cr == c)
					memo[id][l][cr] = 1;
				else {
					if (l >= vec[cr].first && l <= vec[cr].second) {
						memo[id][l][cr] = memo[id][l][cr + 1];
						continue;
					}
				}
			}
		}
		id ^= 1;
		for (int i = n; i > 0; --i, id ^= 1) {
			for (int l = 0; l < i; ++l) {
				for (int cr = c; cr >= 0; --cr) {
					if (cr == c) {
						memo[id][l][cr] = cnt[i];
						continue;
					}
					if (l >= vec[cr].first && l <= vec[cr].second) {
						memo[id][l][cr] = memo[id][l][cr + 1];
						continue;
					}
					if (i > vec[cr].second) {
						memo[id][l][cr] = 0;
					}
					memo[id][l][cr] =
							(memo[id ^ 1][l][cr] + memo[id ^ 1][i][cr]) % mod;
				}
			}
		}
		return memo[1][0][0];
	}
};


