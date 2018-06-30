#include <bits/stdc++.h>

using namespace std;
int n, m;

int vis[66][33][101], vid = 0;
long long memo[66][33][101];

long long solve(int i, int l, int md) {
    if (l < 0) return 0;
    if (i == -1) {
        
        if ((l == 0) && (md == 0)){
            
            return 1ll;
        }
        return 0ll;
    }
    if (vis[i][l][md] == vid) return memo[i][l][md];
    vis[i][l][md] = vid;
    long long &res=memo[i][l][md];
    res=0;
    res+=solve(i-1,l,md);
    res+=solve(i-1,l-1,(0ll+md+(1ll<<i))%m);

    return res;
}


int main() {

    int z;
    scanf("%d", &z);
    for (int tc = 1; tc <= z; ++tc) {
        scanf("%d %d", &n, &m);
        printf("Case %d: ", tc);
        if (n % 2 || !m) {
            puts("0");
            continue;
        }

        ++vid;
        printf("%lld\n", solve(n - 2, (n / 2) - 1, (1ull << (n - 1)) % m));
    }
    return 0;
}
