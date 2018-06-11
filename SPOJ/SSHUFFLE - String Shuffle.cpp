#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 62;
int n, m, k;
char a[N], b[N], c[N];
ll dp[N][N][N];

ll calc(int x, int y, int z) {
	if (z == k)
		return 1;
	ll &res = dp[x + 1][y + 1][z];
	if (res != -1)
		return res;
	res = 0;
	for (int i = x + 1; i < n; ++i)
		if (a[i] == c[z])
			res += calc(i, y, z + 1);
	for (int i = y + 1; i < m; ++i)
		if (b[i] == c[z])
			res += calc(x, i, z + 1);
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s%s%s", a, b, c);
		n = strlen(a);
		m = strlen(b);
		k = strlen(c);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", calc(-1, -1, 0));
	}
	return 0;
}
