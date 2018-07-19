#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int arr[N];

multiset<int> st[N * 4];
int n, k;

void build(int id, int s, int e) {
	if (s == e) {
		st[id].clear();
		st[id].insert(k);
		return;
	}
	int mid = s + (e - s) / 2;

	build(id * 2, s, mid);
	build(id * 2 + 1, mid + 1, e);
	st[id].clear();
	for (int i = s; i <= e; ++i) {
		st[id].insert(k);
	}

}
int c;
int val;

bool f(multiset<int> &s) {
	return (s.lower_bound(c) != s.end());
}

void query(int id, int s, int e) {
	if (s == e) {
		val = arr[s];
		arr[s] -= c;
		st[id].clear();
		st[id].insert(arr[s]);
		return;
	}

	int mid = s + (e - s) / 2;

	if (f(st[id * 2])) {
		query(id * 2, s, mid);
	} else {
		query(id * 2 + 1, mid + 1, e);
	}
	st[id].erase(st[id].find(val));
	st[id].insert(val - c);
}

vector<int> gt(string &s) {
	int v = 0;
	int i = 0;
	if (s[0] == 'b') {
		i += 2;
	}
	vector<int> ans;
	for (; i < s.size(); ++i) {
		if (s[i] == ' ') {
			ans.push_back(v);
			v = 0;
		} else {
			v *= 10;
			v += s[i] - '0';
		}
	}
	ans.push_back(v);
	return ans;
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> k;
		cin >> n;
		int all = min(n, 100000);
		for (int i = 0; i < all; ++i)
			arr[i] = k;
		string x;
		cin.ignore();
		build(1, 0, all - 1);
		vector<int> vals;
		while (n) {
			getline(cin, x);
			vals = gt(x);
			if (vals.size() == 1) {
				c = vals[0];
				query(1, 0, all - 1);
				n--;
			} else {
				n -= vals[0];
				while (vals[0]--) {
					c = vals[1];
					query(1, 0, all - 1);
				}
			}
		}
		int w = 0, c = 0;
		for (int i = 0; i < all; ++i) {
			if (arr[i] == k)
				break;
			w += arr[i];
			++c;
		}
		cout << c << " " << w << "\n";
	}
}
