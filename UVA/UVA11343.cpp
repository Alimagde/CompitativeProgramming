/*
 */
#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
typedef complex<int> point;
#define EPS 1e-13
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define polar(r,t) ((r) * exp(point(0, (t))))
#define angle(v) (atan2((v).Y, (v).X))
#define length(v) ((double)hypot((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(a,b) ((conj(a) * (b)).real())
#define cross(a,b) ((conj(a) * (b)).imag())
#define rotate(v,t) (polar(v, t))
#define rotateabout(v,t,a) (rotate(vec(a, v), t) + (a))
#define reflect(p,m) ((conj((p) / (m))) * (m))
#define normalize(p) ((p) / length(p))
#define same(a,b) (lengthSqr(vec(a, b)) < EPS)
#define mid(a,b) (((a) + (b)) / point(2, 0))
#define perp(a) (point(-(a).Y, (a).X))
#define colliner pointOnLine
enum STATE {
	IN, OUT, BOUNDRY
};

bool pointOnLine(const point& a, const point& b, const point& p) {
	return fabs(cross(vec(a,b), vec(a,p))) < EPS;
}

bool pointOnRay(const point& a, const point& b, const point& p) {
	return dot(vec(a,p), vec(a,b)) > -EPS;
}

bool pointOnSegment(const point& a, const point& b, const point& p) {

	if (!colliner(a, b, p))
		return 0;
	return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

pair<point, point> arr[200];

bool valid(point &x, point &y, int i) {
	bool b1 = (cross(vec(x,y), vec(x,arr[i].first))) < EPS;
	bool b2 = (cross(vec(x,y), vec(x,arr[i].second))) < EPS;
	return (b1 ^ b2);
}

bool intersect(int i, int j) {
	return (pointOnSegment(arr[j].first, arr[j].second, arr[i].second)
			|| pointOnSegment(arr[j].first, arr[j].second, arr[i].first)
			|| pointOnSegment(arr[i].first, arr[i].second, arr[j].first)
			|| pointOnSegment(arr[i].first, arr[i].second, arr[j].second)
			|| arr[i].first == arr[j].first || arr[i].first == arr[j].second
			|| arr[i].second == arr[j].first || arr[i].second == arr[j].second
			|| (valid(arr[i].first, arr[i].second, j)
					&& valid(arr[i].second, arr[i].first, j)
					&& valid(arr[j].first, arr[j].second, i)
					&& valid(arr[j].second, arr[j].first, i)));
}

int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		int x, y;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			arr[i].first = point(x, y);
			scanf("%d %d", &x, &y);
			arr[i].second = point(x, y);
		}
		int ans = n;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				if (intersect(i, j)) {
					--ans;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}
