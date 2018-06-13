#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
vector<int> g[N];
int n, id;
pair<int, int> res[N];

void DFS(int v, int p, int at) {
	if (res[v] == make_pair(-1, -1))
		res[v] = make_pair(at, id++);
	bool can = false;
	for (size_t i = 0; i < g[v].size(); ++i)
		if (g[v][i] != p) {
			can = true;
			DFS(g[v][i], v, res[v].second);
		}
	if (!can)
		res[v] = res[p];
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			res[i] = make_pair(-1, -1);
		}
		for (int i = 1, u, v; i < n; ++i) {
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (g[0].size() == 1) {
			res[0] = make_pair(1, 2);
			res[g[0][0]] = make_pair(1, 2);
			id = 3;
			DFS(0, -1, 1);
		} else {
			res[0] = make_pair(1, 2);
			res[g[0][0]] = make_pair(1, 3);
			res[g[0][1]] = make_pair(2, 4);
			id = 5;
			DFS(0, -1, 1);
		}
		for (int i = 0; i < n; ++i)
			printf("%d %d\n", res[i].first, res[i].second);
	}
	return 0;
}
