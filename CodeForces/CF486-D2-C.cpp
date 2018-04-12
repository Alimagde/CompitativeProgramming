/*
    first count for every pair the minimum presses to make them equal ,we will consider the first half of the
    string so if the current position in the second half it will be mapped the first one, now we have
    3 cases :
    1 - the position after the range so the answer += p-range_start
    2 - the position before the range so the answer += range_end-p
    3 - the position in the range so the answer +=min(p-range_start,range_end-p)+(range_end-range_start)
 */
#include <bits/stdc++.h>

using namespace std;

char str[100005];

int getmn(char a, char b) {
    if (a > b) swap(a, b);
    return min(b - a, 1 + (a - 'a' + 'z' - b));
}


int main() {
    freopen("in.txt", "rt", stdin);
    int n, c;
    scanf("%d %d", &n, &c);
    scanf(" %s", str);
    int ans = 0;
    vector<int> pos;
    map<int, int> mp;
    for (int i = 0, j = n - 1; i < (n / 2) && i != j; ++i, --j) {
        if (str[i] != str[j]) {
            ans += getmn(str[i], str[j]);
            pos.push_back(i + 1);
        }
        mp[j + 1] = (i + 1);
    }
    if (n % 2) {
        if (c == (n / 2) + 1) {
            ans++;
            c--;
        } else if (c > (n / 2) + 1) {
            c = mp[c];
        }
    } else {
        if (c > (n / 2)) {
            c = mp[c];
        }
    }
    if (pos.size() == 0) {
        puts("0");
        return 0;
    }
    ans += (pos.back() - pos[0]);
    if (c <= pos[0]) {
        ans += (pos[0] - c);
    } else if (c >= pos.back()) {
        ans += (c - pos.back());
    } else {
        ans += min(c - pos[0], pos.back() - c);
    }
    printf("%d", ans);
}


