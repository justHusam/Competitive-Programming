#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class TheSumOfLuckyNumbers {
public:
	vector<int> v, res;
	int dp[1000001];

	vector<int> sum(int n) {
		queue<int> qu;
		if (4 <= n)
			qu.push(4);
		if (7 <= n)
			qu.push(7);
		while (!qu.empty()) {
			int fr = qu.front();
			qu.pop();
			v.push_back(fr);
			if (fr * 10 + 4 <= n)
				qu.push(fr * 10 + 4);
			if (fr * 10 + 7 <= n)
				qu.push(fr * 10 + 7);
		}
		memset(dp, -1, sizeof dp);
		if (calc(n) != 2e9)
			path(n);
		return res;
	}

	int calc(int n) {
		if (n == 0)
			return 0;
		if (n < 0)
			return 2e9;
		if (dp[n] != -1)
			return dp[n];
		dp[n] = 2e9;
		for (size_t i = 0; i < v.size(); ++i)
			dp[n] = min(dp[n], calc(n - v[i]) + 1);
		return dp[n];
	}

	void path(int n) {
		if (n == 0)
			return;
		int mn = 2e9, idx = -1;
		for (size_t i = 0; i < v.size(); ++i)
			if (calc(n - v[i]) + 1 < mn)
				mn = calc(n - v[i]) + 1, idx = i;
		res.push_back(v[idx]);
		path(n - v[idx]);
	}
};
