#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

double dist(const pair<double, double> & f, const pair<double, double> & s) {
	double a = f.first - s.first;
	double b = f.second - s.second;
	return sqrt(a * a + b * b);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T--) {
		double d;
		int n;
		scanf("%lf%d", &d, &n);
		vector<pair<double, double> > v(1, make_pair(25, 0));
		for (int i = 0; i < n; ++i) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			v.push_back(make_pair(x, y));
		}
		v.push_back(make_pair(25, 50));
		vector<vector<int> > g(n + 2, vector<int>(n + 2, oo));
		for (size_t i = 0; i < v.size(); ++i)
			for (size_t j = i + 1; j < v.size(); ++j) {
				double dif = dist(v[i], v[j]);
				if (dif <= d || fabs(dif - d) <= 0.0000001)
					g[i][j] = g[j][i] = 1;
			}
		for (int k = 0; k < n + 2; ++k)
			for (int i = 0; i < n + 2; ++i)
				for (int j = 0; j < n + 2; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		if (g[0][n + 1] == oo) {
			puts("Impossible");
			continue;
		}
		printf("%d\n", g[0][n + 1]);
	}
	return 0;
}
