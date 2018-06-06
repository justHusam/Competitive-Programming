#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int sz, mn;
	state(int sz, int mn) :
			sz(sz), mn(mn) {
	}
	bool operator<(const state&e) const {
		if (e.sz != sz)
			return e.sz < sz;
		return e.mn < mn;
	}
};

const int N = 1e4;
int p[N], sz[N], mn[N];
set<state> del;

int find(int v) {
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, q;
		scanf("%d%d", &n, &q);
		priority_queue<state> qu;
		for (int i = 0; i < n; ++i) {
			p[i] = mn[i] = i;
			sz[i] = 1;
			qu.push(state(1, i));
		}
		del.clear();
		while (q-- != 0) {
			char c;
			scanf(" %c", &c);
			if (c == '?') {
				while (del.find(qu.top()) != del.end())
					qu.pop();
				printf("%d %d\n", qu.top().sz, qu.top().mn + 1);
			} else {
				int a, b;
				scanf("%d%d", &a, &b);
				a = find(a - 1);
				b = find(b - 1);
				if (a == b)
					continue;
				del.insert(state(sz[a], mn[a]));
				del.insert(state(sz[b], mn[b]));
				p[a] = b;
				sz[b] += sz[a];
				mn[b] = min(mn[b], mn[a]);
				qu.push(state(sz[b], mn[b]));
			}
		}
	}
	return 0;
}
