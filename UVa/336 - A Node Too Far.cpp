#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

map<int, int> hs;
int id;
vector<int> g[30];

int BFS(int str, int mx) {
	queue<int> qu;
	bool vis[30] = { };
	vis[str] = true;
	qu.push(str);
	int levels = 0;
	while (!qu.empty() && levels < mx) {
		int size = qu.size();
		while (size-- != 0) {
			int v = qu.front();
			qu.pop();
			for (size_t i = 0; i < g[v].size(); ++i) {
				int u = g[v][i];
				if (!vis[u])
					vis[u] = true, qu.push(u);
			}
		}
		++levels;
	}
	int res = 0;
	for (int i = 0; i < id; ++i)
		if (!vis[i])
			++res;
	return res;
}

int main(int argc, char **argv) {
	int m, caseN = 1;
	while (scanf("%d", &m) && m != 0) {
		for (int i = 0; i < 30; ++i)
			g[i].clear();
		hs.clear();
		id = 0;
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (hs.find(u) == hs.end())
				hs[u] = id++;
			if (hs.find(v) == hs.end())
				hs[v] = id++;
			u = hs[u], v = hs[v];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int src, levels;
		while (scanf("%d%d", &src, &levels) > 0 && (levels || src))
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseN++, BFS(hs[src], levels), src, levels);
	}
	return 0;
}
