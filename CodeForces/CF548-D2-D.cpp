/*
 for each index find the range that the index have the minimum value then maximize the value
 with the range length then all range lengths from 1 to length can has value equal to index
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int val[N];
int l[N], r[N];
int arr[N];
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	stack<pair<int, int> > st;
	l[1] = 1;
	st.push(make_pair(-1e9, 0));
	st.push(make_pair(arr[1], 1));

	for (int i = 2; i <= n; ++i) {
		while (st.size() && st.top().first >= arr[i]) {
			st.pop();
		}

		l[i] = st.top().second + 1;

		st.push(make_pair(arr[i], i));
	}
	while (st.size())
		st.pop();

	r[n] = n;
	st.push(make_pair(-1e9, n + 1));
	st.push(make_pair(arr[n], n));

	for (int i = n - 1; i >= 1; --i) {
		while (st.size() && st.top().first >= arr[i]) {
			st.pop();
		}
		if (st.empty()) {
			r[i] = n;
		} else {
			r[i] = st.top().second - 1;
		}
		st.push(make_pair(arr[i], i));
	}
	val[n] = 1e9 + 5;
	r[n] = n;
	for (int i = 1; i <= n; ++i) {
		val[n] = min(arr[i], val[n]);
		val[r[i] - l[i] + 1] = max(val[r[i] - l[i] + 1], arr[i]);
	}
	int v = -1;
	for (int i = n; i > 0; --i) {
		v = max(v, val[i]);
		val[i] = v;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", val[i]);
	}
}
