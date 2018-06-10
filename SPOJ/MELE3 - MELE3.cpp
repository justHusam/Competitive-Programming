#include <bits/stdc++.h>
using namespace std;

const int N = 1e3, oo = 2e9;
int k, m, cost[N];
vector<int> g[N];
bool vis[N];

int wait(int cost, int from, int to) {
	int allMoves = cost / 5;
	int fl = abs(to - from);
	if (((allMoves / fl) & 1) == 1)
		return (to - allMoves % fl) - from;
	int now = (from + allMoves % fl);
	if (now == from)
		return 0;
	return to - now + fl;
}

int Dijkstra(int src, int dest) {
	priority_queue<pair<int, int> > qu;
	memset(vis, false, sizeof vis);
	fill(cost, cost + N, oo);
	if (src == dest)
		return 0;
	qu.push(make_pair(0, src));
	cost[src] = 0;
	while (!qu.empty()) {
		pair<int, int> e = qu.top();
		qu.pop();
		if (e.second == dest)
			return -e.first;
		if (vis[e.second])
			continue;
		vis[e.second] = true;
		for (size_t a = 0; a < g[e.second].size(); ++a) {
			int v = g[e.second][a];
			if (vis[v])
				continue;
			int nc = e.first * -1 + (wait(e.first * -1, e.second, v) + abs(e.second - v)) * 5;
			if (nc < cost[v]) {
				cost[v] = nc;
				qu.push(make_pair(-nc, v));
			}
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	scanf("%d%d", &k, &m);
	int a, b;
	while (m-- != 0) {
		scanf("%d%d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	printf("%d\n", Dijkstra(0, k - 1));
	return 0;
}
