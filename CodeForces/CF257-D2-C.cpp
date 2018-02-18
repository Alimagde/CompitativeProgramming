/*

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

point arr[100005];

double getangle(point &p) {
	double v = angle(p);
	if (v < 0.0)
		v += (2 * pi);
	return v;
}

int main() {

	int n, x, y;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		arr[i] = point(x * 1.0, y * 1.0);
	}

	sort(arr, arr + n, [](point a,point b) {
		double aa=angle(a),bb=angle(b);
		if(aa<EPS) aa+=(2*pi);
		if(bb<EPS) bb+=(2*pi);
		return (bb-aa)>EPS;;
	});

	double ans = 1e9;
	arr[n] = arr[0];
	for (int i = 0; i < n; ++i) {
		double v = (getangle(arr[i + 1]) - getangle(arr[i]));
		if (v < (-EPS))
			v += (2 * pi);
		ans = min(ans, (2 * pi) - v);

	}
	if (fabs(ans - (2 * pi)) < EPS)
		ans = 0;
	printf("%.10lf", ans * 180 / pi);
}
