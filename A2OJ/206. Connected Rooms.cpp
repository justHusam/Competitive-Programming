#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 15;
vector<int> g[N];
ll need[N], in[N];
int n, dp[N][1 << N];

int calc(int v, int msk) {
	int &res = dp[v][msk];
	if (res != -1)
		return res;
	res = 0;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (((msk >> u) & 1) == 1)
			continue;
		ll can = 0;
		for (int i = 0; i < n; ++i)
			if (((msk >> i) & 1) == 1)
				can |= in[i];
		if ((can & need[u]) == need[u])
			res = max(res, calc(u, msk | (1 << u)) + 1);
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			need[i] = in[i] = 0;
		}
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			while (x-- != 0) {
				int j;
				scanf("%d", &j);
				--j;
				need[i] |= (1LL << j);
			}
		}
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			while (x-- != 0) {
				int j;
				scanf("%d", &j);
				--j;
				in[i] |= (1LL << j);
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				char c;
				scanf(" %c", &c);
				if (c == 'Y')
					g[i].push_back(j);
			}
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < n; ++i)
			res = max(res, calc(i, 1 << i) + 1);
		printf("%d\n", res);
	}
	return 0;
}
