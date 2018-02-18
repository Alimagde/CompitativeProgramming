/*
 every set must have at most 1 even number solve the problem for the 1 and then multiply the answer with k
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<vector<long long>> ans;
	vector<long long> s(4);
	s[0] = 1;
	s[1] = 2;
	s[2] = 3;
	s[3] = 5;
	ans.push_back(s);
	long long v = 6;
	while (--n) {
		s[0] = v + 2;
		s[1] = v + 1;
		s[2] = v + 3;
		s[3] = v + 5;
		v += 6;
		ans.push_back(s);
	}
	printf("%lld\n", (v - 1) * k);

	for (auto s : ans) {
		for (auto x : s) {
			printf("%lld ", x * k);
		}
		puts("");
	}
}
