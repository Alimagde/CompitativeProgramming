/*

 */
#include <bits/stdc++.h>
using namespace std;
int n, m, bb, cc;
int memo[1005][12];
int a[12], b[12], c[12], d[12];

int solve(int l, int id) {
	if (id == m) {
		if (l < 0)
			return -1e9;
		return 0;
	}
	if (l < 0)
		return -1e9;
	if (memo[l][id] != -1)
		return memo[l][id];

	int &ret = memo[l][id];
	ret = 0;
	ret = max(ret, solve(l - bb, id) + cc);
	ret = max(ret, solve(l , id+1));
	for(int i=1;i<=100;++i){
		if(i*b[id]>a[id]) break;
		ret=max(ret,(i*d[id])+solve(l-(i*c[id]),id+1));
	}
	return ret;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &bb, &cc);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
	}
	memset(memo, -1, sizeof memo);
	printf("%d", solve(n, 0));
}
