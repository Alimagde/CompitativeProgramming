
#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k;
int memo[N][27];
int best[N][27];
char str[N];

int solve(int idx, int l) {
	if (idx == n)
		return 0;
	int &res = memo[idx][l];
	if (~res)
		return res;
	res = 1e9;
	int cur = str[idx] - 'A';
	if (l != cur) {
		res = min(res, solve(idx + 1, cur));
	}
	for (int i = 0; i < k; ++i) {
		if (i == l)
			continue;
		res = min(res, int(i != cur) + solve(idx + 1, i));

	}
	return res;
}

void print(int idx, int l) {
	if (idx == n)
		return;
	int &res = memo[idx][l];

	int cur = str[idx] - 'A';

	if (l != cur && solve(idx + 1, cur) == res) {
		printf("%c", 'A' + cur);
		print(idx + 1, cur);
		return;
	}

	for (int i = 0; i < k; ++i) {
		if (i == l)
			continue;
		int v = (i != cur);
		if (v + solve(idx + 1, i) == res) {
			printf("%c", 'A' + i);
			print(idx + 1, i);
			return;
		}

	}

}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &k);
	k = min(k, 5);
	scanf(" %s", str);

	printf("%d\n", solve(0, k));
	print(0, k);
}
