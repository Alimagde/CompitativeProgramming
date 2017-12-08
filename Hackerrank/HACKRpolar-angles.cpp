/*

 */
#include <bits/stdc++.h>
using namespace std;

#define eps 1e-13

struct point {
	int x, y;

	double deg;

	point(int a, int b) {
		x = a;
		y = b;
	}

	point() {
		x = 0;
		y = 0;
	}

	void getdeg() {
		deg = atan2(y, x);
		if (deg < 0)
			deg += M_PI * 2;
	}

	bool operator <(const point &z) const {

		if (fabs(deg - z.deg) < eps)
			return hypot(y, x) + eps <= hypot(z.y, z.x);
		return deg < z.deg;
	}

};

int main() {

	int n;
	scanf("%d", &n);
	vector<point> vec(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[i].x = x;
		vec[i].y = y;
		vec[i].getdeg();

	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", vec[i].x, vec[i].y);
	}
}
