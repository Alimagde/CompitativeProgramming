#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<pair<int, int>> vec(3);
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &vec[i].first, &vec[i].second);
	}

	if (vec[0].first == vec[1].first && vec[0].first == vec[2].first) {
		puts("1");
		return 0;
	}

	if (vec[0].second == vec[1].second && vec[0].second == vec[2].second) {
		puts("1");
		return 0;
	}

	for (int i = 0; i < 3; ++i) {
		int j = (i + 1) % 3, k = 3 - (i + j);

		if (vec[i].first == vec[j].first && vec[i].second == vec[k].second) {
			puts("2");
			return 0;
		}
		if (vec[i].first == vec[k].first && vec[i].second == vec[j].second) {
			puts("2");
			return 0;
		}

		int a = vec[i].first, b = vec[j].first;
		if (a > b)
			swap(a, b);
		if (vec[i].second == vec[j].second
				&& (vec[k].first < a || vec[k].first > b)) {
			puts("2");
			return 0;
		}

		a = vec[i].second;
		b = vec[j].second;
		if (a > b)
			swap(a, b);
		if (vec[i].first == vec[j].first
				&& (vec[k].second < a || vec[k].second > b)) {
			puts("2");
			return 0;
		}
	}
	puts("3");
}
