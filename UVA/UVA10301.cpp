/*

 */
#include <bits/stdc++.h>
using namespace std;

int par[110];
int cnt[110];
void init() {
	for (int i = 0; i <= 100; ++i) {
		par[i] = i;
		cnt[i] = 0;
	}
}

int getpar(int x) {
	if (par[x] == x)
		return x;
	return par[x] = getpar(par[x]);
}

void merge(int a, int b) {
	getpar(a);
	getpar(b);
	if (par[a] < par[b])
		swap(a, b);

	par[par[a]] = par[b];

}

double x[110], y[110], r[110];

int main() {

	int n;
	while (scanf("%d", &n), ~n) {
		init();
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf %lf", x + i, y + i, r + i);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				double v = hypot(abs(x[i] - x[j]), abs(y[i] - y[j]));

				if (v <= (r[i] + r[j])
						&& v + min(r[i], r[j]) >= max(r[i], r[j])) {
					merge(i, j);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cnt[getpar(i)]++;

		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, cnt[i]);
		if (ans != 1)
			printf("The largest component contains %d rings.\n", ans);
		else
			puts("The largest component contains 1 ring.");
	}
}

