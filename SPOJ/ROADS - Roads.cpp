#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int k, n, m;
vector<pair<int, pair<int, int> > > g[N];

int Dijkstra(int src, int dest) {
	priority_queue<pair<int, pair<int, int> > > qu;
	qu.push(make_pair(0, make_pair(0, src)));
	while (!qu.empty()) {
		pair<int, pair<int, int> > e = qu.top();
		qu.pop();
		if (e.second.second == dest)
			return -e.first;
		for (size_t i = 0; i < g[e.second.second].size(); ++i) {
			int v = g[e.second.second][i].first;
			int nl = -e.first + g[e.second.second][i].second.first;
			int nc = -e.second.first + g[e.second.second][i].second.second;
			if (nc <= k)
				qu.push(make_pair(-nl, make_pair(-nc, v)));
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d%d", &k, &n, &m);
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		int u, v, c, t;
		while (m-- != 0) {
			scanf("%d%d%d%d", &u, &v, &c, &t);
			g[u].push_back(make_pair(v, make_pair(c, t)));
		}
		printf("%d\n", Dijkstra(1, n));
	}
	return 0;
}
