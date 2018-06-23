#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
int n, m, with[N], match[N], vis[N], vs;
pair<int, int> a[N], b[N];

double dist(pair<int, int>&a, pair<int, int>&b) {
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x * x + y * y);
}

bool DFS(int v) {
	vis[v] = vs;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (match[u] == -1 || (vis[match[u]] != vs && DFS(match[u]))) {
			with[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int maxMatching() {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		++vs;
		if (DFS(i))
			++res;
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			g[i].clear(), with[i] = -1;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &b[i].first, &b[i].second);
			match[i] = -1;
		}
		for (int i = 0; i < n - 1; ++i) {
			double d = dist(a[i], a[i + 1]);
			for (int j = 0; j < m; ++j) {
				double dd = dist(a[i], b[j]) + dist(b[j], a[i + 1]);
				if (d * 2 >= dd)
					g[i].push_back(j);
			}
		}
		printf("%d\n", maxMatching() + n);
		for (int i = 0; i < n; ++i) {
			printf("%s%d %d", i ? " " : "", a[i].first, a[i].second);
			if (with[i] != -1)
				printf(" %d %d", b[with[i]].first, b[with[i]].second);
		}
		puts("");
		if (T != 0)
			puts("");
	}
	return 0;
}
