/*

 */
#include <bits/stdc++.h>
using namespace std;

int n, m;

bool valid(string &a, string &b) {
	int s1 = 0, p = 1, s2 = 0;

	for (auto x : a) {
		s1 += (p * (x - '0'));
		p *= 7;
	}
	p = 1;
	for (auto x : b) {
		s2 += (p * (x - '0'));
		p *= 7;
	}
	return (s1 < n && s2 < m);
}

int main() {

	scanf("%d %d", &n, &m);
	int a = 0, b = 0;
	vector<int> vec;
	for (int i = 0; i < 7; ++i) {
		vec.push_back(i);
	}
	int x;
	x = n - 1;

	while (x) {
		x /= 7;
		++a;
	}
	x = m - 1;
	while (x) {
		x /= 7;
		++b;
	}
	a = max(a, 1);
	b = max(b, 1);

	set<string> st;
	if (a + b > 7) {
		puts("0");
		return 0;
	}
	do {
		string aa = "", bb = "";
		for (int i = 0; i < a; ++i) {
			aa += '0' + vec[i];
		}
		for (int i = a; i < a + b; ++i) {
			bb += '0' + vec[i];
		}
		if (valid(aa, bb)) {
			aa += bb;
			st.insert(aa);
		}
	} while (next_permutation(vec.begin(), vec.end()));
	printf("%d\n", (int) st.size());
}
