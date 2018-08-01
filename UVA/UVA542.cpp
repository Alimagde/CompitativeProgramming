#include <bits/stdc++.h>
using namespace std;

int win[20][20];

char name[20][20];

void printstr(int id) {
	int l = strlen(name[id]);
	printf("%s", name[id]);
	l = 10 - l;
	while (l--)
		printf(" ");
}

int main() {

	for (int i = 0; i < 16; ++i)
		scanf(" %s", name[i]);

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			scanf("%d", &win[i][j]);
		}
	}

	vector<double> cur(16, 1.0);
	for (int i = 2; i <= 16; i *= 2) {
		vector<double> nxt(16, 0.0);
		int last = i / 2;
		for (int j = 0; j < 16; ++j) {
			for (int k = 0; k < 16; ++k) {
				if (j == k)
					continue;
				if ((j / i) == (k / i) && ((j / last) != (k / last))) {
					nxt[j] += (cur[j] * cur[k] * (win[j][k] / 100.0));
				}
			}
		}
		cur = nxt;

	}

	for (int i = 0; i < 16; ++i) {
		printstr(i);
		printf(" p=%.2lf%\n", cur[i] * 100);
	}
}
