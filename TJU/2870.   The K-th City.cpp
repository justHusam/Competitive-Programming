#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int u, c;
	state(int u, int c) :
			u(u), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

int main(int argc, char **argv) {
	int n, m, k;
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &m);
		vector<vector<state> > g(n);
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			g[u].push_back(state(v, c));
			g[v].push_back(state(u, c));
		}
		scanf("%d", &k);
		priority_queue<state> qu;
		vector<bool> vis(n, false);
		vector<int> cost(n, 2e9);
		cost[0] = 0;
		qu.push(state(0, 0));
		while (!qu.empty()) {
			const state t = qu.top();
			qu.pop();
			if (vis[t.u])
				continue;
			vis[t.u] = true;
			for (int i = 0; i < (int) g[t.u].size(); ++i) {
				int u = g[t.u][i].u;
				int c = g[t.u][i].c + t.c;
				if (vis[u] || c >= cost[u])
					continue;
				cost[u] = c;
				qu.push(state(u, c));
			}
		}
		vector<pair<int, int> > res;
		for (int i = 1; i < n; ++i)
			res.push_back(make_pair(cost[i], i));
		sort(res.begin(), res.end());
		--k;
		printf("%d\n", res[k].second);
	}
	return 0;
}
