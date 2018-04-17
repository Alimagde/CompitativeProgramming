/*
 for every point on the x_axis try every possible slope and then count the lattice points on the line
 if greater than or equal to K the answer wll incremented by nCk
 if K equal one the answer is all lattice points in the grid
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
const int mod = 1e9 + 7;
const int MAX = 205;
int comb[MAX + 5][MAX + 5];

void calcCombinations() {
    comb[0][0] = 1;
    for (int i = 1; i <= MAX; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }
}

class SpacetskE {
public:
    int countsets(int L, int H, int K) {
        if (K == 1) {
            return (L + 1) * (H + 1);
        }
        map<pair<int, int>, int> mp;
        calcCombinations();

        int ans = 0;
        for (int j = -200; j <= 200; ++j) {
            for (int k = 0; k <= 200; ++k) {
                if (k == 0) continue;
                int dx = j, dy = k;
                int v = abs(__gcd(dx, dy));
                dx /= v;
                dy /= v;
                mp[{dx, dy}];
            }
        }
        for (int i = 0; i <= L; ++i) {
            for (map<pair<int, int>, int>::iterator x = mp.begin(); x != mp.end(); ++x) {
                int dx = x->first.first, dy = x->first.second;

                if (dx + i < 0 || dx + i > L || dy > H) continue;
                int fx = i, fy;

                int s = 1, e = 200;
                while (s < e) {
                    int mid = s + (e - s + 1) / 2;
                    fx=i+dx*mid;
                    fy=dy*mid;
                    if (fx < 0 || fx > L || fy > H){
                        e=mid-1;
                    }
                    else s=mid;
                }

                fx=i+dx*s;
                fy=dy*s;
                int v = abs(__gcd(fx - i, fy)) + 1;
                if (v >= K) {
                    ans = (ans + comb[v][K]) % mod;
                }
            }
        }
        return ans;
    }
};
