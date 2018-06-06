#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll dp[18][2];

ll calc(int at, bool zero) {
	if (at == n)
		return 1;
	ll &res = dp[at][zero];
	if (res != -1)
		return res;
	res = calc(at + 1, false) * (k - 1);
	if (at != 0 && !zero)
		res += calc(at + 1, true);
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", calc(0, false));
	return 0;
}
