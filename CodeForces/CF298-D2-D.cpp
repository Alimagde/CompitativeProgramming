#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> l1(n), l2(m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &l1[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &l2[i]);

	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());

	while (l1.size() && l2.size()) {
		if (l1.back() > l2.back())
			break;
		l1.pop_back();
		l2.pop_back();
	}

	if ((l1.size() && l2.size()) || l1.size())
		puts("YES");
	else
		puts("NO");

}
