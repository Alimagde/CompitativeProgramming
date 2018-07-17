/*
	for every rectangle find if there is an end point inside it if not find if there is a segment that
	intersect with the sides of the rectangle
 */

#include <bits/stdc++.h>
using namespace std;

typedef complex<long double> point;
#define eps 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define cross(a,b) ((conj(a) * (b)).imag())
#define dot(a,b) ((conj(a) * (b)).real())

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

class RectangleCrossings {
public:
	vector<int> countAreas(vector<string> rec, vector<string> seg) {
		vector<int> ans(2, 0);
		int a, b, x, y;

		for (auto &s : rec) {
			sscanf(s.c_str(), "%d %d %d %d", &a, &b, &x, &y);
			bool in = 0;
			int v1, v2, v3, v4;

			for (auto se : seg) {
				sscanf(se.c_str(), "%d %d %d %d", &v1, &v2, &v3, &v4);
				if (v1 > a && v1 < x && v2 > b && v2 < y) {
					in = 1;
					break;
				}
				if (v3 > a && v3 < x && v4 > b && v4 < y) {
					in = 1;
					break;
				}
			}
			if (in) {
				ans[0] += ((x - a) * (y - b));
				continue;
			}
			for (auto se : seg) {
				sscanf(se.c_str(), "%d %d %d %d", &v1, &v2, &v3, &v4);
				point p1(v1, v2), p2(v3, v4);

				point r1(a, b), r2(a, y), r3(x, y), r4(x, b);
				point d1, d2;
				if (intersect2D_2Segments(p1, p2, r1, r2, d1, d2)) {
					in = 1;
					break;
				}
				if (intersect2D_2Segments(p1, p2, r2, r3, d1, d2)) {
					in = 1;
					break;
				}
				if (intersect2D_2Segments(p1, p2, r3, r4, d1, d2)) {
					in = 1;
					break;
				}
				if (intersect2D_2Segments(p1, p2, r4, r1, d1, d2)) {
					in = 1;
					break;
				}

			}
			if (in) {
				ans[1] += ((x - a) * (y - b));
				continue;
			}
		}
		return ans;
	}
};

int main() {

}
