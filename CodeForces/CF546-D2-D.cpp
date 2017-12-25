/*
 count the powers of every prime factor of every number and make cumulative sum to answer every query
 in O(1)
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5000005;

bool notp[N];
long long cnt[N];

void sieve() {
	for (long long i = 2; i < N; ++i) {
		if (notp[i])
			continue;
		for (int j = i; j < N; j += i) {
			notp[j] = 1;
			int c = 0;
			long long v = j;
			while (v % i == 0) {
				++c;
				v /= i;
			}
			cnt[j] += c;
		}
	}
	for (int i = 1; i < N; ++i)
		cnt[i] += cnt[i - 1];
}

int main() {

	sieve();
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", cnt[a] - cnt[b]);
	}
}
