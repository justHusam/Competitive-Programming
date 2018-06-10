#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

vector<pair<int, pair<int, int> > > v;
int m, ox, nt;
int dp[1000][22][80];

int calc(int idx, int o, int n) {
	if (o >= ox && n >= nt)
		return 0;
	if (idx == m)
		return 2e9;
	if (dp[idx][o][n] != -1)
		return dp[idx][o][n];
	int a = calc(idx + 1, min(o + v[idx].first, ox), min(n + v[idx].second.first, nt)) + v[idx].second.second;
	int b = calc(idx + 1, o, n);
	return dp[idx][o][n] = min(a, b);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d%d", &ox, &nt, &m);
		v.clear();
		v.resize(m);
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &v[i].first, &v[i].second.first, &v[i].second.second);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0));
	}
	return 0;
}
