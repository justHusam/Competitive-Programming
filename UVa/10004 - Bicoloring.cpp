#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 200;
vector<int> g[N];
int col[N];

bool DFS(int v, int c) {
	if (col[v] != -1)
		return col[v] == c;
	col[v] = c;
	bool res = true;
	for (size_t i = 0; i < g[v].size() && res; ++i)
		res &= DFS(g[v][i], c ? 0 : 1);
	return res;
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear(), col[i] = -1;
		int m;
		scanf("%d", &m);
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (DFS(0, 0))
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}
	return 0;
}
