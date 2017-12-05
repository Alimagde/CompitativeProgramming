/*
 for every index get count of all values equal to cnt-k so that the sum of one's between them equal to k
 */
#include <bits/stdc++.h>
using namespace std;

map<int, long long> mp;
char arr[1000006];
int cnt = 0;
int main() {
	mp[0] = 1;
	int k;
	scanf("%d", &k);
	scanf(" %s", arr);
	long long ans = 0;
	for (int i = 0; arr[i]; ++i) {
		cnt += (arr[i] - '0');
		ans += mp[cnt - k];
		mp[cnt]++;
	}
	printf("%lld", ans);
}
