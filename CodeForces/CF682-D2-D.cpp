/*

 */
#include <bits/stdc++.h>
using namespace std;

char str1[1010], str2[1010];
int memo[1010][1010][12][3];
int n, m;
int solve(int i, int j, int k, bool s) {
	if (k == 0)
		return 0;
	if (i == n || j == m) {
		if (k == 1 && s == 1)
			return 0;
		return -1e9;
	}
	int &r = memo[i][j][k][s];
	if (~r)
		return r;
	r = -1e9;
	if (s) {
		if (str1[i] == str2[j]) {
			r = max(r, 1 + solve(i + 1, j + 1, k, s));
			r = max(r, solve(i, j, k - 1, 0));
		} else {
			r = max(r, solve(i, j, k - 1, 0));
		}
	} else {
		if (str1[i] == str2[j]) {
			r = max(r, 1 + solve(i + 1, j + 1, k, 1));
		}
		r = max(r, solve(i + 1, j, k, 0));
		r = max(r, solve(i, j + 1, k, 0));
	}
	return r;
}

int main() {
	//freopen("in.txt", "rt", stdin);
	int k;
	scanf("%d %d %d", &n, &m, &k);
	scanf(" %s", str1);
	scanf(" %s", str2);
	memset(memo, -1, sizeof memo);
	printf("%d", solve(0, 0, k, 0));

}

