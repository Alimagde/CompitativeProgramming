	#include<bits/stdc++.h>
	using namespace std;
	
	char str[4005];
	
	int main() {
		
		int n;
		scanf("%d", &n);
		scanf(" %s", str);
		int l = strlen(str);
		if (n == 0) {
	
			long long cnt = 0;
			int z = 0;
			for (int i = 0; i < l; ++i) {
				int c = 0;
				for (int j = i; j < l; ++j) {
					c += str[j] - '0';
					if (c == 0) {
						++z;
					} else
						break;
				}
			}
			for (int i = 0; i < l; ++i) {
				int c = 0;
				for (int j = i; j < l; ++j) {
					c += str[j] - '0';
					if (c == 0) {
						cnt += ((l * (l + 1) / 2) - z) * 2ll;
					} else
						break;
				}
			}
			printf("%lld", cnt + (1ll * z * z));
		} else {
			map<int, int> mp;
			for (int i = 0; i < l; ++i) {
				int c = 0;
				for (int j = i; j < l; ++j) {
					c += str[j] - '0';
					mp[c]++;
				}
			}
			long long ans = 0;
			for (int i = 0; i < l; ++i) {
				int c = 0;
				for (int j = i; j < l; ++j) {
					c += str[j] - '0';
					if (c != 0 && ((n % c) == 0))
						ans += mp[n / c];
				}
			}
			printf("%lld", ans);
		}
	}
