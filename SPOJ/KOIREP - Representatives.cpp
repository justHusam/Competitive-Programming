#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, g[N][N], at[N], m;
priority_queue<pair<int, int> > qu;

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &g[i][j]);
	for (int i = 0; i < n; ++i)
		sort(g[i], g[i] + m);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		at[i] = 0;
		qu.push(make_pair(-g[i][0], i));
		mx = max(mx, g[i][0]);
	}
	int res = 2e9;
	while (true) {
		pair<int, int> e = qu.top();
		qu.pop();
		res = min(res, mx + e.first);
		if (++at[e.second] == m)
			break;
		qu.push(make_pair(-g[e.second][at[e.second]], e.second));
		mx = max(mx, g[e.second][at[e.second]]);
	}
	printf("%d\n", res);
	return 0;
}
