#include <bits/stdc++.h>
using namespace std;

struct state {
	int a, b, c;
	state(int a, int b, int c) :
			a(a), b(b), c(c) {
	}
	bool operator<(const state&e) const {
		if (e.c != c)
			return e.c < c;
		return e.a < a;
	}
};

int n, k;
set<int> st;
priority_queue<state> qu;
set<int>::iterator it;
set<pair<int, int> > vis;

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &k) && (n || k)) {
		while (!qu.empty())
			qu.pop();
		st.clear();
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			st.insert(x);
		}
		it = st.begin();
		int x = *it;
		for (++it; it != st.end(); ++it) {
			qu.push(state(x, *it, *it - x));
			x = *it;
		}
		vis.clear();
		while (k > 1) {
			state e = qu.top();
			qu.pop();
			if (vis.find(make_pair(e.a, e.b)) != vis.end())
				continue;
			--k;
			vis.insert(make_pair(e.a, e.b));
			it = st.lower_bound(e.a);
			if (it != st.begin()) {
				int x = *(--it);
				qu.push(state(x, e.b, e.b - x));
			}
			it = st.lower_bound(e.b);
			++it;
			if (it != st.end())
				qu.push(state(e.a, *it, *it - e.a));
		}
		while (true) {
			state e = qu.top();
			if (vis.find(make_pair(e.a, e.b)) == vis.end())
				break;
			qu.pop();
		}
		printf("%d %d\n", qu.top().a, qu.top().b);
	}
	return 0;
}
