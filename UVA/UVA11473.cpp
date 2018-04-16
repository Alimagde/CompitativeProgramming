/*
    first calculate the distance between trees with is the distance of the road over the num_of_trees-1
    then walk over the segments till the distance for the next tree is less than the segment lenght
    then using binary search find the place of the tree on the segment
 */

#include <bits/stdc++.h>

using namespace std;

int main() {

    int z;
    scanf("%d", &z);
    for (int tc = 1; tc <= z; ++tc) {
        int n, t;
        scanf("%d %d", &n, &t);
        vector<pair<double, double> > vec(n);
        double dist = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &vec[i].first, &vec[i].second);

            if (i) {
                dist += hypot(vec[i].first - vec[i - 1].first, vec[i].second - vec[i - 1].second);
            }
        }
        double sp = dist / (t - 1);
        printf("Road #%d:\n", tc);
        double x = vec[0].first, y = vec[0].second;
        int id = 1;
        printf("%.2lf %.2lf\n", x, y);
        while (--t) {
            double v = sp;
            while (1) {
                double d = hypot(x - vec[id].first, y - vec[id].second);
                if (d < v) {
                    v -= d;
                    x = vec[id].first;
                    y = vec[id].second;
                    ++id;
                } else break;
            }
            double s = 0, e = 1.0;
            double dx = vec[id].first - x, dy = vec[id].second - y;
            for (int i = 0; i < 50; ++i) {
                double mid = (s + e) / 2;
                double dis = hypot(dx * mid, dy * mid);
                if (dis > v) {
                    e = mid;
                } else s = mid;
            }
            x += (s * dx);
            y += (s * dy);
            printf("%.2lf %.2lf\n", x, y);
        }
        puts("");
    }


}
