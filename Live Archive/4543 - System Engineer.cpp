#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, nxt;
	edge(int u, int nxt) :
			u(u), nxt(nxt) {
	}
};

const int N = 1e4;
vector<edge> e;
int n, head[N], match[N], qu[N], level[N], vis[N], vs;
bool used[N];

int get(char *s) {
	int res = 0, n = strlen(s);
	for (int i = 0; i < n; ++i)
		if (isdigit(s[i]))
			res = res * 10 + (s[i] - '0');
	return res;
}

void addEdge(int u, int v) {
	e.push_back(edge(v, head[u]));
	head[u] = e.size() - 1;
}

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
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			head[i] = match[i] = -1, used[i] = false;
		e.clear();
		char s[111];
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int u = get(s);
			scanf("%s", s);
			int m = get(s);
			while (m-- != 0) {
				int v;
				scanf("%d", &v);
				v -= n;
				addEdge(u, v);
			}
		}
		printf("%d\n", maxMatching());
	}
	return 0;
}
