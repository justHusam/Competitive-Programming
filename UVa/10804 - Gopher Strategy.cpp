#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50;
int n, m, k, vis[N], match[N], vs;
pair<double, double> a[N], b[N];
double dist[N][N];
vector<int> g[N];

bool DFS(int v) {
	vis[v] = vs;
	for (int i = 0; i < (int) g[v].size(); ++i) {
		int u = match[g[v][i]];
		if (u == -1 || (vis[u] != vs && DFS(u))) {
			match[g[v][i]] = v;
			return true;
		}
	}
	return false;
}

bool check(double mid) {
	for (int i = 0; i < n; ++i) {
		g[i].clear();
		match[i] = -1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (dist[i][j] <= mid)
				g[i].push_back(j);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		++vs;
		if (DFS(i))
			++res;
	}
	return res >= n - k;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		printf("Case #%d:\n", cas++);
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &a[i].first, &a[i].second);
		for (int i = 0; i < m; ++i)
			scanf("%lf%lf", &b[i].first, &b[i].second);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				dist[i][j] = hypot(a[i].first - b[j].first, a[i].second - b[j].second);
		double l = 0, r = 1e9, res = -1;
		for (int it = 0; it < 80; ++it) {
			double mid = (l + r) / 2;
			if (check(mid))
				r = res = mid;
			else
				l = mid;
		}
		if (res == -1)
			printf("Too bad.\n\n");
		else
			printf("%.3lf\n\n", res);
	}
	return 0;
}
