#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int u, r, t;
	state(int u, int r, int t) :
			u(u), r(r), t(t) {
	}
	inline bool operator<(const state&e) const {
		if (e.r != r)
			return e.r < r;
		return e.t < t;
	}
};

const int N = 100, T = 251;
int n, m, vis[N][T], cost[N][T];
pair<int, int> g[N][N];

inline void Dijkstra(int str, int tar) {
	priority_queue<state> qu;
	qu.push(state(str, 0, 0));
	cost[str][0] = 0;
	while (!qu.empty()) {
		const state e = qu.top();
		qu.pop();
		if (e.u == tar) {
			printf("%d %d\n", e.r, e.t);
			return;
		}
		if (vis[e.u][e.t])
			continue;
		vis[e.u][e.t] = true;
		for (int i = 0; i < n; ++i) {
			int t = e.t + g[e.u][i].first;
			int r = e.r + g[e.u][i].second;
			if (t > m || vis[i][t] || r >= cost[i][t])
				continue;
			cost[i][t] = r;
			qu.push(state(i, r, t));
		}
	}
	puts("-1");
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j].first);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j].second);
		memset(vis, false, sizeof vis);
		memset(cost, 0x3f, sizeof cost);
		Dijkstra(0, n - 1);
	}
	return 0;
}
