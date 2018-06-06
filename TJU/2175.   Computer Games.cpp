#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int a, b;
	state(int a, int b) :
			a(a), b(b) {
	}
	bool operator<(const state&e) const {
		int d1 = e.b - e.a, d2 = b - a;
		if (d1 != d2)
			return d1 < d2;
		return e.b > b;
	}
};

priority_queue<state> qu;
map<int, string> nm;
map<string, int> pt;
set<int> st;
char a[30], b[30];
set<int>::iterator it;

int main(int argc, char **argv) {
	int p, q;
	while (scanf("%d", &q) && q != 0) {
		while (!qu.empty())
			qu.pop();
		nm.clear();
		pt.clear();
		st.clear();
		while (q--) {
			scanf("%s", a);
			if (!strcmp(a, "Join")) {
				scanf("%s%d", b, &p);
				nm[p] = b;
				pt[b] = p;
				if (st.size() == 0)
					st.insert(p);
				else {
					it = st.lower_bound(p);
					if (it == st.end()) {
						--it;
						qu.push(state(*it, p));
					} else {
						qu.push(state(p, *it));
						if (it != st.begin()) {
							--it;
							qu.push(state(*it, p));
						}
					}
					st.insert(p);
				}
			} else if (!strcmp(a, "Leave")) {
				scanf("%s", b);
				if (pt.find(b) != pt.end()) {
					int v = pt[b];
					it = st.lower_bound(v);
					if (it != st.begin()) {
						int x = *(--it);
						++it;
						qu.push(state(x, *(++it)));
					}
					st.erase(v);
				}
			} else {
				if (st.size() < 2)
					puts("Poor Mr.Yu");
				else {
					bool ok = false;
					while (!qu.empty()) {
						state e = qu.top();
						if (st.find(e.a) == st.end() || st.find(e.b) == st.end()) {
							qu.pop();
							continue;
						}
						ok = true;
						printf("%s %s\n", nm[e.b].c_str(), nm[e.a].c_str());
						break;
					}
					if (!ok)
						puts("Poor Mr.Yu");
				}
			}
		}
		puts("");
	}
	return 0;
}
