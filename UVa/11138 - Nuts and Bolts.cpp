#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, nxt;
	edge(int u, int nxt) :
			u(u), nxt(nxt) {
	}
};

const int N = 500;
int n, m, head[N], qu[N], vis[N], match[N], level[N], vs;
vector<edge> e;
bool used[N];

bool BFS() {
	int l = 0, r = 0;
	++vs;
	for (int i = 0; i < n; ++i)
		if (!used[i])
			qu[r++] = i, level[i] = 0, vis[i] = vs;
	bool can = false;
	while (l < r) {
		int v = qu[l++];
		for (int i = head[v]; i != -1; i = e[i].nxt) {
			int u = match[e[i].u];
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
	for (int i = head[v]; i != -1; i = e[i].nxt) {
		int u = match[e[i].u];
		if (u == -1 || (vis[u] != vs && level[v] + 1 == level[u] && DFS(u))) {
			match[e[i].u] = v;
			used[v] = true;
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
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			head[i] = -1, used[i] = false;
		for (int i = 0; i < m; ++i)
			match[i] = -1;
		e.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				int x;
				scanf("%d", &x);
				if (x != 0) {
					e.push_back(edge(j, head[i]));
					head[i] = e.size() - 1;
				}
			}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", k++, maxMatching());
	}
	return 0;
}
