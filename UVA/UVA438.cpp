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
enum STATE {
	IN, OUT, BOUNDRY
};

bool intersect(const point &a, const point &b, const point &p, const point &q,
		point &ret) {

	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (fabs(d1 - d2) > EPS)
		return 1;
	return 0;
}

bool circle3(const point &p1, const point &p2, const point &p3, point& cen,
		double& r) {
	point m1 = mid(p1, p2);
	point m2 = mid(p2, p3);
	point perp1 = perp(vec(p1, p2));
	point perp2 = perp(vec(p2, p3));
	bool res = intersect(m1, m1 + perp1, m2, m2 + perp2, cen);
	r = length(vec(cen,p1));
	return res;
}

int main() {

	double x1, y1, x2, y2, x3, y3;
	while (~scanf(" %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)) {
		point a(x1, y1), b(x2, y2), c(x3, y3);
		point res;
		double r;
		circle3(a, b, c, res, r);

		printf("%.2lf\n", pi * r * 2);
	}
}
