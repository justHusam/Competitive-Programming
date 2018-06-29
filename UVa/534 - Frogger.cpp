#include <bits/stdc++.h>
using namespace std;

double dist(const pair<int, int> & f, const pair<int, int> & s) {
	double a = f.first - s.first;
	double b = f.second - s.second;
	return sqrt(a * a + b * b);
}

int main(int argc, char **argv) {
	int n;
	for (int caseN = 1; scanf("%d", &n) > 0 && n != 0; ++caseN) {
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; ++i)
			scanf("%i %i", &v[i].first, &v[i].second);
		vector<vector<double> > g(n, vector<double>(n));
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				g[i][j] = g[j][i] = dist(v[i], v[j]);
		priority_queue<pair<double, int> > qu;
		vector<bool> vis(n, false);
		qu.push(make_pair(0, 0));
		double res = 0;
		while (!qu.empty()) {
			pair<double, int> e = qu.top();
			qu.pop();
			if (e.second == 1) {
				res = -e.first;
				break;
			}
			if (vis[e.second])
				continue;
			vis[e.second] = true;
			for (int i = 0; i < n; ++i) {
				double c = max(-e.first, g[e.second][i]);
				if (!vis[i])
					qu.push(make_pair(-c, i));
			}
		}
		printf("Scenario #%i\n", caseN);
		printf("Frog Distance = %.3lf\n\n", res);
	}
	return 0;
}
