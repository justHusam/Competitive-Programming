#include <bits/stdc++.h>
using namespace std;

const int N = 102;
bool vis[N];
vector<int> g[N];

void DFS(int v, int no) {
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i)
		if (!vis[g[v][i]] && g[v][i] != no)
			DFS(g[v][i], no);
}

int main(int argc, char **argv) {
	int n;
	while (cin >> n && n != 0) {
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		int u, v;
		while (cin >> u && u != 0) {
			cin.ignore();
			string line;
			getline(cin, line);
			stringstream ss(line);
			while (!ss.eof()) {
				ss >> v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			memset(vis, false, sizeof vis);
			DFS(i == 1 ? 2 : 1, i);
			for (int j = 1; j <= n; ++j)
				if (!vis[j] && j != i) {
					++res;
					break;
				}
		}
		cout << res << "\n";
	}
	return 0;
}
