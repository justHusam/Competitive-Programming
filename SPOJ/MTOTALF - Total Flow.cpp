#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 100;
int n, ID, g[N][N], cost[N], par[N];
map<char, int> hs;
bool vis[N];

int main(int argc, char **argv) {
	scanf("%d", &n);
	map<char, int> hs;
	while (n-- != 0) {
		char a, b;
		int cap, u, v;
		scanf(" %c %c%d", &a, &b, &cap);
		if (hs.find(a) == hs.end())
			hs[a] = ID++;
		if (hs.find(b) == hs.end())
			hs[b] = ID++;
		u = hs[a];
		v = hs[b];
		g[u][v] += cap;
	}
	int src = hs['A'], sink = hs['Z'], flow = 0;
	while (true) {
		for (int i = 0; i < ID; ++i) {
			cost[i] = 0;
			par[i] = -1;
			vis[i] = false;
		}
		priority_queue<pair<int, int> > qu;
		qu.push(make_pair(2e9, src));
		int temp = -1;
		while (!qu.empty()) {
			pair<int, int> e = qu.top();
			qu.pop();
			if (e.second == sink) {
				temp = e.first;
				break;
			}
			if (vis[e.second])
				continue;
			vis[e.second] = true;
			for (int i = 0; i < ID; ++i)
				if (!vis[i] && g[e.second][i] && g[e.second][i] > cost[i]) {
					cost[i] = g[e.second][i];
					par[i] = e.second;
					qu.push(make_pair(min(cost[i], e.first), i));
				}
		}
		if (temp == -1)
			break;
		flow += temp;
		for (int u = sink; u != src; u = par[u]) {
			int v = par[u];
			g[u][v] += temp;
			g[v][u] -= temp;
		}
	}
	printf("%d\n", flow);
	return 0;
}
