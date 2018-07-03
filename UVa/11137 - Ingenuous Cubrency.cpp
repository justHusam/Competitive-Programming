#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

vector<int> g;
const int N = 1e4 + 2;
ll dp[N][22];

ll calc(int rem, int at) {
	if (rem < 0)
		return 0;
	if (rem == 0)
		return 1;
	if (dp[rem][at] != -1)
		return dp[rem][at];
	ll res = 0;
	for (size_t i = at; i < g.size(); ++i)
		res += calc(rem - g[i], i);
	return dp[rem][at] = res;
}

int main(int argc, char **argv) {
	for (int i = 1; i <= 21; ++i)
		g.push_back(pow(i, 3));
	int n;
	memset(dp, -1, sizeof dp);
	while (scanf("%d", &n) > 0)
		cout << calc(n, 0) << "\n";
	return 0;
}
