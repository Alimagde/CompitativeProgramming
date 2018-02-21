/*

 */
#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-13

int main() {

	vector<pair<pair<double, double>, pair<double, double> > > req;
	vector<pair<double, pair<double, double> > > cir;
	vector<int> cirid, reqid;
	char f;
	double x1, x2, y1, y2, r;
	int id = 1;
	while (scanf(" %c", &f), f != '*') {

		if (f == 'c') {
			scanf("%lf %lf %lf", &x1, &y1, &r);
			cir.push_back(make_pair(r, make_pair(x1, y1)));
			cirid.push_back(id++);
		} else {
			scanf("%lf %lf %lf %lf", &x1, &y2, &x2, &y1);
			req.push_back(make_pair(make_pair(x1, x2), make_pair(y1, y2)));
			reqid.push_back(id++);
		}
	}

	int p = 0;
	while (~scanf("%lf %lf", &x1, &y1), x1 < 9999.9 && y1 < 9999.9) {
		++p;
		vector<int> ans;
		for (int i = 0; i < (int) cir.size(); ++i) {
			auto &c = cir[i];
			double d = (x1 - c.second.first) * (x1 - c.second.first)
					+ (y1 - c.second.second) * (y1 - c.second.second);

			if ((c.first * c.first) - d > EPS) {
				ans.push_back(cirid[i]);
			}
		}
		for (int i = 0; i < (int) req.size(); ++i) {
			auto &re = req[i];
			bool b = 1;
			if (fabs(x1 - re.first.first) < EPS)
				b = 0;
			if (fabs(x1 - re.first.second) < EPS)
				b = 0;
			if (fabs(y1 - re.second.first) < EPS)
				b = 0;
			if (fabs(y1 - re.second.second) < EPS)
				b = 0;

			if (b) {
				if (x1 > re.first.first && x1 < re.first.second
						&& y1 > re.second.first && y1 < re.second.second)
					ans.push_back(reqid[i]);
			}
		}
		if (ans.size()) {
			sort(ans.begin(), ans.end());
			for (auto fe : ans) {
				printf("Point %d is contained in figure %d\n", p, fe);
			}
		} else
			printf("Point %d is not contained in any figure\n", p);
	}
}
