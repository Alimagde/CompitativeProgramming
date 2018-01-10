/*

 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int arr[2][N];
vector<int> tr;
vector<int> vote[2][N];
int n, t;

int ans[N];

int main() {

	scanf("%d %d", &n, &t);
	int v;
	char x;
	for (int i = 1; i <= n; ++i) {
		scanf(" %c%d", &x, &v);
		if (x == '-') {
			arr[0][v]++;
			vote[0][v].push_back(i);
		} else {
			arr[1][v]++;
			vote[1][v].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		arr[0][i] += arr[0][i - 1];
		arr[1][i] += arr[1][i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		int c = arr[1][i] - arr[1][i - 1];
		c += (arr[0][n] - (arr[0][i] - arr[0][i - 1]));
		//printf("%d %d <<\n",i,c);
		if (c == t) {

			tr.push_back(i);
		} else {
			for (auto x : vote[1][i])
				ans[x] = 1;
			for (auto x : vote[0][i])
				ans[x] = 2;
		}
	}
	if (tr.empty())
		tr.push_back(0);
	if (tr.size() == 1) {
		for (auto x : vote[1][tr[0]])
			ans[x] = 2;
		for (auto x : vote[0][tr[0]])
			ans[x] = 1;
		for (int i = 1; i <= n; ++i) {
			if (i == tr[0])
				continue;
			for (auto x : vote[1][i])
				ans[x] = 1;
			for (auto x : vote[0][i])
				ans[x] = 2;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == 1)
			puts("Lie");
		else if (ans[i] == 2)
			puts("Truth");
		else
			puts("Not defined");
	}
}
