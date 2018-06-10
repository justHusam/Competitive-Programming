/*
 * Name: MUDDY - Muddy Fields
 * Link: http://www.spoj.com/problems/MUDDY/
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 51;
int n, m, compH[N][N], compV[N][N], H, V, id, vs[N][N];
char s[N][N];
vector<vector<int> > g;
vector<int> match, vis;

void goV(int x, int y) {
	if (x == n || s[x][y] == '.')
		return;
	vs[x][y] = id;
	compV[x][y] = V;
	goV(x + 1, y);
}

void goH(int x, int y) {
	if (y == m || s[x][y] == '.')
		return;
	vs[x][y] = id;
	compH[x][y] = H;
	goH(x, y + 1);
}

bool DFS(int v) {
	vis[v] = id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (match[u] == -1 || (vis[match[u]] != id && DFS(match[u]))) {
			match[u] = v;
			return true;
		}
	}
	return false;
}

int maxMatching() {
	int res = 0;
	for (size_t i = 0; i < g.size(); ++i) {
		++id;
		if (DFS(i))
			++res;
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		V = 0;
		++id;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (vs[i][j] != id && s[i][j] == '*') {
					goV(i, j);
					++V;
				}
		H = 0;
		++id;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (vs[i][j] != id && s[i][j] == '*') {
					goH(i, j);
					++H;
				}
		g.clear();
		g.resize(H);
		vis.clear();
		vis.resize(H);
		match.clear();
		match.resize(V, -1);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (s[i][j] == '*')
					g[compH[i][j]].push_back(compV[i][j]);
		printf("%d\n", maxMatching());
	}
	return 0;
}
