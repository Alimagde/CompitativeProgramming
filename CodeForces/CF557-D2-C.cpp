#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100005];
int cnt[202];

pair<int, int> len[100005];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &len[i].first);
	}
	int x;
	long long cost = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &len[i].second);
		cost += len[i].second;
		arr[len[i].first].push_back(len[i].second);
	}
	long long ans = 1e9;
	n = 0;
	for (int i = 0; i < 100002; ++i) {
		if (arr[i].size() == 0)
			continue;
		for (auto z : arr[i]) {
			cost -= z;
		}
		x = arr[i].size();
		n += x;
		int l = n - x;
		l = max(0, n - (x * 2 - 1));
		long long v = 0;
		for (int j = 1; j <= 200; ++j) {
			if (cnt[j] < l) {
				v += cnt[j] * j;
				l -= cnt[j];
			} else {
				v += j * l;
				break;
			}
		}
		ans = min(ans, v + cost);
		for (auto z : arr[i]) {
			cnt[z]++;
		}
	}
	printf("%lld", ans);
}

