#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, k, d, x[10], y[10], p[N];
vector<pair<int, int> > g[N];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

inline int dist(const pair<int, int> &a, const pair<int, int> &b) {
	int x = a.first - b.first, y = a.second - b.second;
	return x * x + y * y;
}

inline bool check(int a, int b) {
	for (int i = 0; i < (int) g[a].size(); ++i)
		for (int j = 0; j < (int) g[b].size(); ++j)
			if (dist(g[a][i], g[b][j]) <= k * k)
				return true;
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i = 0; i < m; ++i)
			scanf("%d%d", &x[i], &y[i]);
		for (int i = 0, x; i < n; ++i) {
			p[i] = i;
			g[i].clear();
			scanf("%d", &x);
			g[i].resize(x);
			for (int j = 0; j < x; ++j)
				scanf("%d%d", &g[i][j].first, &g[i][j].second);
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (check(i, j))
					p[find(i)] = find(j);
		bool can = false;
		for (int i = 0; i < n && !can; ++i)
			if (find(i) == find(0)) {
				for (int j = 0; j < (int) g[i].size() && !can; ++j)
					for (int k = 0; k < m && !can; ++k)
						if (dist(g[i][j], make_pair(x[k], y[k])) <= d * d)
							can = true;
			}
		if (can)
			puts("Tree can be saved :)");
		else
			puts("Tree can't be saved :(");
	}
	return 0;
}
