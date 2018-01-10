/*
 count for every character number of occurrences of cumulative sum and count number of substrings
 */
#include <bits/stdc++.h>
using namespace std;

map<long long, int> mp[30];
long long like[30];

char arr[100005];
int main() {
	for (int i = 0; i < 26; ++i) {
		scanf("%lld", like + i);
	}
	scanf("%s", arr);
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; arr[i]; ++i) {
		ans += (mp[arr[i] - 'a'][sum]);
		sum += like[arr[i] - 'a'];
		mp[arr[i] - 'a'][sum]++;
	}
	printf("%lld", ans);
}
