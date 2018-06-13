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

int n, m, k, p[200], v[200];
vector<edge> e;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		for (int i = 0; i < k; ++i) {
			scanf("%d", &v[i]);
			--v[i];
		}
		for (int i = 1; i < k; ++i)
			p[find(v[i])] = find(v[0]);
		e.clear();
		while (m--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			e.push_back(edge(u, v, c));
		}
		sort(e.begin(), e.end());
		int res = 0;
		for (size_t i = 0; i < e.size(); ++i) {
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a != b) {
				p[a] = b;
				res += e[i].c;
			}
		}
		printf("Case #%d: %d\n", cas++, res);
	}
	return 0;
}
