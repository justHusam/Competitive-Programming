#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, low[N], idx[N], id, root, ch;
char s[N][31], a[31], b[31];
vector<int> g[N];
bool need[N];

void DFS(int v, int p) {
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
			if (v == root)
				++ch;
			DFS(u, v);
			if (low[u] >= idx[v])
				need[v] = true;
			low[v] = min(low[v], low[u]);
		} else if (u != p)
			low[v] = min(low[v], idx[u]);
	}
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (cas != 1)
			puts("");
		map<string, int> hs;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			hs[s[i]] = i;
			g[i].clear();
			idx[i] = 0;
			need[i] = false;
		}
		scanf("%d", &m);
		while (m-- != 0) {
			scanf("%s%s", a, b);
			int u = hs[a], v = hs[b];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		id = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0) {
				root = i;
				ch = 0;
				DFS(i, -1);
				need[i] = ch > 1;
			}
		vector<string> res;
		for (int i = 0; i < n; ++i)
			if (need[i])
				res.push_back(s[i]);
		printf("City map #%d: %d camera(s) found\n", cas++, (int) res.size());
		sort(res.begin(), res.end());
		for (size_t i = 0; i < res.size(); ++i)
			puts(res[i].c_str());
	}
	return 0;
}
