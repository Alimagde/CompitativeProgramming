/*

 */
#include <bits/stdc++.h>
using namespace std;
int val[5005];
int n,m;
double ans=0;
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",val+i);
	}

	for (int i = 0; i < m; ++i) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		ans=max(ans,(val[a]+val[b])/(1.0*c));
	}

	printf("%.15lf", ans);
}
