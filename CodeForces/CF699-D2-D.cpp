/*
 initially every vertex's parent is itself for every vertex if the link with the parent will not
 cause a cycle the link is valid else the vertex is a root.
 if there is multiple roots choose one that was root with initial input and link the other roots
 with it
 
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int par[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
}

int getpar(int x) {
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}

int arr[N];
int ans[N];

int main() {

    int n, p;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
    }
    for (int i = n; i > 0; --i) {
        p = arr[i];

        if (i != getpar(p)) {
            par[i] = par[p];
            ans[i] = p;
        } else ans[i] = i;
    }
    vector<int> roots;

    for (int i = 1; i <= n; ++i) {
        if (getpar(i) == i) {
            roots.push_back(i);
        }
    }
    int r = roots[0];
    for (int i = 0; i < roots.size(); ++i) {
        if (arr[roots[i]] == roots[i]) {
            r = roots[i];
        }
    }

    for (int i = 0; i < roots.size(); ++i) {
        ans[roots[i]] = r;
    }
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] != ans[i]) ++c;
    }
    printf("%d\n", c);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
}
