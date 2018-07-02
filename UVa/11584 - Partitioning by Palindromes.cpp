#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e3;
int n, dp[N][N], vis[N][N], id;
char s[N + 9];

bool check(int a, int b) {
	while (a < b)
		if (s[a++] != s[b--])
			return false;
	return true;
}

int calc(int i, int len) {
	if (i + len > n)
		return n - i;
	if (i == n)
		return 0;
	if (vis[i][len] == id)
		return dp[i][len];
	vis[i][len] = id;
	int res = 2e9;
	if (check(i, i + len - 1))
		res = min(res, calc(i + len, 1) + 1);
	res = min(res, calc(i, len + 1));
	return dp[i][len] = res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		n = strlen(s);
		++id;
		printf("%d\n", calc(0, 1));
	}
	return 0;
}
