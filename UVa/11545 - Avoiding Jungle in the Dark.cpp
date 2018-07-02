#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

char s[1111];
int n, dp[1000][24][17];
const int oo = 2e9;

inline int calc(int i, int h, int w) {
	if (w > 16)
		return oo;
	if (s[i] == 'D')
		return 0;
	if (dp[i][h][w] != -1)
		return dp[i][h][w];
	int res = oo;
	if (s[i] == '.') {
		res = min(res, calc(i + 1, (h + 1) % 24, w + 1) + 1);
		if (w != 0) {
			res = min(res, calc(i, (h + 8) % 24, 0) + 8);
			res = min(res, calc(i, (h + 16) % 24, 0) + 16);
		}
	} else if (h > 6 && h < 18)
		res = min(res, calc(i + 1, (h + 1) % 24, w + 1) + 1);
	return dp[i][h][w] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		n = strlen(s);
		memset(dp, -1, sizeof dp);
		int res = calc(1, 7, 1);
		printf("Case #%d: ", k++);
		if (res == oo)
			puts("-1");
		else
			printf("%d\n", res + 1);
	}
	return 0;
}
