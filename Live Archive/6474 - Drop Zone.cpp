#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, c, f, nxt;
	edge(int u, int c, int f, int nxt) :
			u(u), c(c), f(f), nxt(nxt) {
	}
};

const int N = 23000;
char g[150][151];
int hs[150][150], n, m, head[N], work[N], level[N], vis[N], qu[N], vs;
vector<edge> e;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

void addEdge(int u, int v, int c) {
	e.push_back(edge(v, c, 0, head[u]));
	head[u] = e.size() - 1;
	e.push_back(edge(u, 0, 0, head[v]));
	head[v] = e.size() - 1;
}

bool BFS(int src, int sink) {
	int l = 0, r = 0;
	qu[r++] = src;
	vis[src] = ++vs;
	level[src] = 0;
	while (l < r) {
		int v = qu[l++];
		for (int i = head[v]; i != -1; i = e[i].nxt) {
			int u = e[i].u;
			if (vis[u] == vs || e[i].f >= e[i].c)
				continue;
			vis[u] = vs;
			level[u] = level[v] + 1;
			qu[r++] = u;
		}
	}
	return vis[sink] == vs;
}

int DFS(int v, int sink, int f) {
	if (v == sink)
		return f;
	for (int &i = work[v]; i != -1; i = e[i].nxt)
		if (e[i].f < e[i].c && level[v] + 1 == level[e[i].u]) {
			int res = DFS(e[i].u, sink, min(f, e[i].c - e[i].f));
			if (res != -1) {
				e[i].f += res;
				e[i ^ 1].f -= res;
				return res;
			}
		}
	return -1;
}

int maxFlow(int src, int sink) {
	int flow = 0;
	while (BFS(src, sink)) {
		for (int i = 0; i <= sink; ++i)
			work[i] = head[i];
		while (true) {
			int res = DFS(src, sink, 2e9);
			if (res == -1)
				break;
			flow += res;
		}
	}
	return flow;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int id = 1;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf(" %c", &g[i][j]), hs[i][j] = id++;
		int src = 0, sink = id++;
		for (int i = 0; i < id; ++i)
			head[i] = -1;
		e.clear();
		set<pair<int, int> > st;
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) {
				if (g[x][y] == 'X')
					continue;
				if ((!x || !y || x == n - 1 || y == m - 1) && g[x][y] == '.')
					addEdge(src, hs[x][y], 1);
				if (g[x][y] == 'D') {
					addEdge(hs[x][y], sink, 1);
					continue;
				}
				for (int i = 0; i < 4; ++i) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] == 'X')
						continue;
					if (g[tx][ty] == 'D')
						st.insert(make_pair(hs[x][y], sink));
					else
						addEdge(hs[x][y], hs[tx][ty], 1);
				}
			}
		set<pair<int, int> >::iterator it;
		for (it = st.begin(); it != st.end(); ++it)
			addEdge((*it).first, (*it).second, 1);
		int res = maxFlow(src, sink);
		for (int i = 0; i < n; ++i)
			res += (g[i][0] == 'D') + (g[i][m - 1] == 'D');
		for (int i = 0; i < m; ++i)
			res += (g[0][i] == 'D') + (g[n - 1][i] == 'D');
		printf("%d\n", res);
	}
	return 0;
}
