// run time = 0.016
#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int n;
vector<int> x, y;
vector<vector<double> > g;
double dp[8][1 << 8];
vector<pair<int, int> > p;

inline double dist(double x, double y, double xx, double yy) {
	double xxx = x - xx;
	double yyy = y - yy;
	return sqrt(xxx * xxx + yyy * yyy) + 16;
}

inline double calc(int at, int msk) {
	if (msk == (1 << n) - 1)
		return 0;
	if (dp[at][msk] != dp[at][msk]) {
		dp[at][msk] = DBL_MAX;
		for (int i = 0; i < n; ++i) {
			if (((msk >> i) & 1) == 1)
				continue;
			dp[at][msk] = min(dp[at][msk], calc(i, msk | (1 << i)) + g[at][i]);
		}
	}
	return dp[at][msk];
}

inline void path(int at, int msk) {
	if (msk == (1 << n) - 1)
		return;
	double res = DBL_MAX;
	int idx;
	for (int i = 0; i < n; ++i) {
		if (((msk >> i) & 1) == 1)
			continue;
		double temp = calc(i, msk | (1 << i)) + g[at][i] - 1e-9;
		if (temp < res) {
			res = temp;
			idx = i;
		}
	}
	p.push_back(make_pair(at, idx));
	path(idx, msk | (1 << idx));
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		x.clear();
		x.resize(n);
		y.clear();
		y.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &x[i], &y[i]);
		g.clear();
		g.resize(n, vector<double>(n, 0));
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				g[i][j] = g[j][i] = dist(x[i], y[i], x[j], y[j]);
		memset(dp, -1, sizeof dp);
		double res = DBL_MAX;
		int idx;
		for (int i = 0; i < n; ++i) {
			double temp = calc(i, 0 | (1 << i));
			if (temp < res) {
				res = temp;
				idx = i;
			}
		}
		p.clear();
		path(idx, 0 | (1 << idx));
		puts("**********************************************************");
		static int k = 1;
		printf("Network #%d\n", k++);
		for (size_t i = 0; i < p.size(); ++i) {
			int i = p[i].first;
			int j = p[i].second;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[i], y[i], x[j], y[j], g[i][j]);
		}
		printf("Number of feet of cable required is %.2lf.\n", res);
	}
	return 0;
}
