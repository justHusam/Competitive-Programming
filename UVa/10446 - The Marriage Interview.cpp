#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef unsigned long long ll;

ll dp[62];
int n, b, k;

ll calc(int n) {
	if (n <= 1)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	ll s = 1;
	for (int a = 1; a <= b; a++)
		s += calc(n - a);
	return dp[n] = s;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &b) && n <= 60) {
		memset(dp, -1, sizeof dp);
		cout << "Case " << ++k << ": " << calc(n) << "\n";
	}
	return 0;
}
