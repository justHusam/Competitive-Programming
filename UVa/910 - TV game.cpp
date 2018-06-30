#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, g[26][2];
ll dp[26][30];
bool E[26];

ll calc(int i, int w) {
	if (w == m)
		return E[i];
	ll &res = dp[i][w];
	if (res != -1)
		return res;
	return res = calc(g[i][0], w + 1) + calc(g[i][1], w + 1);
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i) {
			char a, b, c, d;
			scanf(" %c %c %c %c", &a, &b, &c, &d);
			g[a - 'A'][0] = b - 'A';
			g[a - 'A'][1] = c - 'A';
			E[a - 'A'] = d == 'x';
		}
		scanf("%d", &m);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(0, 0));
	}
	return 0;
}
