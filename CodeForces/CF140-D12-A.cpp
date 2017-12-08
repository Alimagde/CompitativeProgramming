/*

 */
#include <bits/stdc++.h>
using namespace std;

#define pi 3.14159265359


int main() {
	double n, R, r;
	scanf("%lf %lf %lf", &n, &R, &r);
	if (n == 1) {
		if (r <= R)
			puts("YES");
		else
			puts("NO");
		return 0;
	}
	double b=pi/n,a=(pi/2)-a;
	double x=r*sin(a)/sin(b);

	if(x<=R-r) puts("YES");
	else puts("NO");
}
