/*
 for every path in the tree get the maximum path in all subtrees having a root not
 exist on the path and the answer for the path is the maximum path X path length
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = N * 2;

int head[N], nxt[M], to[M], ne = 0;
int dep[N][N];
int len[N][N];
int ans = 0;
void init() {
	memset(head, -1, sizeof head);
	memset(dep, -1, sizeof dep);
	memset(len, -1, sizeof len);
}

void addedge(int a, int b) {
	nxt[ne] = head[a];
	to[ne] = b;
	head[a] = ne++;
}

void addbiedge(int a, int b) {
	addedge(a, b);
	addedge(b, a);
}

int maxdepth(int idx, int p) {
	if (~dep[idx][p])
		return dep[idx][p];
	int &res = dep[idx][p];
	res = 0;
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		res = max(res, 1 + maxdepth(to[i], idx));
	}
	return res;
}

int maxlen(int idx, int p) {
	if (~len[idx][p])
		return len[idx][p];
	int &res = len[idx][p];
	res = 0;
	vector<int> vec;
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		res = max(res, maxlen(to[i], idx));
		int v = maxdepth(to[i], idx);
		vec.push_back(v);
		res = max(res, 1 + v);
	}
	sort(vec.begin(), vec.end());
	if (vec.size() > 1) {
		res = max(res, 2 + vec[vec.size() - 1] + vec[vec.size() - 2]);
	}
	return res;
}

void dfs(int idx, int p, int len, int mx) {
	ans = max(ans, mx * len);
	multiset<int> st;
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		st.insert(maxlen(to[i], idx));
	}

	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		int v = maxlen(to[i], idx);
		st.erase(st.find(v));
		int x = 0;
		if (st.size())
			x = *(--st.end());
		dfs(to[i], idx, len + 1, max(mx, x));
		st.insert(v);
	}

}

int main() {

	init();
	int n;
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &x, &y);
		addbiedge(x, y);
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i, 0, 0, 0);
	}
	printf("%d", ans);
}
