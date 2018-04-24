/*
    every word represented by two variables x and y x is the word and y is the opposite
    initially every variable in a component
    
    1 - if word A and B are the same merge(Ax,Bx) merge(Ay,By)
    
    2 - if word A and B are not the same merge(Ax,By) merge(Ay,Bx)
    
    answering the queries is to check that the words the same or opposite or neither
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

int par[N * 2];

void init(int n) {
    for (int i = 0; i < n * 2; ++i) par[i] = i;
}

int getpar(int x) {
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}

void merge(int a, int b) {
    if (getpar(a) == getpar(b)) return;
    par[par[a]] = par[b];
}

void mergewords(int a, int b) {
    merge(a, b);
    merge(a ^ 1, b ^ 1);

}

char str[105];

int main() {
    
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    map<string, int> mp;
    init(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        string x(str);
        mp[x] = i;
    }
    int t;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t);
        scanf("%s", str);
        string x(str);
        scanf("%s", str);
        string y(str);
        int a = mp[x] * 2, b = mp[y] * 2;
        if (t == 1) {
            if (getpar(a) == getpar(b ^ 1)) {
                puts("NO");
            } else {
                puts("YES");
                mergewords(a, b);
            }
        } else {
            if (getpar(a) == getpar(b)) {
                puts("NO");
            } else {
                puts("YES");
                mergewords(a, b ^ 1);
            }
        }
    }
    while (q--) {
        scanf("%s", str);
        string x(str);
        scanf("%s", str);
        string y(str);
        int a = mp[x] * 2, b = mp[y] * 2;

        if (getpar(a) == getpar(b)) {
            puts("1");
        } else if (getpar(a) == getpar(b ^ 1)) {
            puts("2");
        } else puts("3");

    }
}
