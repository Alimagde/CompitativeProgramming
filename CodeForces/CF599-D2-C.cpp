/*
	count how many many sub arrays that the elements are in there right position if the array is sorted
 */
#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int tmp[100005];
map<int, deque<int> > mp;
const int N = 100000;
int cnt[N * 2];

int get(int i) {
	i++;
	long long r = 0;
	while (i) {
		r += cnt[i - 1];
		i -= i & -i;
	}
	return r;
}
void add(int i) {
	i++;
	while (i <= N) {
		cnt[i - 1] += 1;
		i += i & -i;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		tmp[i] = arr[i];
	}
	sort(tmp, tmp + n);
	for (int i = 0; i < n; ++i) {
		mp[tmp[i]].push_back(i);
	}

	int ans=0;
	for (int i = 0; i < n; ++i) {
		add(mp[arr[i]][0]);
		mp[arr[i]].pop_front();
		if(get(i)==i+1) ++ans;
	}
	printf("%d",ans);
}
