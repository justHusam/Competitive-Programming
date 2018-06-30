#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, str, k, cost[16][16], dp[16][1 << 16];
char g[20][21];
vector<pair<int, int> > v;

int calc(int v, int msk) {
	if (msk == (1 << k) - 1)
		return cost[v][str];
	int &res = dp[v][msk];
	if (res != -1)
		return res;
	res = 2e9;
	for (int i = 0; i < k; ++i)
		if (((msk >> i) & 1) == 0)
			res = min(res, calc(i, msk | (1 << i)) + cost[v][i]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		v.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] != '.') {
					v.push_back(make_pair(i, j));
					if (g[i][j] == 'L')
						str = v.size() - 1;
				}
			}
		k = v.size();
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				cost[i][j] = max(abs(v[i].first - v[j].first), abs(v[i].second - v[j].second));
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(str, 1 << str));
	}
	return 0;
}
