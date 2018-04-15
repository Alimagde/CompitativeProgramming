/*
    every node in the segment tree have 4 values : best prefix sum , best suffix sum , best on the
    segment and sum of the elements in the segment
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 65536;

struct node {
    long long b, bp, bs, s;
    bool dummy;

    node() {
        b = -1e15;
        bp = -1e15;
        bs = -1e15;
        s = 0;
        dummy = 1;
    };

    node(int i, int j, int k, int l) {
        b = i;
        bp = j;
        bs = k;
        s = l;
        dummy = 0;
    }

    void set(int i, int j, int k, int l) {
        b = i;
        bp = j;
        bs = k;
        s = l;
        dummy = 0;
    }
} seg[4 * N];

long long arr[N];

void build(int id, int s, int e) {
    if (s == e) {
        seg[id].set(arr[s], arr[s], arr[s], arr[s]);
        return;
    }
    int mid = s + (e - s) / 2;

    build(id * 2, s, mid);
    build(id * 2 + 1, mid + 1, e);

    node &l = seg[id * 2];
    node &r = seg[id * 2 + 1];
    long long sum = l.s + r.s;
    long long bs = max(max(r.bs, r.s), max(r.s + l.bs, sum));
    long long bp = max(max(l.bp, l.s), max(l.s + r.bp, sum));
    long long best = max(max(bs, bp), max(r.b, l.b));
    best = max(best, sum);
    best = max(best, l.bs + r.bp);
    seg[id].set(best, bp, bs, sum);
}

void update(int id, int s, int e, int idx, int v) {
    if (idx < s || idx > e) return;

    if (s == e) {
        seg[id].set(v, v, v, v);
        return;
    }
    int mid = s + (e - s) / 2;

    update(id * 2, s, mid, idx, v);
    update(id * 2 + 1, mid + 1, e, idx, v);

    node &l = seg[id * 2];
    node &r = seg[id * 2 + 1];


    long long sum = l.s + r.s;
    long long bs = max(max(r.bs, r.s), max(r.s + l.bs, sum));
    long long bp = max(max(l.bp, l.s), max(l.s + r.bp, sum));
    long long best = max(max(bs, bp), max(r.b, l.b));
    best = max(best, sum);
    best = max(best, l.bs + r.bp);
    seg[id].set(best, bp, bs, sum);
}

node query(int id, int s, int e, int x, int y) {
    if (e < x || s > y) {

        return node();
    }

    if (s >= x && e <= y) {
        return seg[id];
    }

    int mid = s + (e - s) / 2;

    node l = query(id * 2, s, mid, x, y);
    node r = query(id * 2 + 1, mid + 1, e, x, y);
    if (l.dummy) return r;
    if (r.dummy) return l;
    long long sum = l.s + r.s;
    long long bs = max(max(r.bs, r.s), max(r.s + l.bs, sum));
    long long bp = max(max(l.bp, l.s), max(l.s + r.bp, sum));
    long long best = max(max(bs, bp), max(r.b, l.b));
    best = max(best, sum);
    best = max(best, l.bs + r.bp);
    return node(best, bp, bs, sum);
}


int main() {

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", arr + i);
    }
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while (q--) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        if (t) {
            printf("%lld\n", query(1, 1, n, x, y).b);
        } else {
            update(1, 1, n, x, y);
        }

    }
}
