#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, row[N][N], col[N][N], vs;
char s[N][N + 1];
vector<vector<int> > g;
vector<int> vis, match;

inline void calcR(int x, int y, int &R) {
	while (y < n && s[x][y] == '.')
		row[x][y++] = R;
	++R;
}

inline void calcC(int x, int y, int &C) {
	while (x < n && s[x][y] == '.')
		col[x++][y] = C;
	++C;
}

bool DFS(int v) {
	vis[v] = vs;
	for (int i = 0; i < (int) g[v].size(); ++i) {
		int u = g[v][i];
		if (match[u] == -1 || (vis[match[u]] != vs && DFS(match[u]))) {
			match[u] = v;
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				row[i][j] = col[i][j] = -1;
		int R = 0, C = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (row[i][j] == -1 && s[i][j] == '.')
					calcR(i, j, R);
				if (col[i][j] == -1 && s[i][j] == '.')
					calcC(i, j, C);
			}
		g.clear();
		g.resize(R);
		vis.clear();
		vis.resize(R);
		match.clear();
		match.resize(C, -1);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i][j] == '.')
					g[row[i][j]].push_back(col[i][j]);
		int res = 0;
		for (int i = 0; i < R; ++i) {
			++vs;
			if (DFS(i))
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
