#include <bits/stdc++.h>
using namespace std;

const int N = 5e3, M = 1e5;
int n, m;
pair<int, int> dp[N];
vector<int> g[N];

pair<int, int> calc(int v) {
	if (v == n - 1)
		return make_pair(0, 1);
	pair<int, int> &res = dp[v];
	if (res.first != -1)
		return res;
	res = make_pair(0, 0);
	for (size_t i = 0; i < g[v].size(); ++i) {
		pair<int, int> p = calc(g[v][i]);
		res.first = (res.first + p.first + p.second) % M;
		res.second = (res.second + p.second) % M;
	}
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
		}
		memset(dp, -1, sizeof dp);
		pair<int, int> res = make_pair(0, 0);
		for (size_t i = 0; i < g[0].size(); ++i) {
			pair<int, int> p = calc(g[0][i]);
			res.first = (res.first + p.first + p.second) % M;
			res.second = (res.second + p.second) % M;
		}
		printf("Case %d: %d %d\n", cas++, res.first, res.second);
	}
	return 0;
}
