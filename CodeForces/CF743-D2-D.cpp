/*
 we have to problem to solve ,first solve the maximum subtree sum in a subtree then solve the same problem
 put find the best two subtrees
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int head[N], nxt[N * 2], to[N * 2], no = 0;

void addedge(int a, int b) {
	nxt[no] = head[a];
	to[no] = b;
	head[a] = no++;
}

void addbiedge(int a, int b) {
	addedge(a, b);
	addedge(b, a);
}

long long arr[N];
long long sz[N];

long long memo1[N];
vector<long long> memo2[N];
bool vis1[N], vis2[N];

void getsz(int idx, int p) {
	sz[idx] = arr[idx];
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		getsz(to[i], idx);
		sz[idx] += sz[to[i]];
	}
}

long long solve1(int idx, int p) {
	if (vis1[idx])
		return memo1[idx];
	vis1[idx] = 1;
	memo1[idx] = sz[idx];
	long long &r = memo1[idx];
	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		r = max(r, solve1(to[i], idx));
	}
	return r;
}

void update(vector<long long> &v, long long val) {
	if (v.size() == 0) {
		v.push_back(val);
	} else if (v.size() == 1) {
		v.push_back(val);
		if (v[0] > v[1])
			swap(v[0], v[1]);
	} else {
		if (val > v[1]) {
			v[0] = v[1];
			v[1] = val;
		} else if (val > v[0]) {
			v[0] = val;
		}
	}
}

vector<long long> solve2(int idx, int p) {
	if (vis2[idx])
		return memo2[idx];

	vis2[idx] = 1;
	vector<long long> &v = memo2[idx];

	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		update(v, solve1(to[i], idx));
	}

	for (int i = head[idx]; ~i; i = nxt[i]) {
		if (to[i] == p)
			continue;
		vector<long long> t = solve2(to[i], idx);
		if (v.size() < 2) {
			v = t;
		} else {
			if ((int) t.size() == 2 && t[0] + t[1] > v[0] + v[1]) {
				v = t;
			}
		}
	}
	return v;
}

int main() {

	int n;
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", arr + i);
	}
	int x, y;
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &x, &y);
		addbiedge(x, y);
	}
	getsz(1, -1);
	vector<long long> v = solve2(1, -1);

	if (v.size() == 2) {
		printf("%lld", v[0] + v[1]);
	}

	else
		puts("Impossible");
}
