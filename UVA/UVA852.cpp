/*
 find all reachable point for both colors, a point is belong to a color if it unreachable form the other color
 */

#include <bits/stdc++.h>
using namespace std;

char arr[10][10];
int b, w, both;
int vis[10][10], vid = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool black[10][10];
bool white[10][10];

bool valid(int x, int y) {
	return (x > -1 && y > -1 && x < 9 && y < 9);
}

void whitedfs(int x, int y) {
	if (!valid(x, y) || vis[x][y] == vid || arr[x][y] == 'X')
		return;
	vis[x][y] = vid;
	white[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		whitedfs(x + dx[i], y + dy[i]);
	}
}

void blackdfs(int x, int y) {
	if (!valid(x, y) || vis[x][y] == vid || arr[x][y] == 'O')
		return;
	vis[x][y] = vid;
	black[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		blackdfs(x + dx[i], y + dy[i]);
	}
}

int main() {
//	freopen("in.txt", "rt", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				scanf(" %c", &arr[i][j]);
				black[i][j] = white[i][j] = 0;
			}

		}
		b = w = both = 0;
		++vid;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (arr[i][j] == 'X') {
					blackdfs(i, j);
				}
			}
		}
		++vid;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (arr[i][j] == 'O') {
					whitedfs(i, j);
				}
			}
		}
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (black[i][j] && !white[i][j])
					++b;
				if (!black[i][j] && white[i][j])
					++w;
			}
		}
		printf("Black %d White %d\n", b, w);
	}
}

