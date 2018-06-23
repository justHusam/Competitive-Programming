#include <bits/stdc++.h>
using namespace std;

vector<int> g[28];
bool arr[28];
char x, y[28];
double val[28], v;
set<char> st;

double BFS(int src, double val) {
	queue<pair<int, double> > qu;
	bool vis[28] = { };
	if (arr[src])
		return val;
	vis[src] = true;
	qu.push(make_pair(src, val));
	while (!qu.empty()) {
		pair<int, double> e = qu.front();
		qu.pop();
		for (size_t i = 0; i < g[e.first].size(); ++i) {
			if (vis[g[e.first][i]])
				continue;
			if (arr[g[e.first][i]])
				return e.second;
			vis[g[e.first][i]] = true;
			qu.push(make_pair(g[e.first][i], (e.second - e.second * 0.05)));
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0) {
		memset(arr, 0, sizeof arr);
		pair<double, char> res = make_pair(0, 'a');
		st.clear();
		for (int i = 0; i < n + 2; ++i)
			g[i].clear();
		for (int i = 0; i < n; ++i) {
			scanf(" %c%lf%s", &x, &v, y);
			st.insert(x);
			val[x - 'A'] = v;
			int m = strlen(y);
			for (int j = 0; j < m; ++j) {
				if (y[j] == '*') {
					arr[x - 'A'] = 1;
					continue;
				}
				st.insert(y[j]);
				g[x - 'A'].push_back(y[j] - 'A');
				g[y[j] - 'A'].push_back(x - 'A');
			}
		}
		for (set<char>::iterator it = st.begin(); it != st.end(); it++) {
			double temp = BFS((*it) - 'A', val[(*it) - 'A']);
			if (temp > res.first || (temp == res.first && char(*it) < res.second))
				res = make_pair(temp, *it);
		}
		printf("Import from %c\n", res.second);
	}
	return 0;
}
