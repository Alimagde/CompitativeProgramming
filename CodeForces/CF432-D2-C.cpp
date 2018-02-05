#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool notp[N];
vector<int> primes;
void sieve() {
	for (int i = 2; i < N; ++i) {
		if (notp[i])
			continue;
		primes.push_back(i);
		for (int j = i * 2; j < N; j += i)
			notp[j] = 1;
	}
}

int arr[N];
int pos[N];

int main() {

	sieve();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		pos[arr[i]] = i;
	}
	vector<pair<int, int> > ans;
	for (int i = 1; i <= n; ++i) {
		int v = pos[i];
		while (v != i) {
			int pr = *(--upper_bound(primes.begin(), primes.end(), v - i + 1));
			swap(arr[v], arr[v - pr + 1]);
			ans.push_back(make_pair(v - pr + 1, v));
			pos[arr[v]] = v;
			v = v - pr + 1;
		}
	}
	printf("%d\n", (int) ans.size());
	for (auto x : ans)
		printf("%d %d\n", x.first, x.second);
}
