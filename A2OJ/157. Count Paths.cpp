#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e9 + 7;
int n, m, dp[101][101];

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != -1 && m != -1)) {
		dp[0][0] = 1;
		for (int i = 0; i <= n; ++i)
			for (int j = i ? 0 : 1; j <= m; ++j) {
				dp[i][j] = 0;
				if (i - 1 >= 0)
					dp[i][j] += dp[i - 1][j];
				if (j - 1 >= 0)
					dp[i][j] += dp[i][j - 1];
				dp[i][j] %= M;
			}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
