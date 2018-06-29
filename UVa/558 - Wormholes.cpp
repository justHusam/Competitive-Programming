#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<pair<pair<int, int>, int> > E(m + 2);
		int u, v, c;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &c);
			E[i] = make_pair(make_pair(u, v), c);
		}
		vector<int> cost(n + 2, oo);
		cost[0] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				int u = E[j].first.first;
				int v = E[j].first.second;
				int c = E[j].second;
				if (cost[u] == oo)
					continue;
				cost[v] = min(cost[v], cost[u] + c);
			}
		bool can = false;
		for (int i = 0; i < m; ++i) {
			int u = E[i].first.first;
			int v = E[i].first.second;
			int c = E[i].second;
			if (cost[u] + c < cost[v]) {
				can = true;
				break;
			}
		}
		if (can)
			puts("possible");
		else
			puts("not possible");
	}
	return 0;
}
