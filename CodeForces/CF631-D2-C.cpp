/*

 */
#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int ans[200005];
int n, m;
bool vis[200005];
int s = 0, e = -1;
int main() {
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > q(m);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);

	for (int i = 0; i < m; ++i)
		scanf("%d %d", &q[i].first, &q[i].second);

	int b = -1;
	for (int i = m - 1; i >= 0; --i) {
		if (b >= q[i].second)
			vis[i] = 1;
		b = max(b, q[i].second);
	}

	int i;
	bool r = 0;
	for (i = 0; i < m; ++i) {
		if (!vis[i]) {
			sort(arr, arr + q[i].second);
			if (q[i].first == 1) {
				s = 0, e = q[i].second - 1;
			} else {
				s = 0, e = q[i].second - 1, r = 1;
			}
			for (int j = q[i].second; j < n; ++j)
				ans[j] = arr[j];

			break;
		}
	}

	for (; i < m; ++i) {
		if (vis[i])
			continue;
		if (r) {
			while (e - s + 1 > q[i].second) {
				ans[e - s] = arr[s];
				++s;
			}
		} else {
			while (e - s + 1 > q[i].second) {
				ans[e - s] = arr[e];
				--e;
			}
		}

		if (q[i].first == 1) {
			ans[e - s] = arr[e];
			--e;
			r = 0;
		} else {
			ans[e - s] = arr[s];
			++s;
			r = 1;
		}
	}

	if (r) {
		while (e >= s) {
			ans[e - s] = arr[s];
			++s;
		}
	} else {
		while (e >= s) {
			ans[e - s] = arr[e];
			--e;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
}
