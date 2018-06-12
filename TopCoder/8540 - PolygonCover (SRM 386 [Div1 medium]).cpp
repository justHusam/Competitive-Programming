#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int a, b, c;
	double cost;
	state(int a, int b, int c, double cost) :
			a(a), b(b), c(c), cost(cost) {
	}
};

double eps = 1e-9;
const int N = 15;
int pre[N][N][N];
double dp[1 << N];
vector<double> X, Y;
int n;
vector<state> v;

class PolygonCover {
public:
	double getArea(vector<int> x, vector<int> y) {
		n = x.size();
		X.resize(n);
		Y.resize(n);
		for (int i = 0; i < n; ++i)
			X[i] = x[i], Y[i] = y[i];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				for (int k = 0; k < n; ++k) {
					if (k == i || k == j || triangle(i, j, k))
						continue;
					v.push_back(state(i, j, k, area(i, j, k)));
					for (int l = 0; l < n; ++l)
						if (check(i, j, k, l))
							pre[i][j][k] = pre[i][j][k] | (1 << l);
				}
			}
		for (int i = 0; i < (1 << n); ++i)
			dp[i] = -1;
		return calc(0);
	}

	inline double area(int a, int b, int c) {
		double z = X[a] * (Y[b] - Y[c]);
		z += X[b] * (Y[c] - Y[a]);
		z += X[c] * (Y[a] - Y[b]);
		return fabs(z / 2);
	}

	inline bool triangle(int h, int i, int j) {
		double m1 = (Y[i] - Y[h]) / (X[i] - X[h]);
		double m2 = (Y[j] - Y[i]) / (X[j] - X[i]);
		return m1 == m2 || fabs(m2 - m1) < 0.0000001;
	}

	inline bool check(int a, int b, int c, int d) {
		if (d == a || d == b || d == c)
			return 1;
		double x = area(a, b, c);
		double y = area(d, b, c);
		double z = area(a, d, c);
		double w = area(a, b, d);
		return x == y + z + w || fabs(x - (y + z + w)) < eps;
	}

	inline double calc(int msk) {
		if (msk == (1 << n) - 1)
			return 0;
		if (dp[msk] != -1)
			return dp[msk];
		double res = DBL_MAX;
		for (size_t i = 0; i < v.size(); ++i)
			if (!((msk >> v[i].a) & 1) || !((msk >> v[i].b) & 1) || !((msk >> v[i].c) & 1))
				res = min(res, calc(msk | pre[v[i].a][v[i].b][v[i].c]) + v[i].cost);
		return dp[msk] = res;
	}
};
