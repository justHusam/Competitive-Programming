#include <bits/stdc++.h>
using namespace std;

const int N = 100;
char x[N], y[N], res[N];
int n, m, dp[N][N];
vector<int> nxt1[26], nxt2[26];

inline int calc(int i, int j) {
	if (i == n || j == m)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i] == y[j])
		return dp[i][j] = calc(i + 1, j + 1) + 1;
	int a = calc(i + 1, j);
	int b = calc(i, j + 1);
	return dp[i][j] = max(a, b);
}

inline void path(int i, int j, int idx) {
	if (idx == calc(0, 0)) {
		puts(res);
		return;
	}
	for (int i = 0; i < 26; ++i) {
		size_t u = lower_bound(nxt1[i].begin(), nxt1[i].end(), i) - nxt1[i].begin();
		size_t v = lower_bound(nxt2[i].begin(), nxt2[i].end(), j) - nxt2[i].begin();
		if (u == nxt1[i].size() || v == nxt2[i].size() || calc(0, 0) - idx != calc(nxt1[i][u] + 1, nxt2[i][v] + 1) + 1)
			continue;
		res[idx] = char(i + 'a');
		path(nxt1[i][u] + 1, nxt2[i][v] + 1, idx + 1);
	}
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s%s", x, y);
		n = strlen(x);
		m = strlen(y);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < 26; ++i)
			nxt1[i].clear(), nxt2[i].clear();
		for (int i = 0; i < n; ++i)
			nxt1[x[i] - 'a'].push_back(i);
		for (int i = 0; i < m; ++i)
			nxt2[y[i] - 'a'].push_back(i);
		res[calc(0, 0)] = '\0';
		path(0, 0, 0);
	}
	return 0;
}
