#include <bits/stdc++.h>
using namespace std;

int dp[1500], nxt[3];

int main(int argc, char **argv) {
	int x = 0, y = 0, z = 0;
	dp[0] = 1;
	nxt[0] = dp[x] * 2;
	nxt[1] = dp[y] * 3;
	nxt[2] = dp[z] * 5;
	for (int i = 1; i < 1500; ++i) {
		dp[i] = min(nxt[0], min(nxt[1], nxt[2]));
		if (dp[i] == nxt[0]) {
			x++;
			nxt[0] = dp[x] * 2;
		}
		if (dp[i] == nxt[1]) {
			y++;
			nxt[1] = dp[y] * 3;
		}
		if (dp[i] == nxt[2]) {
			z++;
			nxt[2] = dp[z] * 5;
		}
	}
	printf("The 1500'th ugly number is %d.\n", dp[1499]);
	return 0;
}
