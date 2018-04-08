/*
 first generate all segment and then using dsu merge the intersecting segments ,the answer will be the number of disjoint sets
 */
#include <vector>
#include <list>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double pi = 3.141592653589793;
typedef complex<long double> point;
#define eps 1e-9
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

bool inSegment(const point &P, const point &a, const point &b) {
	if (a.X != b.X) {    // S is not  vertical
		if (a.X <= P.X && P.X <= b.X)
			return 1;
		if (a.X >= P.X && P.X >= b.X)
			return 1;
	} else {    // S is vertical, so test y  coordinate
		if (a.Y <= P.Y && P.Y <= b.Y)
			return 1;
		if (a.Y >= P.Y && P.Y >= b.Y)
			return 1;
	}
	return 0;
}

int intersect2D_2Segments(const point &a, const point &b, const point &p,
		const point &q, point &I0, point &I1) {
	point u = b - a;
	point v = q - p;
	point w = a - p;
	long double D = cross(u, v);

	// test if  they are parallel (includes either being a point)
	if (fabs(D) < eps) {		// S1 and S2 are parallel
		if (cross(u,w) != 0 || cross(v,w) != 0) {
			return 0;                    // they are NOT collinear
		}
		// they are collinear or degenerate
		// check if they are degenerate  points
		long double du = dot(u, u);
		long double dv = dot(v, v);
		if (du == 0 && dv == 0) {            // both segments are points
			if (a != p)         // they are distinct  points
				return 0;
			I0 = a;                 // they are the same point
			return 1;
		}
		if (du == 0) {                     // S1 is a single point
			if (!inSegment(a, p, q))  // but is not in S2
				return 0;
			I0 = a;
			return 1;
		}
		if (dv == 0) {                     // S2 a single point
			if (!inSegment(p, a, b))  // but is not in S1
				return 0;
			I0 = p;
			return 1;
		}
		// they are collinear segments - get  overlap (or not)
		long double t0, t1;                    // endpoints of S1 in eqn for S2
		point w2 = b - p;
		if (v.X != 0) {
			t0 = w.X / v.X;
			t1 = w2.X / v.X;
		} else {
			t0 = w.Y / v.Y;
			t1 = w2.Y / v.Y;
		}
		if (t0 > t1) {                   // must have t0 smaller than t1
			long double t = t0;
			t0 = t1;
			t1 = t;    // swap if not
		}
		if (t0 > 1 || t1 < 0) {
			return 0;      // NO overlap
		}
		t0 = t0 < 0 ? 0 : t0;               // clip to min 0
		t1 = t1 > 1 ? 1 : t1;               // clip to max 1
		if (t0 == t1) {                  // intersect is a point
			I0 = p + t0 * v;
			return 1;
		}

		// they overlap in a valid subsegment
		I0 = p + t0 * v;
		I1 = p + t1 * v;
		return 2;
	}
	// the segments are skew and may intersect in a point
	// get the intersect parameter for S1
	long double sI = cross(v, w) / D;
	if (sI < 0 || sI > 1)                // no intersect with S1
		return 0;

	// get the intersect parameter for S2
	long double tI = cross(u, w) / D;
	if (tI < 0 || tI > 1)                // no intersect with S2
		return 0;

	I0 = a + sI * u;                // compute S1 intersect point
	return 1;
}

int par[2000];

void init() {
	for (int i = 0; i < 2000; ++i) {
		par[i] = i;
	}
}

int getpar(int x) {
	if (par[x] == x)
		return x;
	return par[x] = getpar(par[x]);
}

void merge(int a, int b) {
	if (getpar(a) == getpar(b))
		return;

	par[par[a]] = par[b];
}

class PolylineUnion {
public:

	vector<pair<point, point> > seg;
	vector<int> points;

	void getseg() {
		if (points.size() == 2) {
			seg.push_back(
					{ point(points[0], points[1]), point(points[0], points[1]) });
			points.clear();
			return;
		}
		for (int i = 2; i < points.size(); i += 2) {
			seg.push_back(
					{ point(points[i - 2], points[i - 1]), point(points[i],
							points[i + 1]) });
		}
		points.clear();
	}

	int countComponents(vector<string> p) {
		string x = "";
		for (int i = 0; i < p.size(); i++) {
			x += p[i];
		}
		point a, b;
		int v = 0;

		for (int i = 0; i < x.size(); i++) {
			if (x[i] == ' ') {
				points.push_back(v);
				getseg();
				v = 0;
			} else if (x[i] == '-' || x[i] == ',') {
				points.push_back(v);
				v = 0;
			} else {
				v *= 10;
				v += (x[i] - '0');
			}
		}
		points.push_back(v);
		getseg();
		init();
		int c = 0;
		for (int i = 0; i < seg.size(); i++) {
			for (int j = i + 1; j < seg.size(); ++j) {
				if (intersect2D_2Segments(seg[i].first, seg[i].second,
						seg[j].first, seg[j].second, a, b)) {
					merge(i, j);
					++c;
				}
			}
		}
		set<int> st;
		for (int i = 0; i < seg.size(); i++) {
			st.insert(getpar(i));
		}
		return st.size();
	}
};
