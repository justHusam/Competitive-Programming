#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int u, c;
	state() {
	}
	state(int u, int c) :
			u(u), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, str, tar;
		scanf("%d%d%d%d", &n, &m, &str, &tar);
		--str;
		--tar;
		vector<vector<state> > g(n);
		while (m-- != 0) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			--a;
			--b;
			g[a].push_back(state(b, c));
			g[b].push_back(state(a, c));
		}
		int res = -1;
		priority_queue<state> qu;
		vector<int> cost(n, 2e9);
		vector<bool> vis(n, false);
		qu.push(state(str, 0));
		cost[str] = 0;
		while (!qu.empty()) {
			const state t = qu.top();
			qu.pop();
			if (vis[t.u])
				continue;
			vis[t.u] = true;
			if (t.u == tar) {
				res = t.c;
				break;
			}
			for (int i = 0; i < (int) g[t.u].size(); ++i) {
				int u = g[t.u][i].u;
				int c = g[t.u][i].c + t.c;
				if (vis[u] || c >= cost[u])
					continue;
				cost[u] = c;
				qu.push(state(u, c));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
