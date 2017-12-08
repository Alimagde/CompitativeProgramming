/*
 find the nearest and the farthest points of every square to the center if both in the circle so the square in
 if one in and the other out so the square on the boundary
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	int c = 0;
	while (~scanf("%d", &n)) {
		double r = (2.0 * n) - 1.0;
		r /= 2;
		if (c++)
			puts("");
		int in = 0, bo = 0;
		for (int i = -n; i < n; ++i) {
			for (int j = -n; j < n; ++j) {
				double mn = 1e9, mx = -1e9;
				int ax, ay, bx, by;
				for (int x = 0; x < 2; ++x) {
					for (int y = 0; y < 2; ++y) {
						double z = hypot(i + x, j + y);
						if (z < mn) {
							mn = z;
							ax = i + x;
							ay = j + y;
						}
						if (z > mx) {
							mx = z;
							bx = i + x;
							by = j + y;
						}
					}
				}
				bool a = 0, b = 0;

				a = (hypot(ax, ay) <= r);
				b = (hypot(bx, by) <= r);
				if (a && b) {
					++in;
				} else if (a || b)
					++bo;
			}
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\n",
				n, bo);
		printf("There are %d cells completely contained in the circle.\n", in);
	}
}
