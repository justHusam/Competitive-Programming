#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct UF {
	vector<int> p, r;
	UF(int n) {
		p = r = vector<int>(n);
		for (int a = 0; a < n; ++a)
			p[a] = a, r[a] = 1;
	}
	inline int find(int x) {
		if (x == p[x])
			return x;
		return p[x] = find(p[x]);
	}
	inline int link(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (r[x] > r[y])
				swap(x, y);
			p[x] = y;
			if (r[x] == r[y])
				++r[y];
		}
		return x != y;
	}
};

struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator<(const edge&e) const {
		return e.c < c;
	}
};

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		priority_queue<edge> qu;
		for (int i = 0; i < n; ++i) {
			char s[100];
			scanf("%s", s);
			int m;
			scanf("%d", &m);
			while (m--) {
				int u, c;
				scanf("%d%d", &u, &c);
				qu.push(edge(i, u - 1, c));
			}
		}
		ll res = 0;
		UF uf(n);
		while (!qu.empty()) {
			const edge t = qu.top();
			qu.pop();
			if (uf.link(t.u, t.v))
				res += ll(t.c);
		}
		cout << res << "\n";
	}
	return 0;
}
