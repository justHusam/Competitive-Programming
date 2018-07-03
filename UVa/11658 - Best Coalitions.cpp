#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int n, x;
double g[100];
map<double, double> dp[100];

inline double rnd(const double&x) {
	int a = (x + 1e-9) * 1000;
	int b = a % 10;
	a /= 10;
	if (b > 4)
		++a;
	return double(a) / 100 + 1e-9;
}

double calc(int at, double avg) {
	if (at == n) {
		if (avg - 1e-9 > 50)
			return rnd(g[x] / avg * double(100));
		return 0;
	}
	if (dp[at].find(avg) != dp[at].end())
		return dp[at][avg];
	if (at == x)
		return dp[at][avg] = calc(at + 1, rnd(avg + g[at]));
	double a = calc(at + 1, avg);
	double b = calc(at + 1, rnd(avg + g[at]));
	return dp[at][avg] = max(a, b);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &x) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%lf", g + i);
		for (int i = 0; i < n; ++i)
			dp[i].clear();
		--x;
		printf("%.2lf\n", rnd(calc(0, 0)));
	}
	return 0;
}
