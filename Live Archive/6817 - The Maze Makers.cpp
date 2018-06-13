#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int n, m, at[N][N];
char s[N][N];
map<char, string> hs;
vector<vector<int> > g;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
vector<pair<int, int> > open;
vector<bool> vis;
bool cycle;

string calc(char c) {
	if (hs.find(c) != hs.end())
		return hs[c];
	int n;
	if (isdigit(c))
		n = c - '0';
	else
		n = c - 'A' + 10;
	string res = "";
	while (n > 0) {
		res += (n & 1) + '0';
		n >>= 1;
	}
	while (res.size() < 4)
		res += "0";
	reverse(res.begin(), res.end());
	return hs[c] = res;
}

void DFS(int v, int p) {
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (vis[u]) {
			if (u != p)
				cycle = true;
			continue;
		}
		DFS(u, v);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		int id = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &s[i][j]);
				at[i][j] = id++;
			}
		g.clear();
		g.resize(id);
		open.clear();
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y) {
				string bin = calc(s[x][y]);
				for (size_t i = 0; i < bin.size(); ++i)
					if (bin[i] == '0') {
						int tx = x + dx[i];
						int ty = y + dy[i];
						if (tx < 0 || ty < 0 || tx >= n || ty >= m)
							continue;
						g[at[x][y]].push_back(at[tx][ty]);
						g[at[tx][ty]].push_back(at[x][y]);
					}
				if (x == 0 && bin[0] == '0')
					open.push_back(make_pair(x, y));
				else if (y == m - 1 && bin[1] == '0')
					open.push_back(make_pair(x, y));
				else if (x == n - 1 && bin[2] == '0')
					open.push_back(make_pair(x, y));
				else if (y == 0 && bin[3] == '0')
					open.push_back(make_pair(x, y));
			}
		for (int i = 0; i < id; ++i) {
			sort(g[i].begin(), g[i].end());
			g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
		}
		vis.clear();
		vis.resize(id, false);
		cycle = false;
		DFS(at[open[0].first][open[0].second], -1);
		int can = 0;
		for (int i = 0; i < id; ++i)
			can += vis[i] == true;
		if (vis[at[open[1].first][open[1].second]] == false)
			puts("NO SOLUTION");
		else if (can != id)
			puts("UNREACHABLE CELL");
		else if (cycle)
			puts("MULTIPLE PATHS");
		else
			puts("MAZE OK");
	}
	return 0;
}
