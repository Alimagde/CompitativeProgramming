/*
    first if k==0 the answer is k^(p-1) because f(0)-> 0 * f(0) and no other value [1,p-1] depends on the other
    second if k==1 the answer is k^p becaues every value depends on itself
    if k>1:
    let's make a graph with N vertices and for every x [0,p-1] merge (x*k)%p and x into one component
    if f(x) has value V and f((k*x)%b) -> k*f(x) so there is one value can be set to f((k*x)%b)
    so for every component if we choose one vertex and set it's value from [0,p-1] we can get the other
    values in the component.
    so the answer is p^(number_of_component-1).
 */

#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int par[N];
long long mod = 1e9 + 7;

void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
}

int getpar(int x) {
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}

void merge(int a, int b) {
    if (getpar(a) == getpar(b)) {
        return;
    }
    par[par[a]] = par[b];
}

int main() {
    long long p, k;
    scanf("%lld %lld", &p, &k);
    init(p);
    for (long long i = 0; i < p; ++i) {
        merge(i, (i * k) % p);
    }
    set<int> st;
    for (int i = 0; i < p; ++i) st.insert(getpar(i));

    long long ans = 1;
    long long pw = (int) st.size() - 1;
    if (k == 0) pw = p - 1;
    else if (k == 1) pw = p;
    while (pw--) {
        ans = (ans * p) % mod;
    }
    printf("%lld", ans);
}
