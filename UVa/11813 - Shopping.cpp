#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, m, k, v[10];
ll need[N], cost[10][10], back[10], dp[10][1 << 10];
vector<pair<int, int> > g[N];
bool vis[N];

void SPFA(int src) {
	for (int i = 0; i < n; ++i)
		vis[i] = false, need[i] = 2e15;
	need[v[src]] = 0;
	queue<int> qu;
	qu.push(v[src]);
	vis[v[src]] = true;
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		vis[v] = false;
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].first;
			int c = need[v] + g[v][i].second;
			if (c >= need[u])
				continue;
			need[u] = c;
			if (!vis[u]) {
				qu.push(u);
				vis[u] = true;
			}
		}
	}
	for (int i = 0; i < k; ++i)
		cost[src][i] = need[v[i]];
	back[src] = need[0];
}

ll calc(int v, int msk) {
	if (msk == (1 << k) - 1)
		return back[v];
	ll &res = dp[v][msk];
	if (res != -1)
		return res;
	res = 2e15;
	for (int i = 0; i < k; ++i)
		if (((msk >> i) & 1) == 0)
			res = min(res, calc(i, msk | (1 << i)) + cost[v][i]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		scanf("%d", &k);
		for (int i = 0; i < k; ++i)
			scanf("%d", &v[i]);
		for (int i = 0; i < k; ++i)
			SPFA(i);
		memset(dp, -1, sizeof dp);
		ll res = 2e15;
		for (int i = 0; i < k; ++i)
			res = min(res, calc(i, 1 << i) + back[i]);
		printf("%lld\n", res);
	}
	return 0;
}
