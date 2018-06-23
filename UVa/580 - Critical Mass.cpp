#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, add[] = { 3, 31 };
vector<vector<vector<vector<ll> > > > dp;

ll calc(int at, int type, int len, bool bad) {
	if (at == n)
		return bad;
	ll &res = dp[at][type][len][bad];
	if (res != -1)
		return res;
	res = 0;
	res += calc(at + 1, type, min(len + 1, add[type]), bad || (len + 1 >= add[type]));
	res += calc(at + 1, type ^ 1, 1, bad);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		dp.clear();
		dp.resize(n);
		for (int i = 0; i < n; ++i)
			dp[i].resize(2, vector<vector<ll> >(32, vector<ll>(2, -1)));
		printf("%lld\n", calc(1, 0, 1, false) + calc(1, 1, 1, false));
	}
	return 0;
}
