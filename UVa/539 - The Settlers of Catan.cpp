#include <bits/stdc++.h>
using namespace std;

int res;
vector<vector<pair<int, int> > > g;

void calc(int v, int d, bitset<25> bs) {
	res = max(d, res);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].first, e = g[v][i].second;
		if (bs[e])
			continue;
		bs[e] = 1;
		calc(u, d + 1, bs);
		bs[e] = 0;
	}
}

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0 && n != 0) {
		g.clear();
		g.resize(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(make_pair(v, i));
			g[v].push_back(make_pair(u, i));
		}
		res = 0;
		for (int i = 0; i < n; ++i) {
			bitset<25> bs;
			bs.reset();
			calc(i, 0, bs);
		}
		printf("%d\n", res);
	}
	return 0;
}
