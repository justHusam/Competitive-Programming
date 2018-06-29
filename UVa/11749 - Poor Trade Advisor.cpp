#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct edge {
	int u, c;
	edge() {
	}
	edge(int u, int c) :
			u(u), c(c) {
	}
	bool operator<(const edge&e) const {
		return e.c < c;
	}
};

struct state {
	int u, v, c;
	state() {
	}
	state(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c > c;
	}
};

const int N = 500;
vector<edge> g[N];
bool vis[N];
set<int> res, st;
int n, m;

void DFS(int v, int w) {
	st.insert(v);
	if (st.size() > res.size())
		res = st;
	if (vis[v])
		return;
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i)
		if (g[v][i].c == w)
			DFS(g[v][i].u, w);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		priority_queue<state> qu;
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u].push_back(edge(v, c));
			g[v].push_back(edge(u, c));
			qu.push(state(u, v, c));
		}
		res.clear();
		memset(vis, false, sizeof vis);
		int mx = qu.top().c;
		while (!qu.empty()) {
			state e = qu.top();
			qu.pop();
			if (e.c != mx)
				break;
			st.clear();
			DFS(e.u, e.c);
		}
		printf("%d\n", res.size());
	}
	return 0;
}
