/*
 	loop over the prefix and get the summation of the element if equal total_sum/2 or else add another element and find
 	number sum-(total_sum/2) in the prefix before the added number
 */
#include <bits/stdc++.h>
using namespace std;

long long arr[100005];
bool in[100005];
int main() {

	int n;
	scanf("%d", &n);
	map<long long, int> mp;
	map<long long, int> cnt;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", arr + i);
		sum += arr[i];
		mp[arr[i]];
		cnt[arr[i]]++;
	}
	int id = 1;
	for (auto &x : mp)
		x.second = id++;

	in[mp[arr[0]]] = 1;
	long long v = arr[0];
	cnt[arr[0]]--;
	bool c = 0;
	if (sum % 2) {
		puts("NO");
		return 0;
	}
	sum /= 2;

	for (int i = 1; i < n; ++i) {

		if (v == sum || cnt[sum - v])
			c = 1;
		v += arr[i];
		if (sum < v && in[mp[v - sum]])
			c = 1;
		in[mp[arr[i]]] = 1;
		cnt[arr[i]]--;
	}
	if (c)
		puts("YES");
	else
		puts("NO");
}
