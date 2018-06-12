#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class CorporationSalary {
public:
	vector<int> g[50];
	ll dp[50];

	long long totalSalary(vector<string> relations) {
		int n = relations.size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (relations[i][j] == 'Y')
					g[i].push_back(j);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i)
			DFS(i);
		ll res = 0;
		for (int i = 0; i < n; ++i)
			res += dp[i];
		return res;
	}

	ll DFS(int v) {
		ll &res = dp[v];
		if (res != -1)
			return res;
		res = 0;
		for (size_t i = 0; i < g[v].size(); ++i)
			res += DFS(g[v][i]);
		if (res == 0)
			++res;
		return res;
	}
};
