#include <bits/stdc++.h>
using namespace std;

int mnf, mxy, mxx;
int dp[12][12][12], g[12][12][12];

int calc(int f, int y, int x) {
	if (f < mnf || y > mxy || x > mxx)
		return 0;
	if (dp[f][y][x] != -1)
		return dp[f][y][x];
	int a = calc(f, y, x + 1);
	int b = calc(f, y + 1, x);
	int c = calc(f - 1, y, x);
	return dp[f][y][x] = g[f][y][x] + max(a, max(b, c));
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		memset(g, 0, sizeof g);
		mnf = 10, mxy = 1, mxx = 1;
		while (n-- != 0) {
			int f, y, x, c;
			scanf("%d %d %d %d", &f, &y, &x, &c);
			g[f][y][x] = c;
			mnf = min(mnf, f);
			mxy = max(mxy, y);
			mxx = max(mxx, x);
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(10, 1, 1));
	}
	return 0;
}
