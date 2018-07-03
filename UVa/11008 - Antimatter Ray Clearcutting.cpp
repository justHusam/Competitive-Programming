#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 16;
int n, m, T, k, x[N], y[N], dp[1 << N];
bitset<N> bs[N][N];

bool check(int i, int j, int k) {
	if (i == k || j == k)
		return 0;
	int x1 = x[j] - x[i];
	int y1 = y[j] - y[i];
	int x2 = x[k] - x[i];
	int y2 = y[k] - y[i];
	if (x1 * y2 - y1 * x2 == 0)
		return false;
	return true;
}

int calc(bitset<N> msk) {
	if (n - (int) msk.count() >= m)
		return 0;
	int &res = dp[msk.to_ulong()];
	if (res != -1)
		return res;
	res = 2e9;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			bitset<N> nmsk = msk;
			nmsk.operator &=(bs[i][j]);
			res = min(res, calc(nmsk) + 1);
		}
	return res;
}

int main(int argc, char **argv) {
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", x + i, y + i);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					bs[i][j].set();
					bs[i][j][i] = 0;
					continue;
				}
				for (int k = 0; k < n; ++k)
					bs[i][j][k] = check(i, j, k);
			}
		bitset<N> msk = (1 << n) - 1;
		memset(dp, -1, sizeof dp);
		printf("Case #%d:\n%d\n", ++k, calc(msk));
		if (T != 0)
			putchar('\n');
	}
	return 0;
}
