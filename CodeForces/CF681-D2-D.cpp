/*
    for every parent P that any child want to give a gift this condition must hold:
    no child can give a give a gift to X such that X is ancestor to P , special cae if any child can give a gift
    to P iff p want to give a gift for himself.
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

vector<int> c[N];
int id[N];
bool r[N];
int want[N];
bool can = 1;
int deg[N], d;
int lev[N];
bool vis[N];

int dfs(int idx, int l) {
    lev[idx] = l;
    int lv = 1e9;
    if (c[idx].empty()) {
        deg[idx] = d--;
        return lev[want[idx]];
    }

    for (auto x:c[idx]) {
        lv = min(lv, dfs(x, l + 1));
    }
    if (vis[idx]) {
        if (lv > l) {
            deg[idx] = d--;
        } else if (lv == l) {
            if (want[idx] == idx) {
                deg[idx] = d--;
            } else can = 0;
        } else {
            can = 0;
        }
    }
    return min(lv, lev[want[idx]]);
}


int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    int x, y;
    d = n;
    while (m--) {
        scanf("%d %d", &x, &y);
        c[x].push_back(y);
        r[y] = 1;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        scanf("%d", want + i);
        st.insert(want[i]);
        vis[want[i]] = 1;
    }
    vector<int> vec;
    for (auto x:st) vec.push_back(x);

    for (int i = 1; i <= n; i++) {
        if (!r[i]) {
            dfs(i, 1);
        }
    }
    if (!can) puts("-1");
    else {
        sort(vec.begin(), vec.end(), [](int a, int b) {
            return deg[a] > deg[b];
        });
        printf("%d\n", vec.size());
        for (auto x:vec) printf("%d\n", x);
    }
}
