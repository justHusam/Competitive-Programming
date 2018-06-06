#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct edge {
	int u, c;
	edge(int u, int c) :
			u(u), c(c) {
	}
	inline bool operator<(const edge&e) const {
		return e.c < c;
	}
};

const int N = 1e3;
vector<edge> g[N];
bitset<10009> bs;
int n, m;

int Dijkstra(int str, int tar) {
	priority_queue<edge> qu;
	qu.push(edge(str, 0));
	vector<int> cost(n, 2e9), vis(n, 0);
	cost[str] = 0;
	while (!qu.empty()) {
		const edge e = qu.top();
		qu.pop();
		if (vis[e.u])
			continue;
		vis[e.u] = 1;
		if (e.u == tar)
			return e.c;
		for (size_t a = 0; a < g[e.u].size(); ++a) {
			int u = g[e.u][a].u;
			int c = g[e.u][a].c + e.c;
			if (vis[u] || c >= cost[u])
				continue;
			cost[u] = c;
			qu.push(edge(u, c));
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < 10009; ++i)
		if (bs[i])
			for (ll j = i * i; j < 10009; j += i)
				bs[j] = 0;
	int t, k = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			if (!bs[c])
				continue;
			g[u].push_back(edge(v, c));
			g[v].push_back(edge(u, c));
		}
		int str, tar;
		scanf("%d%d", &str, &tar);
		--str;
		--tar;
		printf("Case %d: %d\n", k++, Dijkstra(str, tar));
	}
	return 0;
}
