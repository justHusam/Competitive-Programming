#include <bits/stdc++.h>
using namespace std;

vector<int> g[20];
int n, m, cost[20];

int BFS(int src, int dest) {
	queue<int> qu;
	qu.push(src);
	memset(cost, 0, sizeof cost);
	while (qu.front() != dest) {
		int v = qu.front();
		qu.pop();
		for (size_t i = 0; i < g[v].size(); ++i)
			if (cost[g[v][i]] == 0 && g[v][i] != src) {
				qu.push(g[v][i]);
				cost[g[v][i]] = cost[v] + 1;
			}
	}
	return cost[dest];
}

int main(int argc, char **argv) {
	int cases = 1;
	while (scanf("%d", &m) > 0) {
		for (int i = 0; i < 20; ++i)
			g[i].clear();
		int u, v;
		for (int i = 0; i < 19; ++i) {
			if (i != 0)
				scanf("%d", &m);
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &u);
				g[i].push_back(u - 1);
				g[u - 1].push_back(i);
			}
		}
		scanf("%d", &n);
		printf("Test Set #%d\n", cases++);
		while (n-- != 0) {
			scanf("%d%d", &u, &v);
			printf("%2d to %2d: %d\n", u, v, BFS(u - 1, v - 1));
		}
		puts("");
	}
	return 0;
}
