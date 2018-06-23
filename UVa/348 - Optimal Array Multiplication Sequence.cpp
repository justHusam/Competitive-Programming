#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n;
ll dp[11][11];
vector<pair<ll, ll> > g;
string ss, hs[12];

ll calc(int s, int e) {
	if (s == e)
		return dp[s][e] = 0;
	if (dp[s][e] != -1)
		return dp[s][e];
	ll res = 2e9;
	for (int i = s; i < e; ++i)
		res = min(res, calc(s, i) + calc(i + 1, e) + g[s].first * g[e].second * g[i].second);
	return dp[s][e] = res;
}

void path(int s, int e) {
	if (e == s) {
		ss += "A";
		ss += hs[s + 1];
		return;
	}
	ss += "(";
	if (e - s == 1) {
		ss += "A";
		ss += hs[s + 1];
		ss += " x A";
		ss += hs[e + 1];
		ss += ")";
		return;
	}
	ll mn = 2e9, idx;
	for (int a = s; a < e; ++a) {
		ll temp = calc(s, a) + calc(a + 1, e) + g[s].first * g[e].second * g[a].second;
		if (temp < mn)
			mn = temp, idx = a;
	}
	path(s, idx);
	ss += " x ";
	path(idx + 1, e);
	ss += ")";
}

int main(int argc, char **argv) {
	hs[1] = "1";
	hs[2] = "2";
	hs[3] = "3";
	hs[4] = "4";
	hs[5] = "5";
	hs[6] = "6";
	hs[7] = "7";
	hs[8] = "8";
	hs[9] = "9";
	hs[10] = "10";
	int k = 1;
	while (scanf("%d", &n) && n) {
		g = vector<pair<ll, ll> >(n);
		for (int i = 0; i < n; ++i)
			scanf("%lld%lld", &g[i].first, &g[i].second);
		memset(dp, -1, sizeof dp);
		calc(0, n - 1);
		ss = "";
		path(0, n - 1);
		printf("Case %d: %s\n", k++, ss.c_str());
	}
	return 0;
}
