#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int> > E, with, cost;
char a[10], b[10];
vector<int> v;
vector<vector<int> > g;
vector<bool> vis;
int hs[26][26][26], N;

int idx(char *s) {
	if (hs[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'] == -1)
		hs[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'] = N++;
	return hs[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'];
}

int BFS(int src, int tar) {
	deque<int> qu;
	qu.push_back(src);
	cost[src] = make_pair(0, 0);
	while (!qu.empty()) {
		deque<int> temp;
		while (!qu.empty()) {
			int v = qu.front();
			qu.pop_front();
			if (v == tar)
				return cost[v].second;
			if (vis[v])
				continue;
			vis[v] = true;
			for (size_t i = 0; i < g[v].size(); ++i) {
				int u = g[v][i];
				int c1 = cost[v].first + (u != tar);
				int c2 = cost[v].second + !binary_search(with.begin(), with.end(), make_pair(v, u));
				if (vis[u] || make_pair(c1, c2) >= cost[u])
					continue;
				cost[u] = make_pair(c1, c2);
				if (c2 == cost[v].second)
					temp.push_front(u);
				else
					temp.push_back(u);
			}
		}
		qu.swap(temp);
	}
	return -1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int m;
		scanf("%d", &m);
		E.clear();
		N = 0;
		memset(hs, -1, sizeof hs);
		while (m--) {
			scanf("%s%s", a, b);
			int u = idx(a);
			int v = idx(b);
			E.push_back(make_pair(u, v));
		}
		scanf("%d", &m);
		v.clear();
		for (int i = 0; i <= m; ++i) {
			scanf("%s", a);
			int u = idx(a);
			v.push_back(u);
		}
		with.clear();
		for (size_t i = 1; i < v.size(); ++i)
			with.push_back(make_pair(v[i - 1], v[i]));
		sort(with.begin(), with.end());
		g.clear();
		g.resize(N);
		for (size_t i = 0; i < E.size(); ++i) {
			g[E[i].first].push_back(E[i].second);
			g[E[i].second].push_back(E[i].first);
		}
		vis.clear();
		vis.resize(N, false);
		cost.clear();
		cost.resize(N, make_pair(2e9, 2e9));
		printf("%d\n", BFS(v[0], v.back()));
	}
	return 0;
}
