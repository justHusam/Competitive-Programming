#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4;
pair<int, int> e[150001];
int n, m, p;
int head[N], qu[N], level[N], vis[N], match[N], vs, idx;
bitset<N> used;

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
		if (u == -1 || (vis[u] != vs && level[u] == level[v] + 1 && DFS(u))) {
			used[v] = 1;
			match[e[i].first] = v;
			return true;
		}
	}
	return false;
}

int maxMatching() {
	int res = 0;
	while (BFS()) {
		++vs;
		for (int i = 0; i < n; ++i)
			if (!used[i] && DFS(i))
				++res;
	}
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; ++i)
		head[i] = -1;
	for (int i = 0; i < m; ++i)
		match[i] = -1;
	while (p-- != 0) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		addEdge(u, v);
	}
	printf("%d\n", maxMatching());
	return 0;
}
