/*
 adding element in a multiset and keep a iterator on the i-minimum so far
 */
#include <bits/stdc++.h>
using namespace std;

int a[30004];
int g[30004];

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", g + i);
		}

		multiset<int> st;
		st.insert(a[0]);
		auto it = st.begin();
		g[m] = 1e9;
		int id = 0;
		for (int i = 1; i < n; ++i) {
			while (g[id] == st.size()) {
				printf("%d\n", *it);
				it++;
				id++;
			}

			st.insert(a[i]);
			if (a[i] < (*it) || it == st.end())
				--it;
		}
		while (g[id] == (int) st.size()) {
			printf("%d\n", *it);
			it++;
			id++;
		}
		if (tc)
			puts("");
	}
}
