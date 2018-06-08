#include <bits/stdc++.h>
using namespace std;

char a[2010], b[2010];
int dp[2010][2010], n, m;

int calc(int i, int j) {
	if (i == n && j == m)
		return 0;
	if (i > n || j > m)
		return 2e9;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (a[i] == b[j])
		return dp[i][j] = calc(i + 1, j + 1);
	int x = 1 + calc(i, j + 1);
	int y = 1 + calc(i + 1, j + 1);
	int z = 1 + calc(i + 1, j);
	return dp[i][j] = min(x, min(y, z));
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		memset(dp, -1, sizeof dp);
		scanf("%s%s", a, b);
		n = strlen(a);
		m = strlen(b);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
