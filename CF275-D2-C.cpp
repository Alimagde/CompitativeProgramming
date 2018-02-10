/*
 */
#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		mp[arr[i]] = 1;
	}
	if (k == 1) {
		printf("%d", n);
		return 0;
	}
	sort(arr, arr + n);
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		int v = arr[i];
		if (!mp[v])
			continue;
		mp[v] = 0;
		int c = 1;
		while (v % k == 0) {
			v /= k;
			if (mp[v]) {
				++c;
				mp[v] = 0;
			} else
				break;
		}
		ans += (c + 1) / 2;
	}
	printf("%d", ans);
}
