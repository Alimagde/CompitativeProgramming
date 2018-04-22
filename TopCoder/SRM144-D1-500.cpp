
/*
    there is 4 cases for the tickets:
    sorted = false , unique = false so the number of tickets = c^b
    sorted = false , unique = true so the number of tickets = cCb * b!
    sorted = true , unique = false so the number of tickets can be counted using dp
    sorted = true , unique = true so the number of tickets = cCb
 */

#include <bits/stdc++.h>

using namespace std;


unsigned long long nCr(unsigned long long n, unsigned long long r) {
    if (n == r)
        return 1;
    return nCr(n - 1, r) * n / (n - r);
}
struct tic {
    string s;
    long long cnt;

    bool operator<(const tic &x) const {
        if (cnt != x.cnt) return cnt < x.cnt;
        return (s < x.s);
    }
};

long long fact(int x) {
    long long v = 1;
    for (long long i = 2; i <= x; ++i) {
        v *= i;
    }
    return v;
}

long long memo1[10][101];

long long solves(int c, int l) {
    if (c == 0) return 1;
    long long &r = memo1[c][l];
    if (~r) return r;

    r = 0;
    for (int i = l; i <= 100; ++i) {
        r += solves(c - 1, i);
    }
    return r;
}


class Lottery {
public:
    vector<string> sortByOdds(vector<string> rules) {
        memset(memo1, -1, sizeof memo1);


        tic tc;

        int n, b;
        char s, u;
        vector<tic> vec;
        for (int i = 0; i < rules.size(); ++i) {
            string x = rules[i], st = "";
            for (int i = 0; i < (int)x.size(); ++i) {
                if (x[i] == ':') {
                    x = x.substr(i + 1);
                    break;
                }
                st += x[i];
            }
            sscanf(x.c_str(), "%d %d %c %c",&n, &b, &s, &u);

            long long v = 0;
            if (s == 'F' && u == 'F') {
                v = n;
                for (int i = 1; i < b; ++i) {
                    v *= n;
                }
            } else if (s == 'F' && u == 'T') {
                v = nCr(n,b) * fact(b);
            } else if (s == 'T' && u == 'F') {
                v = solves(b, 100 - n + 1);
            } else {
                v = nCr(n,b);
            }
            tc.s = st;
            tc.cnt = v;
            vec.push_back(tc);
        }
        sort(vec.begin(), vec.end());
        vector<string> ans;
        for (int i = 0; i < vec.size(); ++i) {
            ans.push_back(vec[i].s);
        }
        return ans;
    }
};

