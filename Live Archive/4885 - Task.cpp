#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
};

const int N = 101, oo = 1e9;
int n, m, cost[N], E[N][N];
vector<edge> e;
char s[N];

inline void addEdge(int u, int v, int c) {
	e.push_back(edge(u, v, c));
}

bool BellmanFord() {
	for (int i = 0; i <= n; ++i)
		cost[i] = oo;
	cost[n] = 0;
	bool up = true;
	for (int it = 0; it <= n && up; ++it) {
		up = false;
		for (int i = 0; i < (int) e.size(); ++i) {
			int u = e[i].u, v = e[i].v, c = e[i].c;
			if (cost[u] != oo && cost[u] + c < cost[v]) {
				up = true;
				cost[v] = cost[u] + c;
			}
		}
	}
	return up == false;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		e.clear();
		scanf("%d", &m);
		gets(s);
		for (int i = 0; i < n; ++i)
			fill(E[i], E[i] + n, oo);
		for (int i = 0; i < m; ++i) {
			gets(s);
			int u = -1, v = -1, A = -1, type = 1;
			int len = strlen(s), pos = 0;
			while (pos < len) {
				if (pos + 1 < len && s[pos] == 'a' && s[pos + 1] == 't')
					type = 0;
				if (!isdigit(s[pos])) {
					++pos;
					continue;
				}
				int val = 0;
				while (pos < len && isdigit(s[pos]))
					val = val * 10 + (s[pos++] - '0');
				if (u == -1)
					u = val;
				else if (A == -1)
					A = val;
				else
					v = val;
			}
			--u, --v;
			if (type == 0) {
				E[u][v] = min(E[u][v], -A);
			} else {
				E[v][u] = min(E[v][u], A);
				E[u][v] = min(E[u][v], 0);
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (E[i][j] != oo)
					addEdge(i, j, E[i][j]);
		for (int i = 0; i < n; ++i)
			addEdge(n, i, 0);
		if (BellmanFord()) {
			int mn = oo;
			for (int i = 0; i < n; ++i)
				mn = min(mn, cost[i]);
			if (mn < 0)
				mn = -mn + 1;
			else
				mn = 0;
			for (int i = 0; i < n; ++i)
				printf("%s%d", i ? " " : "", cost[i] + mn);
			puts("");
		} else
			puts("Impossible.");
	}
	return 0;
}
