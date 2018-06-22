#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, dp[101];

bool check(int k) {
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
		dp[i] = (dp[i - 1] + k - 1) % i + 1;
	return dp[n - 1] == 12;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		int res = 0;
		for (int i = 1;; ++i)
			if (check(i)) {
				res = i;
				break;
			}
		printf("%d\n", res);
	}
	return 0;
}
