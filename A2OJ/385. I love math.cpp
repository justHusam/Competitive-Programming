#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int M = 1e9 + 7;
int n, dp[1000][2];

int calc(int i, int l) {
	if (i == n)
		return 1;
	int &res = dp[i][l];
	if (res != -1)
		return res;
	res = calc(i + 1, 1);
	if (l != 0)
		res = (res + calc(i + 1, 0)) % M;
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 1));
	}
	return 0;
}
