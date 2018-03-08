/*

 */

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9;
long long memo[303][303];
int vis[303][303], vid = 0;
char str[303];

long long solve(int i, int j) {

	if (str[i] != str[j] || i > j)
		return 0;

	if (i == j)
		return 1;

	long long &r = memo[i][j];
	if (vis[i][j] == vid)
		return r;
	vis[i][j] = vid;
	r = 0;

	for (int k = i + 1; k < j; ++k) {
		if (str[i] == str[k + 1])
			r = (r + (solve(i + 1, k) * solve(k + 1, j))) % mod;
	}

	return r;
}

int main() {
	freopen("in.txt", "rt", stdin);
	while (~scanf(" %s", str)) {
		int l = strlen(str);
		++vid;
		printf("%lld\n", solve(0, l - 1));
	}
}
