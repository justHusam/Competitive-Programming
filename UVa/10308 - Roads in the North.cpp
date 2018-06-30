#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
};

char s[111];
vector<int> hs;
vector<edge> E;
vector<vector<pair<int, int> > > g;
int at, mx;

void DFS(int v, int p, int dist) {
	if (dist > mx) {
		mx = dist;
		at = v;
	}
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].first;
		int c = dist + g[v][i].second;
		if (u != p)
			DFS(u, v, c);
	}
}

int main(int argc, char **argv) {
	while (gets(s) > 0) {
		hs.clear();
		E.clear();
		if (strlen(s) == 0) {
			gets(s);
			puts("0");
			continue;
		}
		do {
			int u, v, c;
			sscanf(s, "%d%d%d", &u, &v, &c);
			hs.push_back(u);
			hs.push_back(v);
			E.push_back(edge(u, v, c));
		} while (gets(s) > 0 && strlen(s) != 0);
		sort(hs.begin(), hs.end());
		hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
		g.clear();
		g.resize(hs.size());
		for (size_t i = 0; i < E.size(); ++i) {
			int u = lower_bound(hs.begin(), hs.end(), E[i].u) - hs.begin();
			int v = lower_bound(hs.begin(), hs.end(), E[i].v) - hs.begin();
			g[u].push_back(make_pair(v, E[i].c));
			g[v].push_back(make_pair(u, E[i].c));
		}
		mx = 0;
		DFS(0, -1, 0);
		DFS(at, -1, 0);
		printf("%d\n", mx);
	}
	return 0;
}
