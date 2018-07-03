#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char *x, *y;
int n, m;
vector<vector<int> > dp;

int calc(int i, int j) {
	if (i == n)
		return m - j;
	if (j == m)
		return n - i;
	int &res = dp[i][j];
	if (res != -1)
		return res;
	if (x[i] == y[j])
		return res = calc(i + 1, j + 1);
	res = calc(i + 1, j) + 1;
	res = min(res, calc(i, j + 1) + 1);
	res = min(res, calc(i + 1, j + 1) + 1);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		x = new char[n + 9];
		scanf("%s%d", x, &m);
		y = new char[m + 9];
		scanf("%s", y);
		dp = vector<vector<int> >(n, vector<int>(m, -1));
		printf("%d\n", calc(0, 0));
		delete[] x;
		delete[] y;
	}
	return 0;
}
