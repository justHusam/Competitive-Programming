#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, m;
	for (int caseN = 1; cin >> n >> m && n + m > 0; ++caseN) {
		vector<vector<pair<int, int> > > g(n);
		map<string, int> hs;
		int ID = 0;
		while (m-- != 0) {
			string i, j;
			int c;
			cin >> i >> j >> c;
			if (hs.find(i) == hs.end())
				hs[i] = ID++;
			if (hs.find(j) == hs.end())
				hs[j] = ID++;
			g[hs[i]].push_back(make_pair(hs[j], c));
			g[hs[j]].push_back(make_pair(hs[i], c));
		}
		string s, e;
		cin >> s >> e;
		int tar = hs[e], res = -1;
		priority_queue<pair<int, int> > qu;
		bitset<202> vis;
		vis.reset();
		qu.push(make_pair(1 << 30, hs[s]));
		while (!qu.empty()) {
			pair<int, int> e = qu.top();
			qu.pop();
			if (e.second == tar) {
				res = e.first;
				break;
			}
			if (vis[e.second])
				continue;
			vis[e.second] = 1;
			for (size_t i = 0; i < g[e.second].size(); ++i) {
				int v = g[e.second][i].first;
				int c = min(e.first, g[e.second][i].second);
				if (!vis[v])
					qu.push(make_pair(c, v));
			}
		}
		printf("Scenario #%d\n%d tons\n\n", caseN, res);
	}
	return 0;
}
