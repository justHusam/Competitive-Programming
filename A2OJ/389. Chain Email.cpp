#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 50;
char s[N][20];
vector<int> g[N];
int par[N], qu[N];
bool in[N], with[N], vis[N];
vector<int> res;

void DFS(int v) {
	vis[v] = in[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!vis[u]) {
			par[u] = v;
			DFS(u);
		} else if (in[u]) {
			with[u] = true;
			for (int i = v; i != u; i = par[i])
				with[i] = true;
		}
	}
	in[v] = false;
}

void BFS(int str) {
	int s = 0, e = 0;
	qu[e++] = str;
	vis[str] = true;
	while (s < e) {
		int v = qu[s++];
		res.push_back(v);
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (!vis[u]) {
				vis[u] = true;
				qu[e++] = u;
			}
		}
	}
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, str;
		scanf("%d%d", &n, &str);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			g[i].clear();
			vis[i] = with[i] = false;
		}
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			while (x-- != 0) {
				int u;
				scanf("%d", &u);
				--u;
				g[i].push_back(u);
			}
		}
		--str;
		DFS(str);
		res.clear();
		for (int i = 0; i < n; ++i)
			vis[i] = false;
		for (int i = 0; i < n; ++i)
			if (with[i] && !vis[i])
				BFS(i);
		printf("Chain Email #%d:\n", k++);
		if (!res.size())
			puts("Safe chain email!");
		else {
			sort(res.begin(), res.end());
			for (size_t i = 0; i < res.size(); ++i)
				printf("%s%s", i ? " " : "", s[res[i]]);
			puts("");
		}
		puts("");
	}
	return 0;
}
