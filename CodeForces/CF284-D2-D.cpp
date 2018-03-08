/*
 map te array to a directed graph and check if there is a cycle, if not count the path to the end using dp
 */
#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 200005;
int memo[N][3];
long long arr[N];

long long tot[N][3];

int solve(int idx, int d) {
	if (idx < 1 || idx > n)
		return 1;
	if (idx == 1) {
		return d;
	}
	if (~memo[idx][d])
		return memo[idx][d];
	int &r = memo[idx][d];
	r = 0;

	if (d == 0) {
		if (solve(idx + arr[idx], d ^ 1))
			r = 1;
	} else {
		if (solve(idx - arr[idx], d ^ 1))
			r = 1;
	}
	return r;
}

long long get(int idx, int d) {
	if (idx < 1 || idx > n)
		return 0;
	if (idx == 1) {
		return arr[idx];
	}
	if (~tot[idx][d])
		return tot[idx][d];
	long long &r = tot[idx][d];
	r = 0;

	if (d == 0) {
		r = (arr[idx] + get(idx + arr[idx], d ^ 1));
	} else {
		r = (arr[idx] + get(idx - arr[idx], d ^ 1));
	}
	return r;
}

int main() {

	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		scanf("%lld", arr + i);
	memset(tot, -1, sizeof tot);
	for (int i = 1; i < n; ++i) {
		arr[1] = i;
		if (solve(1 + i, 1)) {
			printf("%lld\n", get(1 + i, 1) + i);
		} else
			puts("-1");
	}

}
