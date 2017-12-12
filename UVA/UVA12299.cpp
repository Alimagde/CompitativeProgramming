/*
 in shift query update each value with the corresponding value and change the values in the original array
 other query is normal RMQ
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int seg[N * 4];
int arr[N];
int update(int id, int s, int e, int idx, int v) {
	if (idx < s || idx > e)
		return seg[id];
	if (s == e) {
		return seg[id] = v;
	}
	int mid = s + (e - s) / 2;
	return seg[id] = min(update(id * 2, s, mid, idx, v),
			update(id * 2 + 1, mid + 1, e, idx, v));
}

int query(int id, int s, int e, int f, int t) {
	if (s > t || f > e)
		return 1e9;
	if (s == e || (s >= f && e <= t)) {
		return seg[id];
	}
	int mid = s + (e - s) / 2;

	return min(query(id * 2, s, mid, f, t), query(id * 2 + 1, mid + 1, e, f, t));

}

char str[50];
int main() {

	int n, q;
	scanf("%d %d", &n, &q);
	int x;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		update(1, 1, n, i, x);
		arr[i] = x;
	}
	while (q--) {
		scanf(" %s", str);
		vector<int> num;
		int v = 0;
		for (int i = 6; str[i] != ')'; ++i) {
			if (str[i] == ',') {
				num.push_back(v);

				v = 0;
				continue;
			}
			v *= 10;
			v += (str[i] - '0');
		}
		num.push_back(v);

		if (str[0] == 'q') {
			printf("%d\n", query(1, 1, n, num[0], num[1]));
		} else {
			for (int i = 0; i + 1 < (int) num.size(); ++i) {
				update(1, 1, n, num[i], arr[num[i + 1]]);

			}
			update(1, 1, n, num.back(), arr[num[0]]);

			int v = arr[num[0]];

			for (int i = 0; i + 1 < (int) num.size(); ++i) {
				arr[num[i]] = arr[num[i + 1]];
			}

			arr[num.back()] = v;
		}
	}
}
