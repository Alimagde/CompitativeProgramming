/*
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int z;
	scanf("%d", &z);
	for (int t = 1; t <= z; ++t) {
		int n;
		scanf("%d", &n);
		int x1 = -1e9, x2 = 1e9, y1 = -1e9, y2 = 1e9;
		for (int i = 0; i < n; ++i) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			x1 = max(x1, a);
			x2 = min(x2, c);
			y1 = max(y1, b);
			y2 = min(y2, d);
		}
		if(x1>x2 || y1>y2) printf("Case %d: 0\n",t);
		else printf("Case %d: %d\n",t,max(0,(x2-x1)*(y2-y1)));
	}
}
