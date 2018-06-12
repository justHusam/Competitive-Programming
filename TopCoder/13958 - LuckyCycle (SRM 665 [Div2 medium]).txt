#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int> > g[N];
pair<int, int> G[N][N];
bool vis[N][N];

void DFS(int v, int p, int src, int f, int s) {
	G[src][v] = make_pair(f, s);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].first;
		if (u == p)
			continue;
		if (g[v][i].second == 4)
			DFS(u, v, src, f + 1, s);
		else
			DFS(u, v, src, f, s + 1);
	}
}

class LuckyCycle {
public:
	vector<int> getEdge(vector<int> edge1, vector<int> edge2, vector<int> weight) {
		int n = edge1.size() + 1;
		for (size_t i = 0; i < edge1.size(); ++i) {
			int u = edge1[i], v = edge2[i], c = weight[i];
			--u;
			--v;
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
			vis[u][v] = vis[v][u] = true;
		}
		for (int i = 0; i < n; ++i)
			DFS(i, -1, i, 0, 0);
		vector<int> res;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				int e = G[i][j].first + G[i][j].second + 1;
				if (vis[i][j] || (e & 1))
					continue;
				if (G[i][j].first + 1 == G[i][j].second) {
					res.push_back(i + 1);
					res.push_back(j + 1);
					res.push_back(4);
					return res;
				} else if (G[i][j].first == G[i][j].second + 1) {
					res.push_back(i + 1);
					res.push_back(j + 1);
					res.push_back(7);
					return res;
				}
			}
		return vector<int>();
	}
};
