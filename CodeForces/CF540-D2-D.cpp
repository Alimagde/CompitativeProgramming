#include <bits/stdc++.h>
using namespace std;

double memor[105][105][105], memos[105][105][105], memop[105][105][105];
int vis[105][105][105], vid = 0;

double solver(int r, int s, int p) {
	if (r == 0)
		return 0;
	if (p == 0)
		return 1;
	if (s == 0)
		return 0;

	double &res = memor[r][s][p];
	if (vis[r][s][p] == vid)
		return res;
	vis[r][s][p] = vid;
	double all = (r*s+s*p+p*r);
	res = 0;

	res += solver(r, s - 1, p) * ((r * s) / all);
	res += solver(r, s, p - 1) * ((s * p) / all);
	res += solver(r - 1, s, p) * ((r * p) / all);
	return res;
}

double solves(int r, int s, int p) {
	if (s == 0)
		return 0;
	if (r == 0)
		return 1;
	if (p == 0)
		return 0;

	double &res = memor[r][s][p];
	if (vis[r][s][p] == vid)
		return res;
	vis[r][s][p] = vid;
	
	double all = (r*s+s*p+p*r);
	res = 0;

	res += solves(r, s - 1, p) * ((r * s) / all);
	res += solves(r, s, p - 1) * ((s * p) / all);
	res += solves(r - 1, s, p) * ((r * p) / all);
	return res;
}

double solvep(int r, int s, int p) {
	if (p == 0)
		return 0;
	if (s == 0)
		return 1;
	if (r == 0)
		return 0;

	double &res = memor[r][s][p];
	if (vis[r][s][p] == vid)
		return res;
	
	vis[r][s][p] = vid;
	double all = (r*s+s*p+p*r);
	res = 0;

	res += solvep(r, s - 1, p) * ((r * s) / all);
	res += solvep(r, s, p - 1) * ((s * p) / all);
	res += solvep(r - 1, s, p) * ((r * p) / all);
	return res;
}
int main() {
	
	int r, s, p;
	scanf("%d %d %d", &r, &s, &p);
	++vid;
	printf("%.15lf", solver(r, s, p));
	++vid;
	printf(" %.15lf", solves(r, s, p));
	++vid;
	printf(" %.15lf", solvep(r, s, p));
}
