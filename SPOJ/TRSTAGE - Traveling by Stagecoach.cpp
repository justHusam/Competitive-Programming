#include<bits/stdc++.h>
#include<map>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int u;
	double c;
	bitset<8> mask;
	state(int u, double c, bitset<8> mask) :
			u(u), c(c), mask(mask) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

struct edge {
	int u;
	double c;
	edge(int u, double c) :
			u(u), c(c) {
	}
};

int main(int argc, char **argv) {
	int tc, n, m, str, tar;
	while (scanf("%d%d%d%d%d", &tc, &n, &m, &str, &tar) > 0) {
		if (tc == 0 && n == 0 && m == 0 && str == 0 && tar == 0)
			break;
		vector<vector<edge> > g(n);
		vector<int> v(tc);
		for (int a = 0; a < tc; ++a)
			scanf("%d", &v[a]);
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			g[u].push_back(edge(v, c));
			g[v].push_back(edge(u, c));
		}
		--str, --tar;
		vector<vector<bool> > vis(n, vector<bool>(1 << tc, false));
		vector<vector<double> > cost(n, vector<double>(1 << tc, 2e9));
		priority_queue<state> qu;
		bitset<8> bs = 0;
		qu.push(state(str, 0, bs));
		double res = -1;
		cost[str][0] = 0;
		while (!qu.empty()) {
			state e = qu.top();
			qu.pop();
			if (vis[e.u][e.mask.to_ulong()])
				continue;
			vis[e.u][e.mask.to_ulong()] = true;
			if (e.u == tar) {
				res = e.c;
				break;
			}
			for (size_t i = 0; i < g[e.u].size(); ++i)
				for (int j = 0; j < tc; ++j)
					if (e.mask[j] == 0) {
						int u = g[e.u][i].u;
						double c = g[e.u][i].c / (double) v[j] + e.c;
						bitset<8> nMask = e.mask;
						nMask[j] = 1;
						if (c < cost[u][nMask.to_ulong()]) {
							cost[u][nMask.to_ulong()] = c;
							qu.push(state(u, c, nMask));
						}
					}
		}
		if (res == -1)
			puts("Impossible");
		else
			printf("%.3lf\n", res);
	}
	return 0;
}
