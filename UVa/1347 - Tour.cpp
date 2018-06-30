#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<double, double> > v;
vector<vector<double> > dp, cost;

double calc(int a, int b) {
	int v = max(a, b) + 1;
	if (v == n - 1)
		return cost[a][v] + cost[v][b];
	double &res = dp[a][b];
	if (res != -1)
		return res;
	return res = min(calc(v, b) + cost[a][v], calc(a, v) + cost[v][b]);
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &v[i].first, &v[i].second);
		cost.clear();
		cost.resize(n, vector<double>(n));
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				cost[i][j] = cost[j][i] = hypot(v[i].first - v[j].first, v[i].second - v[j].second);
		dp.clear();
		dp.resize(n, vector<double>(n, -1));
		printf("%.2lf\n", calc(0, 0));
	}
	return 0;
}
