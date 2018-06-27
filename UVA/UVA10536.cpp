/*
 let's represent the grid by an integer so we have three options

 1 - the grid is full so it is a winning state.
 2 - if a state going to only winning states so it's losing state.
 3 - if a state going to at least one losing state it's a wining state.
 */
#include <bits/stdc++.h>
using namespace std;

int memo[(1 << 16) + 5];

int solve(int g) {
	if ((g + 1) == (1 << 16))
		return 1;
	if (~memo[g])
		return memo[g];
	int &res = memo[g];
	res = 0;
	for (int i = 0; i < 4; ++i) {
		int v = g;
		int c = i;
		int x = 3;
		while (x--) {
			if ((g >> c) & 1)
				break;
			v |= (1 << c);
			res |= !solve(v);
			c += 4;
		}
		v = g;
		c = i + 12;
		x = 3;
		while (x--) {
			if ((g >> c) & 1)
				break;
			v |= (1 << c);
			res |= !solve(v);
			c -= 4;
		}
	}

	for (int i = 0; i < 16; i += 4) {
		int v = g;
		int c = i;
		int x = 3;
		while (x--) {
			if ((g >> c) & 1)
				break;
			v |= (1 << c);
			res |= !solve(v);
			c++;
		}
		v = g;
		c = i + 3;
		x = 3;
		while (x--) {
			if ((g >> c) & 1)
				break;
			v |= (1 << c);
			res |= !solve(v);
			c--;
		}
	}
	for (int i = 0; i < 16; ++i) {
		if ((g >> i) & 1)
			continue;
		res |= !solve(g | (1 << i));
	}
	return res;
}

int main() {

	memset(memo, -1, sizeof memo);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char x;
		int g = 0;
		for (int i = 0; i < 16; ++i) {
			scanf(" %c", &x);
			if (x == 'X') {
				g |= (1 << i);
			}
		}
		if (solve(g)) {
			puts("WINNING");
		} else
			puts("LOSING");
	}
}
