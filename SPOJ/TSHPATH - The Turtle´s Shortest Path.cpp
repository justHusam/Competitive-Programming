#include <bits/stdc++.h>
using namespace std;

const int N = 1e4, oo = 1e9;
int n, paths;
char S[15], D[15];
vector<pair<int, int> > g[N];
char arr[N][15];

inline int getID(char *name) {
	for (int i = 0; i < n; ++i) {
		if (strcmp(name, arr[i]) == 0)
			return i;
	}
	return -1;
}

int Dijkstra(int src, int dest) {
	priority_queue<pair<int, int> > qu;
	vector<int> cost(n, oo);
	vector<int> vis(n, 0);
	qu.push(make_pair(0, src));
	while (!qu.empty()) {
		pair<int, int> e = qu.top();
		qu.pop();
		if (e.second == dest)
			return -e.first;
		if (vis[e.second])
			continue;
		vis[e.second] = true;
		for (size_t i = 0; i < g[e.second].size(); ++i) {
			int v = g[e.second][i].first;
			int c = -e.first + g[e.second][i].second;
			if (vis[v] || c >= cost[v])
				continue;
			cost[v] = c;
			qu.push(make_pair(-c, v));
		}
	}
	return cost[dest];
}

int main(int argc, char **argv) {
	int T;
	scanf("%i", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		int p, j, c;
		for (int i = 0; i < n; ++i) {
			scanf(" %s%d", arr[i], &p);
			while (p-- != 0) {
				scanf("%d%d", &j, &c);
				g[i].push_back(make_pair(j - 1, c));
			}
		}
		scanf("%d", &paths);
		while (paths-- != 0) {
			scanf("%s%s", S, D);
			printf("%d\n", Dijkstra(getID(S), getID(D)));
		}
	}
	return 0;
}
