/*
	evaluate the expression with stack then re-construct the original expression with queue
 */
#include <bits/stdc++.h>
using namespace std;

struct expr {
	char c;
	stack<expr*> q;

	expr() {

	}
	expr(char x) {
		c = x;
	}

	void add(expr* x) {
		q.push(x);
	}

	expr* get() {
		expr *x = q.top();
		q.pop();
		return x;
	}
};

char str[10005];
expr ex[10005];
int main() {
//	freopen("in.txt", "rt", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", str);
		stack<expr*> st;

		for (int i = 0; str[i]; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				ex[i].c = str[i];
				while (ex[i].q.size())
					ex[i].q.pop();
				st.push(&ex[i]);
			} else {
				ex[i].c = str[i];
				while (ex[i].q.size())
					ex[i].q.pop();
				ex[i].add(st.top());
				st.pop();
				ex[i].add(st.top());
				st.pop();
				st.push(&ex[i]);
			}
		}
		deque<char> ans;
		queue<expr*> q;
		q.push(st.top());
		int sz = 0;
		while (q.size()) {
			expr *x = q.front();
			q.pop();
			if (x->q.size()) {
				str[sz++] = x->c;
				q.push(x->get());
				q.push(x->get());
			} else {
				str[sz++] = x->c;
			}
		}
		str[sz] = 0;
		reverse(str, str + sz);
		printf("%s\n", str);

	}
	return 0;
}
