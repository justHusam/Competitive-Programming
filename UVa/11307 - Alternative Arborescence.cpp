#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, in[N], dp[N][11];
vector<int> g[N];
char s[111111];

int calc(int v, int c) {
	int &res = dp[v][c];
	if (res != -1)
		return res;
	res = 0;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int mn = 2e9;
		for (int j = 1; j <= 10; ++j)
			if (c != j)
				mn = min(mn, calc(g[v][i], j) + j);
		res += mn;
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear(), in[i] = 0;
		getchar();
		for (int i = 0; i < n; ++i) {
			gets(s);
			stringstream ss(s);
			int u, v;
			char x;
			ss >> u >> x;
			while (ss >> v) {
				g[u].push_back(v);
				++in[v];
			}
		}
		memset(dp, -1, sizeof dp);
		int res = 2e9;
		for (int i = 0; i < n; ++i)
			if (in[i] == 0) {
				for (int j = 1; j <= 10; ++j)
					res = min(res, calc(i, j) + j);
				break;
			}
		printf("%d\n", res);
	}
	return 0;
}
