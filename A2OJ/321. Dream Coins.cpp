#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	ll x, y, z, v;
	state() {
	}
	state(ll x, ll y, ll z, ll v) :
			x(x), y(y), z(z), v(v) {
	}
	inline bool operator<(const state&e) const {
		return e.z > z;
	}
} v[1000];

int n;
ll dp[1002][1002];

inline ll calc(int i, int l) {
	if (i == n)
		return 0;
	if (dp[i][l] != -1)
		return dp[i][l];
	ll res = calc(i + 1, l);
	if (l == n || abs(v[i].x - v[l].x) + abs(v[i].y - v[l].y) < v[i].z - v[l].z)
		res = max(res, calc(i + 1, i) + ll(v[i].v));
	return dp[i][l] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld%lld%lld%lld", &v[i].x, &v[i].y, &v[i].z, &v[i].v);
		sort(v, v + n);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %lld\n", k++, calc(0, n));
	}
	return 0;
}
