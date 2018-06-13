#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator<(const edge&e) const {
		return c < e.c;
	}
};

int n, m, p[100], best;
vector<edge> e;

int find(int v) {
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

int calc(int s) {
	int mn = 2e9, mx = 0, can = 0;
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (size_t i = s; i < e.size() && can != n - 1; ++i) {
		int a = find(e[i].u);
		int b = find(e[i].v);
		if (a != b) {
			++can;
			p[a] = b;
			mn = min(mn, e[i].c);
			mx = max(mx, e[i].c);
			if (mx - mn > best)
				return 2e9;
		}
	}
	if (can != n - 1)
		return 2e9;
	return mx - mn;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		e.clear();
		for (int i = 0; i < n; ++i)
			p[i] = i;
		int can = 0;
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			e.push_back(edge(u, v, c));
			u = find(u);
			v = find(v);
			if (u != v) {
				p[u] = v;
				++can;
			}
		}
		if (can != n - 1) {
			puts("-1");
			continue;
		}
		sort(e.begin(), e.end());
		best = 2e9;
		for (size_t i = 0; i < e.size(); ++i)
			best = min(best, calc(i));
		printf("%d\n", best);
	}
	return 0;
}
