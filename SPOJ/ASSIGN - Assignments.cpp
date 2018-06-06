#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
int n, g[N][N];
ll dp[1 << N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		dp[0] = 1;
		int sz = 1 << n;
		for (int mask = 1; mask < sz; ++mask) {
			dp[mask] = 0;
			int ones = bitset<N>(mask).count();
			for (int i = 0; i < n; ++i)
				if (g[ones - 1][i] == 1 && ((mask >> i) & 1) == 1)
					dp[mask] += dp[mask ^ (1 << i)];
		}
		printf("%lld\n", dp[sz - 1]);
	}
	return 0;
}
