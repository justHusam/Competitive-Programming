#include <bits/stdc++.h>
using namespace std;

const int N = 66;
int n, T, dp[N][N], res[N][N];

int check(int i, int j, int k, int l) {
	int ones = dp[k][l] - dp[i - 1][l] - dp[k][j - 1] + dp[i - 1][j - 1];
	int area = (k - i + 1) * (l - j + 1);
	int zeros = area - ones;
	double A = ones * 1.0 / area * 100;
	double B = zeros * 1.0 / area * 100;
	if (A >= T || fabs(A - T) < 1e-6)
		return 1;
	if (B >= T || fabs(B - T) < 1e-6)
		return 0;
	return -1;
}

void calc(int i, int j, int k, int l) {
	int C = check(i, j, k, l);
	if (C == -1) {
		int M = (k - i + 1) / 2;
		calc(i, j + M, i + M - 1, l);
		calc(i, j, i + M - 1, j + M - 1);
		calc(i + M, j, k, j + M - 1);
		calc(i + M, j + M, k, l);
	} else {
		for (int a = i; a <= k; ++a)
			for (int b = j; b <= l; ++b)
				res[a][b] = C;
	}
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &T);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				char c;
				scanf(" %c", &c);
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + (c == '1');
			}
		calc(1, 1, n, n);
		printf("Image %d:\n", cas++);
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < n; ++j)
				printf("%d", res[i + 1][j + 1]);
	}
	return 0;
}
