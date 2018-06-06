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

int n, p[100], g[100][100];
vector<edge> e;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		e.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (g[i][j] != -1)
					e.push_back(edge(i, j, g[i][j]));
		sort(e.begin(), e.end());
		for (int i = 0; i < n; ++i)
			p[i] = i;
		int res = 0, cnt = 0;
		for (size_t i = 0; i < e.size(); ++i) {
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a != b) {
				res += e[i].c;
				p[a] = b;
				++cnt;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
