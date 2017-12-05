/*
	first but all lucky numbers in a vector then have a pointer the the minimum so far then lower bound
	for the next lucky and all numbers from the number to the lucky number have the same next
 */

#include <bits/stdc++.h>
using namespace std;

vector<long long> lucky;

void precalc() {
	deque<long long> q;
	q.push_back(4);
	q.push_back(7);
	while (q.size()) {
		long long v = q[0];
		q.pop_front();
		if (v > 7777777777ll)
			continue;
		lucky.push_back(v);
		q.push_back((v * 10) + 4);
		q.push_back((v * 10) + 7);
	}

}

int main() {
	precalc();
	sort(lucky.begin(), lucky.end());
	long long s, e;
	scanf("%lld %lld", &s, &e);
	long long i = s;
	long long ans = 0;
	while (i <= e) {
		long long x = *lower_bound(lucky.begin(), lucky.end(), i);
		if (x <= e) {
			ans += ((x - i + 1) * x);
			i = x + 1;
		} else {
			ans += ((e - i + 1) * x);
			break;
		}
	}
	printf("%lld",ans);
}
