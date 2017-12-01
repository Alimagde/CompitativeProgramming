/*

 	if(n/k<3) then the answer is -1
 	else put first 2 elements of each group in sequence 1 1 2 2 . . .k k
  	then devide the rest n-2*k elements over the k
 */


#include <bits/stdc++.h>
using namespace std;

int arr[1000006];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if ((n / k) < 3) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < k; ++i) {
		printf("%d %d ", i + 1, i + 1);
	}
	int idx = 0;
	for (int i = k * 2; i < n; ++i) {
		printf("%d ", ++idx);
		idx %= k;
	}
}
