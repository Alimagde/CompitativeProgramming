/*
 find the nearest point to M in every segment and take the neatest one
 */
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;

#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9

#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine
enum STATE {
	IN, OUT, BOUNDRY
};

point intersect(const point a, const point b, const point p, const point q,
		point ret) {
	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (fabs(d1 - d2) > EPS)
		return ret;
	return point(1.0 / 0.0, 1.0 / 0.0);

}

bool pointOnLine(const point a, const point b, const point p) {
	return fabs(cross(vec(a,b), vec(a,p))) < EPS;
}

point pointSegmentDist(point a, point b, point p) {
	if (dot(vec(a, b), vec(a, p)) < EPS)
		return a;
	if (dot(vec(b, a), vec(b, p)) < EPS)
		return b;
	return intersect(a, b, p, p + (perp(vec(a,b))), p);
}

int main() {

	double x, y;
	while (~scanf("%lf", &x)) {
		scanf("%lf", &y);

		point m(x, y);
		int n;
		scanf("%d", &n);
		double a, b, c, d;
		double ansx, ansy, mn = 1 / 0.0;
		scanf("%lf %lf", &a, &b);
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf", &c, &d);
			point p = pointSegmentDist(point(a, b), point(c, d), m);

			double l = length(vec(m,p));
			if (l < mn) {
				mn = l;
				ansx = p.X;
				ansy = p.Y;
			}
			a = c;
			b = d;
		}
		printf("%.4lf\n%.4lf\n", ansx, ansy);
	}
}
