/*

 */
#include <bits/stdc++.h>
using namespace std;

bool ok[200005];
int pos[200005];
int arr[200005];

int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", arr + i);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		pos[x] = i;
	}
	int ans = 0, id = n, o = 0;
	for (int i = n; i > 0; --i) {
		while (ok[id]) {
			--id;
		}
		if (!id)
			break;

		if (pos[arr[i]] == id) {
			--id;
			++o;
		} else {
			ans += o + 1;
			o = 0;
			ok[pos[arr[i]]] = 1;
		}
	}
	printf("%d", ans);
}
