#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e3 + 10;
int dp[N][N][4], t, x, y, H[] = { 3, -5, -20 }, A[] = { 2, -10, 5 }; // x = h , y =a;

int calc(int hel, int arm, int pos) {
	if (hel < 1 || arm < 1)
		return 0;
	if (dp[hel][arm][pos] != -1)
		return dp[hel][arm][pos];
	int res = 0;
	for (int i = 0; i < 3; ++i)
		if (i != pos)
			res = max(res, calc(hel + H[i], arm + A[i], i) + 1);
	return dp[hel][arm][pos] = res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(x, y, 3) - 1);
	}
	return 0;
}
