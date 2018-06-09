/*
 * Name: LPPP - Lov-e Pap Pap-e Polti
 * Link: http://www.spoj.com/problems/LPPP/
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50;
int n, a[N];
bool dp[2][834][834];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("Case %d: ", cas++);
		if (sum % 3 != 0) {
			puts("Lov-e Pap Pap-e Polti");
			continue;
		}
		sum /= 3;
		int at = 0;
		memset(dp, false, sizeof dp);
		dp[1][0][0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= sum; ++j)
				for (int k = 0; k <= sum; ++k) {
					bool can = dp[at ^ 1][j][k];
					if (j - a[i] >= 0)
						can |= dp[at ^ 1][j - a[i]][k];
					if (k - a[i] >= 0)
						can |= dp[at ^ 1][j][k - a[i]];
					dp[at][j][k] = can;
				}
			at ^= 1;
		}
		if (dp[at ^ 1][sum][sum])
			puts("Happy Eid Day");
		else
			puts("Lov-e Pap Pap-e Polti");
	}
	return 0;
}
