/*
 for every bit i in the number find the nearest number that have bit i set to 0 if so and the
 distance greater than K then the bit i will be set in the number after K operations
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int arr[N], ans[N];
int val[N];

int l[N], r[N];

int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			ans[i] = 0;
		}
		for (int p = 0; p <= 30; ++p) {
			for (int i = 0; i < n; ++i) {
				val[i] = ((arr[i] >> p) & 1);
			}

			int v = -(1e9 + 5);
			for (int i = 0; i < n; ++i) {
				if (!val[i])
					v = i;
				l[i] = abs(i - v);
			}
			v = (1e9 + 5);
			for (int i = n - 1; i >= 0; --i) {
				if (!val[i])
					v = i;
				r[i] = abs(i - v);
			}

			for (int i = 0; i < n; ++i) {
				v = 1e9 + 5;
				v = min(l[i], r[i]);
				v = min(v, (i + 1) + l[n - 1]);
				v = min(v, (n - i) + r[0]);
				if (v > k) {
					ans[i] |= (1 << p);
				}
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d ", ans[i]);
		puts("");
	}
}
