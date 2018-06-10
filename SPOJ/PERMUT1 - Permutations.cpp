#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 12;
int n, k, dp[1 << N][100];

inline int get(int mask, int d) {
	int res = 0;
	for (int a = 0; a < n; ++a)
		if (((mask >> a) & 1) == 1 && a != d && a > d)
			++res;
	return res;
}

inline int calc(int mask, int cnt) {
	if (mask == (1 << n) - 1 && cnt == k)
		return 1;
	if (cnt > k)
		return 0;
	int &res = dp[mask][cnt];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 0; i < n; ++i)
		if (((mask >> i) & 1) == 0)
			res += calc(mask | (1 << i), cnt + get(mask, i));
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &k);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
