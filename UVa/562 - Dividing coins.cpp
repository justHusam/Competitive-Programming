#include <bits/stdc++.h>
using namespace std;

int n, v[100], dp[500 * 100 + 1][100];

int calc(int s, int ss, int i) {
	if (i == n)
		return abs(s - ss);
	int d = abs(s - ss);
	if (dp[d][i] != -1)
		return dp[d][i];
	int a = calc(s + v[i], ss, i + 1);
	int b = calc(s, ss + v[i], i + 1);
	return dp[d][i] = min(a, b);
}
int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0));
	}
	return 0;
}
