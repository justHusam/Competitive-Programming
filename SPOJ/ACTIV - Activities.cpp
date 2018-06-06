#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5, M = 1e8;
int n, dp[N], nxt[N];
pair<int, int> v[N];

int calc(int at) {
	if (at == n)
		return 1;
	int &res = dp[at];
	if (res != -1)
		return res;
	return res = (calc(at + 1) + calc(nxt[at])) % M;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != -1) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &v[i].first, &v[i].second);
			dp[i] = -1;
		}
		sort(v, v + n);
		for (int i = 0; i < n; ++i)
			nxt[i] = lower_bound(v, v + n, make_pair(v[i].second, -1)) - v;
		int res = 0;
		for (int i = 0; i < n; ++i)
			res = (res + calc(nxt[i])) % M;
		printf("%08d\n", res);
	}
	return 0;
}
