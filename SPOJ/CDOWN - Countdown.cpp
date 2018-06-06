#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, d, N, T;
vector<vector<int> > g, at;
map<string, int> hs;
char s[11];
vector<pair<string, int> > sol;
vector<string> name;
vector<int> from, to, lev, order;
vector<bool> par;

inline int idx() {
	if (hs.find(s) == hs.end()) {
		hs[s] = g.size();
		g.push_back(vector<int>());
		name.push_back(s);
		par.push_back(false);
	}
	return hs[s];
}

inline bool comp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

void DFS(int v, int p) {
	order[T] = v;
	from[v] = T++;
	for (int i = 0; i < g[v].size(); ++i)
		if (g[v][i] != p) {
			lev[g[v][i]] = lev[v] + 1;
			DFS(g[v][i], v);
		}
	to[v] = T - 1;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		if (cas != 1)
			puts("");
		scanf("%d%d", &n, &d);
		hs.clear();
		g.clear();
		name.clear();
		at.clear();
		from.clear();
		lev.clear();
		to.clear();
		order.clear();
		par.clear();
		for (int i = 0, m; i < n; ++i) {
			scanf("%s%d", s, &m);
			int at = idx();
			while (m--) {
				scanf("%s", s);
				int x = idx();
				g[at].push_back(x);
				par[x] = true;
			}
		}
		N = g.size();
		at.resize(N);
		from.resize(N);
		to.resize(N);
		lev.resize(N);
		order.resize(N);
		T = 0;
		for (int i = 0; i < N; ++i)
			if (par[i] == 0) {
				lev[i] = 0;
				DFS(i, -1);
			}
		for (int i = 0; i < N; ++i)
			at[lev[order[i]]].push_back(from[order[i]]);
		sol.clear();
		for (int i = 0; i < N; ++i) {
			int dep = lev[i] + d;
			if (dep >= N)
				continue;
			int l = lower_bound(at[dep].begin(), at[dep].end(), from[i]) - at[dep].begin();
			int r = upper_bound(at[dep].begin(), at[dep].end(), to[i]) - at[dep].begin() - 1;
			if (l <= r)
				sol.push_back(make_pair(name[i], r - l + 1));
		}
		sort(sol.begin(), sol.end(), comp);
		printf("Tree %d:\n", cas++);
		for (int i = 0; i < 3 && i < sol.size(); ++i)
			printf("%s %d\n", sol[i].first.c_str(), sol[i].second);
		int at = 3;
		while (at < sol.size() && sol[at].second == sol[at - 1].second) {
			printf("%s %d\n", sol[at].first.c_str(), sol[at].second);
			++at;
		}
	}
	return 0;
}
