/*

 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) && n) {
		int ans = -1;
		double mn = 0;
		for (int i = 1; i <= n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (x > y)
				swap(x, y);
			if (x * 4 <= y) {
				if (x > mn) {
					mn = x;
					ans = i;
				}
			}

			if (min(1.0 * x, 1.0 * y / 4) > mn) {
				mn = min(1.0 * x, 1.0 * y / 4);
				ans = i;
			}
			if(1.0*x/2.0>mn){
				mn=1.0*x/2.0;
				ans=i;
			}

		}

		printf("%d\n", ans);
	}

}
