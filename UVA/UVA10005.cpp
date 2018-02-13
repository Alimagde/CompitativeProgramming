/*
 get the minimum enclosing circle for the point and compare the circle radius with the given radius
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
enum STATE {
	IN, OUT, BOUNDRY
};

#define MAXPOINTS 101
point p[MAXPOINTS], r[3], cen;
int ps, rs;
double rad;

bool intersect(const point &a, const point &b, const point &p, const point &q,
		point &ret) {
	int dx1 = a.X - b.X;
	int dx2 = p.Y - q.Y;
	int dy1 = a.X - b.X;
	int dy2 = p.Y - q.Y;

	if ((dx1 >= 0 && dy1 <= 0) || (dx1 <= 0 && dy1 >= 0)) {
		dx1 = abs(dx1);
		dy1 = -abs(dy1);
	}
	if ((dx2 >= 0 && dy2 <= 0) || (dx2 <= 0 && dy2 >= 0)) {
		dx2 = abs(dx2);
		dy2 = -abs(dy2);
	}

	if (dx1 == dx2 && dy1 == dy2)
		return 0;

	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (fabs(d1 - d2) > EPS)
		return 1;
	return 0;
}

void circle2(const point &p1, const point &p2, point &cen, double &r) {
	cen = mid(p1, p2);
	r = length(vec(p1, p2)) / 2;
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

STATE circlePoint(const point &cen, const double &r, const point &p) {
	double lensqr = lengthSqr(vec(cen,p));
	if (fabs(lensqr - r * r) < EPS)
		return BOUNDRY;
	if (lensqr < r * r)
		return IN;
	return OUT;
}

void mec() {
	if (rs == 3) {
		circle3(r[0], r[1], r[2], cen, rad);
		return;
	}
	if (rs == 2 && ps == 0) {
		circle2(r[0], r[1], cen, rad);
		return;
	}
	if (!ps) {
		cen = r[0];
		rad = 0;
		return;
	}
	ps--;
	mec();
	if (circlePoint(cen, rad, p[ps]) == OUT) {
		r[rs++] = p[ps];
		mec();
		rs--;
	}
	ps++;
}

int main() {

	int n, x, y;
	while (scanf("%d", &n), n) {

		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			p[i] = point(x * 1.0, y * 1.0);
		}
		ps = n;
		random_shuffle(p, p + n);
		mec();
		double r;
		scanf("%lf", &r);
		if (fabs(r - rad) < EPS || r + EPS > rad)
			puts("The polygon can be packed in the circle.");
		else
			puts("There is no way of packing that polygon.");
	}
}
