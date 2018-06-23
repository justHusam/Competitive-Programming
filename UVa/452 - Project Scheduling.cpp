#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 26;
char s[1111];
vector<int> g[N];
int in[N], cost[N], dp[N];

int calc(int v) {
	int &res = dp[v];
	if (res != -1)
		return res;
	res = 0;
	for (size_t i = 0; i < g[v].size(); ++i)
		res = max(res, calc(g[v][i]) + cost[g[v][i]]);
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	getchar();
	getchar();
	while (T-- != 0) {
		for (int i = 0; i < N; ++i)
			g[i].clear(), in[i] = 0, cost[i] = -1;
		while (gets(s) > 0 && strlen(s)) {
			stringstream ss(s);
			char u, v;
			int k;
			ss >> u >> k;
			cost[u - 'A'] = k;
			while (ss >> v) {
				g[v - 'A'].push_back(u - 'A');
				++in[u - 'A'];
			}
		}
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < N; ++i)
			if (in[i] == 0 && cost[i] != -1)
				res = max(res, calc(i) + cost[i]);
		printf("%d\n", res);
		if (T != 0)
			puts("");
	}
	return 0;
}
