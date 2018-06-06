#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300;
int n, m, k, g[N][N], c, head[N], match[N], vis[N], vs, qu[N], idx, level[N];
bitset<N> used;
pair<int, int> e[N * N];

inline void addEdge(int u, int v) {
	e[idx] = make_pair(v, head[u]);
	head[u] = idx++;
}

bool BFS() {
	int l = 0, r = 0;
	++vs;
	for (int i = 0; i < n; ++i)
		if (!used[i])
			qu[r++] = i, vis[i] = vs, level[i] = 0;
	bool can = false;
	while (l < r) {
		int v = qu[l++];
		for (int i = head[v]; i != -1; i = e[i].second) {
			int u = match[e[i].first];
			can |= u == -1;
			if (u == -1 || vis[u] == vs)
				continue;
			vis[u] = vs;
			level[u] = level[v] + 1;
			qu[r++] = u;
		}
	}
	return can;
}

bool DFS(int v) {
	vis[v] = vs;
	for (int i = head[v]; i != -1; i = e[i].second) {
		int u = match[e[i].first];
		if (u == -1 || (vis[u] != vs && level[v] + 1 == level[u] && DFS(u))) {
			match[e[i].first] = v;
			used[v] = 1;
			return true;
		}
	}
	return false;
}

bool check(int mid) {
	idx = 0;
	for (int i = 0; i < n; ++i)
		head[i] = -1;
	for (int i = 0; i < m * 2; ++i)
		match[i] = -1;
	used.reset();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (g[i][j] <= mid)
				addEdge(i, j);
			if (g[i][j] + c <= mid)
				addEdge(i, j + m);
		}
	int res = 0;
	while (BFS()) {
		++vs;
		for (int i = 0; i < n; ++i)
			if (!used[i] && DFS(i))
				++res;
	}
	return res >= k;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d", &n, &m, &k, &c);
		int mx = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf("%d", &g[i][j]);
				mx = max(mx, g[i][j]);
			}
		int l = 0, r = mx + c, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				res = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
