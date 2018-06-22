#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e6 + 1;
int dp[N];

int main(int argc, char **argv) {
	int x, y;
	memset(dp, -1, sizeof dp);
	while (scanf("%d%d", &x, &y) > 0) {
		int mn = min(x, y), mx = max(x, y), fin = 0;
		for (int i = mn; i <= mx; ++i) {
			int temp = i, res = 1;
			if (dp[temp] != -1)
				temp = 1, res = dp[i];
			while (temp != 1) {
				if ((temp & 1) == 1)
					temp = temp * 3 + 1;
				else
					temp >>= 1;
				++res;
			}
			dp[i] = res;
			fin = max(fin, res);
		}
		printf("%d %d %d\n", x, y, fin);
	}
	return 0;
}
