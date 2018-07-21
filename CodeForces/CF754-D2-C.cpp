/*
 for every line that have no sender find the that is not mentioned in the line
 then using dynamic programming find a valid solution that satisfy the constrains
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
int vis[105][105], vid = 0;
bool pr;

int user[105];
set<int> canbe[105];
string name[105];
string lines[105];

bool notchar(char &c) {

	if (c >= '0' && c <= '9')
		return 0;
	if (c >= 'a' && c <= 'z')
		return 0;
	if (c >= 'A' && c <= 'Z')
		return 0;
	return 1;
}

int solve(int idx, int l) {
	if (idx == m) {
		pr = 1;
		for (int i = 0; i < m; ++i) {
			cout << name[user[i]] << lines[i] << "\n";
		}
		return 1;
	}
	if (user[idx] != -1) {
		if (l == user[idx])
			return 0;
		return solve(idx + 1, user[idx]);
	}
	if (vis[idx][l] == vid)
		return 0;

	vis[idx][l] = vid;
	bool mem = 0;

	for (auto x : canbe[idx]) {
		if (x == l)
			continue;
		user[idx] = x;
		mem |= solve(idx + 1, x);
		if (mem)
			return 1;
		user[idx] = -1;
	}
	return 0;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		map<string, int> mp;
		for (int i = 1; i <= n; ++i) {
			cin >> name[i];
			mp[name[i]] = i;
		}
		cin >> m;
		cin.ignore();

		for (int i = 0; i < m; ++i) {
			getline(cin, lines[i]);
			string &line = lines[i];
			if (line[0] == '?') {
				line = line.substr(1);
				string x = "";
				canbe[i].clear();
				for (int u = 1; u <= n; ++u) {
					canbe[i].insert(u);
				}
				for (auto &c : line) {
					if (notchar(c)) {
						int id = mp[x];
						if (id) {
							canbe[i].erase(id);
						}
						x = "";
					} else
						x += c;
				}
				int id = mp[x];
				if (id) {
					canbe[i].erase(id);
				}
				user[i] = -1;
			} else {
				size_t pos = line.find(":");
				int id = mp[line.substr(0, pos)];
				line = line.substr(pos);
				user[i] = id;

			}
		}
		++vid;
		pr = 0;
		solve(0, 0);
		if (!pr)
			cout << "Impossible" << "\n";
	}
}
