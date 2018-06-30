#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, vis[100][11], vs;
double dp[100][11];

double calc(int i, int p) {
	if (i == n)
		return 1;
	double &res = dp[i][p];
	if (vis[i][p] == vs)
		return res;
	vis[i][p] = vs;
	res = 0;
	for (int j = -1; j <= 1; ++j)
		if (p + j >= 0 && p + j <= k)
			res += calc(i + 1, p + j);
	return res;
}

double get(int n) {
	if (n == 0)
		return 1;
	return get(n - 1) * (k + 1);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &k, &n) > 0) {
		++vs;
		double res = 0;
		for (int i = 0; i <= k; ++i)
			res += calc(1, i);
		printf("%.5lf\n", res / get(n) * 100);
	}
	return 0;
}
