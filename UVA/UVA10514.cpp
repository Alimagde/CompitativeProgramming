/*
 find the shortest water distance for every pair of islands and between islands and the
 shortest water distance between the two shores then using floyed find the shortest distance
 between the two shores.

 */
#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
typedef complex<double> point;
#define EPS 1e-9
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

double pointLineDist(const point& a, const point& b, const point& p) {
// handle degenrate case: (a,b) is point
	return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

double pointSegmentDist(const point &a, const point &b, const point &p) {
	if (dot(vec(a,b),vec(a,p)) < EPS)
		return length(vec(a,p));
	if (dot(vec(b,a),vec(b,p)) < EPS)
		return length(vec(b,p));
	return pointLineDist(a, b, p);
}

double getmin(point &a, point &b, point &x, point &y) {
	double v1 = min(pointSegmentDist(a, b, x), pointSegmentDist(a, b, y));
	double v2 = min(pointSegmentDist(x, y, a), pointSegmentDist(x, y, b));
	return min(v1, v2);
}

vector<point> arr[20];

double dist[20][20];

void floyed(int n) {
	for (int i = 0; i < n; ++i)
		dist[i][i] = 0.0;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b, n;
		scanf("%d %d %d", &a, &b, &n);
		n += 2;
		for (int i = 0; i < n; ++i) {
			arr[i].clear();
		}
		double x, y;
		for (int i = 0; i < a; ++i) {
			scanf("%lf %lf", &x, &y);
			arr[0].push_back(point(x, y));
		}
		for (int i = 0; i < b; ++i) {
			scanf("%lf %lf", &x, &y);
			arr[1].push_back(point(x, y));
		}
		int m;
		for (int i = 2; i < n; ++i) {
			scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				scanf("%lf %lf", &x, &y);
				arr[i].push_back(point(x, y));
			}
			arr[i].push_back(arr[i][0]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				double d = 1e9;
				for (int k = 1; k < (int)arr[i].size(); ++k) {
					for (int l = 1; l < (int)arr[j].size(); ++l) {
						d = min(d,
								getmin(arr[i][k - 1], arr[i][k], arr[j][l - 1],
										arr[j][l]));
					}
				}
				dist[i][j] = dist[j][i] = d;
			}
		}
		floyed(n);
		printf("%.3lf\n", dist[0][1]);
	}
}
