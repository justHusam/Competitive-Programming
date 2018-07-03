#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char s[62];
ll dp[60][60];

ll calc(int i, int j) {
	if (i == j)
		return 1;
	if (i > j || j < 0)
		return 0;
	if (j - i + 1 == 2)
		return 2 + (s[i] == s[j]);
	if (dp[i][j] != -1)
		return dp[i][j];
	ll res = 0;
	if (s[i] == s[j])
		res += calc(i + 1, j - 1) + 1;
	res += calc(i + 1, j);
	res += calc(i, j - 1);
	res -= calc(i + 1, j - 1);
	return dp[i][j] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s", s);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(0, strlen(s) - 1));
	}
	return 0;
}
