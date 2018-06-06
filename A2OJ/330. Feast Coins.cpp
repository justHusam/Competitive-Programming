#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 50;
int n, sum, c[N], v[N], vis[5001][N], vs, cnt;
ll dp[5001][N];

ll calc(int w, int i) {
	if (i == n)
		return w == sum;
	if (w > sum)
		return 0;
	if (vis[w][i] == vs)
		return dp[w][i];
	vis[w][i] = vs;
	ll res = calc(w, i + 1);
	if (c[i] >= cnt)
		res += calc(w + cnt * v[i], i + 1);
	return dp[w][i] = res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &sum, &n);
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &v[i], &c[i]);
			mx = max(mx, c[i]);
		}
		ll res = 0;
		for (int i = 1; i <= mx; ++i) {
			++vs;
			cnt = i;
			res += calc(0, 0);
		}
		printf("Case %d: %lld\n", k++, res);
	}
	return 0;
}
