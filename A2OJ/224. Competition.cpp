#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int calc(int i, int j, int k) {
	if (k == 0)
		return min(i / 2, j);
	if (i < 0 || j < 0)
		return -2e9;
	int &res = dp[i][j][k];
	if (res != -1)
		return res;
	return res = max(calc(i - 1, j, k - 1), calc(i, j - 1, k - 1));
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int m, n, k;
		scanf("%d%d%d", &m, &n, &k);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(m, n, k));
	}
	return 0;
}
