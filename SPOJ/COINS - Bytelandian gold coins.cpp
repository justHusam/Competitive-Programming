#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

map<int, ll> dp;

inline ll calc(ll n) {
	if (n == 0)
		return 0;
	if (dp.find(n) != dp.end())
		return dp[n];
	ll a = calc(n / 2) + calc(n / 3) + calc(n / 4);
	return dp[n] = max(a, n);
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0)
		cout << calc(n) << "\n";
	return 0;
}
