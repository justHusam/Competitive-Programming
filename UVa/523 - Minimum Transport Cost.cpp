#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int T;
	scanf("%d\n", &T);
	while (T-- != 0) {
		string s;
		getline(cin, s);
		vector<int> v;
		stringstream ss(s);
		while (!ss.eof()) {
			int x;
			ss >> x;
			v.push_back(x);
		}
		int n = v.size();
		vector<vector<pair<int, int> > > g(n);
		for (int i = 1; i < n; ++i)
			if (v[i] != -1)
				g[0].push_back(make_pair(i, v[i]));
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				int x;
				scanf("%d", &x);
				if (i == j || x == -1)
					continue;
				g[i].push_back(make_pair(j, x));
			}
		vector<int> E(n);
		for (int i = 0; i < n; ++i)
			scanf("%d\n", &E[i]);
		bool newLine = false;
		while (getline(cin, s) && !s.empty()) {
			if (newLine)
				puts("");
			newLine = true;
			stringstream ss(s);
			int src, dest;
			ss >> src >> dest;
			printf("From %d to %d :\n", src, dest);
			--src, --dest;
			priority_queue<pair<int, int> > qu;
			qu.push(make_pair(0, src));
			vector<int> cost(n, 2e9), par(n, -1);
			vector<int> vis(n, 0);
			cost[src] = 0;
			while (!qu.empty()) {
				pair<int, int> e = qu.top();
				qu.pop();
				if (vis[e.second])
					continue;
				vis[e.second] = 1;
				if (e.second == dest) {
					printf("Path:");
					vector<int> v;
					for (int n = dest; n != -1; n = par[n])
						v.push_back(n + 1);
					string s = " ";
					while (v.size()) {
						printf("%s%d", s.c_str(), v.back());
						v.pop_back();
						s = "-->";
					}
					printf("\nTotal cost : %d\n", -e.first);
					break;
				}
				for (size_t i = 0; i < g[e.second].size(); ++i) {
					int u = g[e.second][i].first, c = -e.first + g[e.second][i].second;
					if (u != dest)
						c += E[u];
					if (vis[u] || c >= cost[u])
						continue;
					cost[u] = c;
					par[u] = e.second;
					qu.push(make_pair(-c, u));
				}
			}
		}
	}
	return 0;
}
