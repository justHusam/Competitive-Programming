#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, dp[N][N], vis[N][N], vs;
char s[N + 1];

int calc(int l, int r) {
	if (l >= r)
		return 0;
	int &res = dp[l][r];
	if (vis[l][r] == vs)
		return res;
	vis[l][r] = vs;
	res = 2e9;
	if (s[l] == s[r])
		res = min(res, calc(l + 1, r - 1));
	res = min(res, calc(l + 1, r) + 1);
	res = min(res, calc(l, r - 1) + 1);
	return res;
}

void path(int l, int r) {
	if (l >= r) {
		if (l == r)
			putchar(s[l]);
		return;
	}
	int best = calc(l, r);
	if (s[l] == s[r] && calc(l + 1, r - 1) == best) {
		putchar(s[l]);
		path(l + 1, r - 1);
		putchar(s[r]);
		return;
	}
	if (calc(l + 1, r) + 1 == best)
		path(l + 1, r);
	else
		path(l, r - 1);
}

int main(int argc, char **argv) {
	while (scanf("%s", s) != EOF) {
		n = strlen(s);
		++vs;
		calc(0, n - 1);
		path(0, n - 1);
		putchar('\n');
	}
	return 0;
}
