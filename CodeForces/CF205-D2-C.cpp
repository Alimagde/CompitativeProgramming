/*

 */

#include <bits/stdc++.h>
using namespace std;

long long memo[20][3][3];
char arr[20];

long long solve(int i, int l, int c) {

	if (arr[i + 1] == 0) {
		if (l == 0 && c > 0)
			return 0ll;
		return 1ll;
	}
	if (memo[i][l][c] != -1)
		return memo[i][l][c];
	long long &ret = memo[i][l][c];

	ret = 0;
	if (l) {
		for (char a = '0'; a <= '9'; ++a) {
			ret += solve(i + 1, l, c);
		}
	} else {
		for (char a = '0'; a <= arr[i]; ++a) {
			ret += solve(i + 1, a < arr[i], c);
		}
	}
	return ret;
}
long long np[22];

void precalc() {
	np[0] = 1;
	for (int i = 1; i < 20; ++i)
		np[i] = 10 * np[i - 1];
}

long long getval(int i) {
	if (i == 1 || i == 2)
		return 9;
	return 9 * np[i - 2];
}

int main() {
	precalc();
	long long v1 = 0, v2 = 0;
	scanf("%s", arr);
	memset(memo, -1, sizeof memo);

	for (char x = '1'; x <= arr[0]; ++x) {
		v1 += solve(1, x < arr[0], x > arr[(int) strlen(arr) - 1]);
	}
	for (int i = 1; i < (int) strlen(arr); ++i)
		v1 += getval(i);

	int x = arr[strlen(arr) - 1] - '0';
	if (x == (arr[0] - '0'))
		x = 1;
	else
		x = 0;
	scanf("%s", arr);
	memset(memo, -1, sizeof memo);
	for (char x = '1'; x <= arr[0]; ++x) {
		v2 += solve(1, x < arr[0], x > arr[(int) strlen(arr) - 1]);
	}
	for (int i = 1; i < (int) strlen(arr); ++i)
		v2 += getval(i);

	v2 -= v1;
	v2 += x;
	printf("%lld", v2);

}
