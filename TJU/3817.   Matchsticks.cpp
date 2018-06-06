#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, dp[201], mn[] = { 0, 1, 2, 4, 6, 7, 8 }, mx[] = { 0, 1, 4, 5, 7, 8, 9 };
map<int, int> hs;

inline int calc1(int with) {
	if (with == n)
		return 0;
	if (with > n)
		return 2e9;
	if (dp[with] != -1)
		return dp[with];
	int res = 2e9;
	for (int i = !with; i < 7; ++i)
		res = min(res, calc1(with + hs[mn[i]]) + 1);
	return dp[with] = res;
}

inline int calc2(int with) {
	if (with == n)
		return 0;
	if (with > n)
		return -(2e9);
	if (dp[with] != -1)
		return dp[with];
	int res = 0;
	for (int i = !with; i < 7; ++i)
		res = max(res, calc2(with + hs[mx[i]]) + 1);
	return dp[with] = res;
}

inline void path1(int with) {
	if (with == n)
		return;
	int res = 2e9, dig;
	for (int i = !with; i < 7; ++i)
		if (calc1(with + hs[mn[i]]) < res)
			res = calc1(with + hs[mn[i]]), dig = mn[i];
	printf("%d", dig);
	path1(with + hs[dig]);
}

inline void path2(int with) {
	if (with == n)
		return;
	int res = -(2e9), dig;
	for (int i = 6; i >= !with; --i)
		if (calc2(with + hs[mx[i]]) > res)
			res = calc2(with + hs[mx[i]]), dig = mx[i];
	printf("%d", dig);
	path2(with + hs[dig]);
}

int main(int argc, char **argv) {
	hs[0] = 6, hs[1] = 2, hs[2] = 5, hs[3] = 5, hs[4] = 4;
	hs[5] = 5, hs[6] = 6, hs[7] = 3, hs[8] = 7, hs[9] = 6;
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		calc1(0);
		path1(0);
		putchar(' ');
		memset(dp, -1, sizeof dp);
		calc2(0);
		path2(0);
		putchar('\n');
	}
	return 0;
}
