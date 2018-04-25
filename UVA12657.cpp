/*
    for every box save the iterator of the list then apply the commands easily  
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

list<int>::iterator it[N];

int main() {

    int n, m;
    int tc = 1;
    while (~scanf("%d %d", &n, &m)) {
        list<int> l;
        bool r = 0;
        for (int i = 1; i <= n; ++i) {
            l.push_back(i);
            it[i] = (--l.end());
        }
        int t, x, y;
        while (m--) {
            scanf("%d", &t);
            if (t == 4) {
                r ^= 1;
                continue;
            }
            scanf("%d %d", &x, &y);
            if ((t == 2 && r == 0) || (t == 1 && r == 1)) {
                l.erase(it[x]);
                auto i = it[y];
                ++i;
                it[x] = l.insert(i, x);
            } else if ((t == 1 && r == 0) || (t == 2 && r == 1)) {
                l.erase(it[x]);
                it[x] = l.insert(it[y], x);
            } else if (t == 3) {
                *it[x]=y;
                *it[y]=x;
                auto a=it[x];
                auto b=it[y];
                it[x]=b;
                it[y]=a;
                //iter_swap(it[x], it[y]);
            }
        }
        if (r) {
            l.reverse();
        }
        int i = 1;
        long long ans = 0;
        for (auto x:l) {
            if (i) {
                ans += x;
            }
            i ^= 1;
        }
        printf("Case %d: %lld\n", tc++, ans);
    }
}
