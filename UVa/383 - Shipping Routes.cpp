#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int cost[N];
map<string, int> hs;
vector<int> g[N];

int BFS(int src, int dest) {
	queue<int> qu;
	cost[src] = 0;
	qu.push(src);
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		if (v == dest)
			return cost[dest];
		for (size_t i = 0; i < g[v].size(); ++i)
			if (cost[g[v][i]] == 0) {
				qu.push(g[v][i]);
				cost[g[v][i]] = cost[v] + 1;
			}
	}
	return -1;
}

int main(int argc, char **argv) {
	int T, m, n, p;
	scanf("%d", &T);
	printf("SHIPPING ROUTES OUTPUT\n");
	for (int caseN = 1; caseN <= T; ++caseN) {
		scanf("%d%d%d", &m, &n, &p);
		char s[10];
		hs.clear();
		for (int i = 0; i < m; i++)
			g[i].clear();
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			hs[s] = i;
		}
		while (n-- != 0) {
			scanf("%s", s);
			int u = hs[s];
			scanf("%s", s);
			int v = hs[s];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("\nDATA SET  %d\n\n", caseN);
		while (p-- != 0) {
			memset(cost, 0, sizeof cost);
			scanf("%s", s);
			int u = hs[s];
			scanf("%s", s);
			int v = hs[s];
			int res = BFS(u, v);
			if (res == -1)
				printf("NO SHIPMENT POSSIBLE\n");
			else
				printf("$%d\n", (res * s * 100));
		}
	}
	printf("\nEND OF OUTPUT\n");
	return 0;
}
