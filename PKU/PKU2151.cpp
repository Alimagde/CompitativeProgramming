#include <stdio.h>
int n, pr, mn;

double memo[1005][31][31][3];
int vis[1005][31][31][3], vid;

double arr[1005][32];

double solve(int idx, int p, int cnt, bool b) {
	if (idx == n) {
		if (b)
			return 1;
		return 0;
	}
	if (p == pr) {
		if(cnt){
		return solve(idx + 1, 0, 0, b | (cnt >= mn));
		}
		return 0;
	}
	double &res = memo[idx][p][cnt][b];
	if (vis[idx][p][cnt][b] == vid)
		return res;
	vis[idx][p][cnt][b] = vid;
	res = 0;

	res += (solve(idx, p + 1, cnt + 1, b) * arr[idx][p]);
	res += (solve(idx, p + 1, cnt, b) * (1.0 - arr[idx][p]));
	return res;
}

int main() {

	while (scanf("%d %d %d", &pr, &n, &mn), pr | n | mn) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < pr; ++j)
				scanf("%lf", &arr[i][j]);
		}
		++vid;

		printf("%.3lf\n", solve(0, 0, 0, 0));

	}
}
