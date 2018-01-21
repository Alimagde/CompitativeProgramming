#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	int c = 1;
	while (scanf("%d %d", &a, &b), a | b) {
		long long v1 = ((b - 1) * (b)) / 2;
		long long v2 = ((a - 1) * (a)) / 2;
		printf("Case %d: %lld\n", c++, v1 * v2);
	}
}
