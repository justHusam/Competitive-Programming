#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, dp[N][N], sum, opt, gre, a[N];

int calc(int a, int b) {
	if (a > b)
		return 0;
	if (dp[a][b] != -1)
		return dp[a][b];
	int c = a[a] + ((a[a + 1] < a[b]) ? (calc(a + 1, b - 1)) : (calc(a + 2, b)));
	int d = a[b] + ((a[a] < a[b - 1]) ? (calc(a, b - 2)) : (calc(a + 1, b - 1)));
	return dp[a][b] = max(c, d);
}

int main(int argc, char **argv) {
	for (int it = 1; scanf("%d", &n) > 0 && n > 0; ++it) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%i", &a[i]);
			sum += a[i];
		}
		memset(dp, -1, sizeof dp);
		int opt = calc(0, n - 1);
		int gre = sum - opt;
		printf("In game %i, the greedy strategy might lose by as many as %d points.\n", it, opt - gre);
	}
	return 0;
}
