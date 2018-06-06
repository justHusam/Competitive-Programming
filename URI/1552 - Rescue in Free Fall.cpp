#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

double dist(const pair<double, double>& f, const pair<double, double>& s) {
	double a = f.first - s.first;
	double b = f.second - s.second;
	return sqrt(a * a + b * b);
}

double conv(double d) {
	return floor(d + 0.5);
}

int main(int argc, char **argv) {
	int t;
	scanf("%i", &t);
	while (t-- != 0) {
		int n;
		scanf("%i", &n);
		if (n == 0)
			break;
		vector<pair<double, double> > v(n);
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &v[i].first, &v[i].second);
		vector<vector<double> > g(n, vector<double>(n));
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				g[i][j] = g[j][i] = dist(v[i], v[j]);
		vector<double> cost(n, oo);
		priority_queue<pair<double, int> > qu;
		qu.push(make_pair(0, 0));
		cost[0] = 0;
		double res = 0;
		bitset<502> vis;
		vis.reset();
		while (!qu.empty()) {
			pair<double, int> t = qu.top();
			qu.pop();
			if (vis[t.second])
				continue;
			vis[t.second] = 1;
			res -= t.first;
			for (size_t i = 0; i < g[t.second].size(); ++i) {
				if (vis[i] || g[t.second][i] >= cost[i])
					continue;
				cost[i] = g[t.second][i];
				qu.push(make_pair(-g[t.second][i], i));
			}
		}
		printf("%.2lf\n", (conv(res) / 100));
	}
	return 0;
}
