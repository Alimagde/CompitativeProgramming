/*
 first remove the component that contain cell x,y then find the maximum connected component size

 */

#include <bits/stdc++.h>
using namespace std;

char arr[25][25];
int n, m;

char l, w;

bool valid(int x, int y) {
	return (x > -1 && y > -1 && x < n && y < m && arr[x][y] == l);
}

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	arr[x][y] = w;
	int c = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = (((y + dy[i]) % m) + m) % m;
		if (valid(nx, ny))
			c += dfs(nx, ny);
	}
	return c;
}

int main() {

	while (~scanf(" %d %d", &n, &m)) {

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				scanf(" %c", &arr[i][j]);
		}
		int a, b;
		scanf("%d %d", &a, &b);
		l = arr[a][b];
		w = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] != l) {
					w = arr[i][j];
					break;
				}
			}
		}
		dfs(a, b);
		int c = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == l) {
					c = max(dfs(i, j), c);
				}
			}
		}
		printf("%d\n", c);
	}
}
