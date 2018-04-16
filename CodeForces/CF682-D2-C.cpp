/*
    for every node if it will make other node sad the node must be deleted with it's subtree.
    using dfs while keeping the maximum sum between the current node and ancestors if the sum
    is greater than the node value the tree must be deleted.
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int head[N], nxt[N], to[N], no = 0;

long long cost[N];
int val[N];

void addedge(int a, int b, long long v) {
    nxt[no] = head[a];
    to[no] = b;
    cost[no] = v;
    head[a] = no++;
}

int sz[N];

void getsz(int idx) {
    sz[idx] = 1;
    for (int i = head[idx]; ~i; i = nxt[i]) {
        getsz(to[i]);
        sz[idx] += sz[to[i]];
    }
}

int ans = 0;

void dfs(int idx, long long v) {
    if (v > val[idx]) {
        ans += sz[idx];
        return;
    }

    for (int i = head[idx]; ~i; i = nxt[i]) {
        dfs(to[i], max(v + cost[i], cost[i]));
    }
}

int main() {

    int n;
    memset(head, -1, sizeof head);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", val + i);
    }

    int p;
    long long v;
    for (int i = 2; i <= n; ++i) {
        scanf("%d %lld", &p, &v);
        addedge(p, i, v);
    }
    getsz(1);
    dfs(1, 0);
    printf("%d", ans);
}
