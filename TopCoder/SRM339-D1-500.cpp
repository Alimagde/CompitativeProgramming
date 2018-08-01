#include <bits/stdc++.h>
using namespace std;

double area(int a, int b, int c) {
	double p = (a + b + c) / 2.0;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

vector<int> sz;
int n;
double memo[(1 << 17)];
bool vis[(1 << 17)];
double solve(int msk) {

	double &res = memo[msk];
	if (vis[msk])
		return res;
	vis[msk] = 1;
	res = 0;
	for (int i = 0; i < n; ++i) {
		if ((msk >> i) & 1)
			continue;
		for (int j = i + 1; j < n; ++j) {
			if ((msk >> j) & 1)
				continue;
			for (int k = j + 1; k < n; ++k) {
				if ((msk >> k) & 1)
					continue;
				if (sz[i] + sz[j] > sz[k]) {
					int nx = msk;
					nx |= (1 << i);
					nx |= (1 << j);
					nx |= (1 << k);
					res = max(res, solve(nx) + area(sz[i], sz[j], sz[k]));
				}
			}
		}
	}
	return res;
}

class GrasslandFencer {
public:
	double maximalFencedArea(vector<int> vec) {
		sort(vec.begin(), vec.end());
		sz = vec;
		n = vec.size();
		return solve(0);
	}
};
