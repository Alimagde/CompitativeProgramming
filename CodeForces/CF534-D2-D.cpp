#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> arr[N];
int n;
vector<int> ans;

set<int> st[4];

int main() {

	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		arr[x].push_back(i);
		st[x % 3].insert(x);
	}
	int idx = 0;

	while (1) {

		if (arr[idx].empty()) {
			if (st[idx % 3].empty())
				break;
			auto it = st[idx % 3].lower_bound(idx);
			if (it != st[idx % 3].begin())
				--it;
			else
				break;
			int v = (*it);
			if (v > idx)
				break;
			idx = v;
		}

		ans.push_back(arr[idx].back());
		arr[idx].pop_back();
		if (arr[idx].empty())
			st[idx % 3].erase(idx);

		++idx;
	}
	if ((int) ans.size() == n) {
		puts("Possible");
		for (auto z : ans)
			printf("%d ", z);
	} else
		puts("Impossible");
}
