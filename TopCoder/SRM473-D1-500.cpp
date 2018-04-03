/*
 first we need to color the points, using bit and binary search we can find the first non red point, after that we need
 to calculate the right triangles , a right triangle in a circle has the hypotenuse equal to the circle diameter so for
 half of the points check if it is red and the opposite point is red, let this count = x , so the answer = x*(points-2).
 if places is odd the answer is 0
 */
#include <vector>
#include <list>
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

struct BIT {
	vector<long long> v;

	BIT(int s) {
		resize(s);
	}
	void clear() {
		v.clear();
	}

	BIT() {
	}

	void resize(int s) {
		s = 1 << (int) ceil(log(1.0 * s) / log(2.) + 1e-9);
		v.resize(s, 0);
	}

	long long get(int i) {
		i++;
		long long r = 0;
		while (i) {
			r += v[i - 1];
			i -= i & -i;
		}
		return r;
	}

	void add(int i, long long val) {
		i++;
		while (i <= (int) v.size()) {
			v[i - 1] += val;
			i += i & -i;
		}
	}

	int find(long long val) {
		int s = 0;
		int m = v.size() >> 1;
		while (m) {
			if (v[s + m - 1] < val)
				val -= v[(s += m) - 1];
			m >>= 1;
		}
		return s;
	}
};

bool col[1000006];

class RightTriangle {
public:
	long long triangleCount(int places, int points, int a, int b, int c) {
		if (places % 2)
			return 0;

		BIT bit(places);
		for (long long i = 0; i < points; ++i) {
			long long v = (((i * i) % places) * a) % places;
			v = (v + (i * b)) % places;
			v = (v + c) % places;

			if (!col[v]) {
				col[v] = 1;
				bit.add(v, 1);
				continue;
			}

			int s = v, e = places - 1;
			if (bit.get(places - 1) - bit.get(v - 1) == places - v) {
				e = v - 1;
				s = 0;
			}

			while (s < e) {
				int mid = s + (e - s) / 2;
				if (bit.get(mid) - bit.get(s - 1) == (mid - s + 1)) {
					s = mid + 1;
				} else
					e = mid;
			}
			col[s] = 1;
			bit.add(s, 1);
		}
		long long ans = 0;
		for (int j = 0; j < (places / 2); ++j) {
			if (col[j] && col[j + (places / 2)]) {
				ans += (points - 2);
				col[j] = 0;
				col[j + (places / 2)] = 0;
			}
		}
		return ans;
	}
};

