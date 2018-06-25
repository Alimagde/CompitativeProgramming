/*
 using binary search find X that between x+1 and 2*x there is m numbers with k bits ones
 to count M using dynamic programming count how many number <= V that have k bits ones

 let f(V,k) is the count of numbers <= V that have k bits ones
 the answer for x+1 to 2*x is f(2*x,k)-f(x,k)

 */
#include <bits/stdc++.h>
using namespace std;

int str[66];
long long m;
int k;
long long memo[66][66][3];
int vis[66][66][3], vid = 0;
void setstr(long long v) {
	int idx = 61;
	while (v) {
		str[idx--] = (v & 1);
		v >>= 1;
	}
	while (~idx) {
		str[idx--] = 0;
	}
	++vid;
}

long long solve(int idx, int k, bool ls) {
	if (idx == 62) {
		if (k == 0)
			return 1;
		return 0;
	}
	if (k < 0)
		return 0;

	if (vis[idx][k][ls] == vid) {
		return memo[idx][k][ls];
	}
	long long &res = memo[idx][k][ls];
	res = 0;
	vis[idx][k][ls] = vid;
	if (ls) {
		res += solve(idx + 1, k, ls);
		res += solve(idx + 1, k - 1, ls);
	} else {
		for (int i = 0; i <= str[idx]; ++i) {
			res += solve(idx + 1, k - i, ls | (i < str[idx]));
		}
	}
	return res;
}

int main() {

	scanf("%lld %d", &m, &k);
	long long s = 1, e = 1e18;

	while (s < e) {
		long long mid = s + (e - s) / 2;
		setstr(mid * 2);
		long long v = solve(0, k, 0);
		setstr(mid);
		v -= solve(0, k, 0);

		if (v < m)
			s = mid + 1;
		else
			e = mid;
	}
	printf("%lld\n", s);
}
