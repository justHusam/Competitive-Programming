#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dp[1001][30], v[30], d[30], w, n, t;
vector<int> res;

int calc(int rem, int at) {
	if (rem == 0 || at == n)
		return 0;
	if (dp[rem][at] != -1)
		return dp[rem][at];
	int res = calc(rem, at + 1), req = w * d[at] + 2 * w * d[at];
	if (rem - req >= 0)
		res = max(res, calc(rem - req, at + 1) + v[at]);
	return dp[rem][at] = res;
}

void path(int rem, int at) {
	if (at == n)
		return;
	int a = calc(rem, at + 1), b = -1, req = w * d[at] + 2 * w * d[at];
	if (rem - req >= 0)
		b = calc(rem - req, at + 1) + v[at];
	if (b >= a) {
		res.push_back(at);
		path(rem - req, at + 1);
		return;
	}
	path(rem, at + 1);
}

int main(int argc, char **argv) {
	bool newLine = false;
	while (scanf("%d%d", &t, &w) > 0) {
		if (newLine)
			puts("");
		newLine = true;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", d + i, v + i);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(t, 0));
		res.clear();
		path(t, 0);
		printf("%d\n", (int) res.size());
		for (size_t i = 0; i < res.size(); ++i)
			printf("%d %d\n", d[res[i]], v[res[i]]);
	}
	return 0;
}
